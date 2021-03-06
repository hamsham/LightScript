/*
 * File:   scriptSerializer.cpp
 * Author: Miles Lacey
 *
 * Created on March 13, 2015, 9:26 PM
 */

#include <algorithm>
#include <fstream>
#include <type_traits>
#include <utility>

#include "lightsky/utils/Log.h"

#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"
#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptSerializer.h"

namespace ls {
namespace script {

/*-------------------------------------
 * Perform an initial read to populate all script types.
-------------------------------------*/
bool initialRead(
    VariableMap_t& varList,
    FunctorMap_t& funcList,
    std::istream& fin,
    const script_base_t baseType
) {
    std::underlying_type<script_base_t>::type scriptBaseType; // int?
    hash_t scriptDataType = 0;
    void* pScript = nullptr;

    fin >> scriptBaseType >> scriptDataType >> pScript;

    LS_ASSERT(scriptBaseType == LS_ENUM_VAL(baseType));

    if (baseType == script_base_t::VARIABLE) {
        Pointer_t<Variable>&& pVar = create_variable(scriptDataType);

        if (pVar) {
            varList.emplace((Variable*)pScript, std::move(pVar));
            return true;
        }
    }
    else if (baseType == script_base_t::FUNCTOR) {
        Pointer_t<Functor>&& pFunc = create_functor(scriptDataType);

        if (pFunc) {
            funcList.emplace((Functor*)pScript, std::move(pFunc));
            return true;
        }
    }

    LS_LOG_ERR(
        "Unable to instantiate a script of type ",
        scriptBaseType, '-', scriptDataType,
        " with requested type ",
        LS_ENUM_VAL(baseType), '-', scriptDataType,
        " during a load operation."
        );

    return false;
}

/*-------------------------------------
 * Load a specific type of script
-------------------------------------*/
bool dataRead(
    VariableMap_t& varList,
    FunctorMap_t& funcList,
    std::istream& istr,
    const script_base_t baseType
) {
    void* inAddr = nullptr;
    istr >> inAddr; // import the scriptable's address
    istr.get(); // discard extra whitespace inserted by the save() method

    if (baseType == script_base_t::VARIABLE) {
        Pointer_t<Variable>& pScript = varList.at((Variable*)inAddr);
        if (pScript && pScript->load(istr, varList, funcList)) {
            return true;
        }
    }
    else if (baseType == script_base_t::FUNCTOR) {
        Pointer_t<Functor>& pScript = funcList.at((Functor*)inAddr);
        if (pScript && pScript->load(istr, varList, funcList)) {
            return true;
        }
    }

    LS_LOG_ERR(
        "Unable to read a script of type ",
        LS_ENUM_VAL(baseType),
        " during a load operation."
        );

    return false;
}

/*-------------------------------------
 * Load a list of variables.
-------------------------------------*/
bool load_script_file(const std::string& filename, VariableMap_t& varList, FunctorMap_t& funcList) {
    varList.clear();
    funcList.clear();

    unsigned numVars = 0;
    unsigned numFuncs = 0;
    std::ifstream fin {filename, std::ios_base::in | std::ios_base::binary};

    if (!fin.good()) {
        LS_LOG_ERR("Unable to open a script file for reading: ", filename, '.');
        return false;
    }

    fin >> numVars >> numFuncs;

    for (unsigned v = 0; v < numVars; ++v) {
        if (!initialRead(varList, funcList, fin, script_base_t::VARIABLE)) {
            fin.close();
            LS_LOG_ERR("Failed to initialize a variable object from ", filename, '.');
            return false;
        }
    }

    for (unsigned f = 0; f < numFuncs; ++f) {
        if (!initialRead(varList, funcList, fin, script_base_t::FUNCTOR)) {
            fin.close();
            LS_LOG_ERR("Failed to initialize a functor object from ", filename, '.');
            return false;
        }
    }

    // all variables and functors have been initialized, now load their data.
    while (numVars-- > 0) {
        if (!dataRead(varList, funcList, fin, script_base_t::VARIABLE)) {
            fin.close();
            LS_LOG_ERR("Failed to read a variable object from ", filename, '.');
            return false;
        }
    }

    while (numFuncs-- > 0) {
        if (!dataRead(varList, funcList, fin, script_base_t::FUNCTOR)) {
            fin.close();
            LS_LOG_ERR("Failed to read a functor object from ", filename, '.');
            return false;
        }
    }

    fin.close();

    return true;
}

/*-------------------------------------
 * Ensure all mapped script keys actually point to valid data.
-------------------------------------*/
void remap_script_keys(VariableMap_t& inVarMap, FunctorMap_t& inFuncMap) {
    VariableMap_t tempVarMap {};
    for (VariableMap_t::value_type& inVar : inVarMap) {
        tempVarMap[inVar.second.get()] = std::move(inVar.second);
    }
    inVarMap = std::move(tempVarMap);

    FunctorMap_t tempFuncMap {};
    for (FunctorMap_t::value_type& inFunc : inFuncMap) {
        tempFuncMap[inFunc.second.get()] = std::move(inFunc.second);
    }
    inFuncMap = std::move(tempFuncMap);
}

/*-------------------------------------
 * Write an initial set of data for a script type
-------------------------------------*/
template <typename data_t>
bool initialWrite(std::ostream& ostr, const Pointer_t<data_t>& pScript) {
    if (!pScript) {
        return false;
    }

    const script_base_t baseType = pScript->get_script_type();
    const hash_t hashType = pScript->get_script_subtype();

    ostr
        << '\n' << static_cast<typename std::underlying_type < decltype(baseType)>::type>(baseType)
        << ' ' << hashType
        << ' ' << (const void*)pScript;

    return true;
}

/*-------------------------------------
 * Save a list of variables and functors.
-------------------------------------*/
bool save_script_file(
    const std::string& filename,
    const VariableMap_t& inVarList,
    const FunctorMap_t& inFuncList
) {
    std::ofstream fout {filename, std::ios_base::binary | std::ios_base::out};

    if (!fout.good()) {
        LS_LOG_ERR("Unable to open a script file for saving: ", filename, '.');
        return false;
    }

    // output the number of all variables and functors.
    fout << inVarList.size() << ' ' << inFuncList.size();

    // write function to save all "scriptable" addresses
    for (const VariableMap_t::value_type& scriptIter : inVarList) {
        if (!initialWrite<Variable>(fout, scriptIter.second)) {
            fout.close();
            LS_LOG_ERR("Failed to save variable initialization data to : ", filename, '.');
            return false;
        }
    };

    for (const FunctorMap_t::value_type& scriptIter : inFuncList) {
        if (!initialWrite<Functor>(fout, scriptIter.second)) {
            fout.close();
            LS_LOG_ERR("Failed to save functor initialization data to : ", filename, '.');
            return false;
        }
    };

    if (!fout.good()) {
        LS_LOG_ERR("A stream error occurred while saving the script file: ", filename, '.');
        fout.close();
        return false;
    }

    // all initial data has been saved, now serialize all scripts
    for (const VariableMap_t::value_type& pScript : inVarList) {
        const Pointer_t<Variable>& pVar = pScript.second;
        fout << '\n' << (const void*)pVar << ' ';
        pVar->save(fout);
    }

    for (const FunctorMap_t::value_type& pScript : inFuncList) {
        const Pointer_t<Functor>& pFunc = pScript.second;
        fout << '\n' << (const void*)pFunc << ' ';
        pFunc->save(fout);
    }

    const bool ret = fout.good();
    fout.close();
    return ret;
}

} // end script namespace
} // end ls namespace
