/*
 * File:   scriptSerializer.cpp
 * Author: Miles Lacey
 *
 * Created on March 13, 2015, 9:26 PM
 */

#include <cassert>
#include <fstream>
#include <type_traits>
#include <utility>

#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"
#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptSerializer.h"



namespace ls
{
namespace script
{
namespace
{

/*-------------------------------------
 * Perform an initial read to populate all script types.
-------------------------------------*/
ScriptLoadStatus _load_initializer_info(
    VariableMap_t& varList,
    FunctorMap_t& funcList,
    std::istream& fin,
    const ScriptBaseType baseType)
{
    std::underlying_type<ScriptBaseType>::type scriptBaseType; // int?
    hash_t scriptDataType = 0;
    void* pScript = nullptr;

    fin >> scriptBaseType >> scriptDataType >> pScript;
    if (!fin.good())
    {
        return ScriptLoadStatus::ERROR_BAD_STREAM;
    }

    auto expectedType = static_cast<std::underlying_type<decltype(baseType)>::type>(baseType);
    if (scriptBaseType != expectedType)
    {
        std::cerr << "Unknown script base type " << expectedType << std::endl;
        assert(false);
        return ScriptLoadStatus::ERROR_UNKNOWN_TYPE_INFO;
    }

    if (baseType == ScriptBaseType::VARIABLE)
    {
        Pointer_t<Variable>&& pVar = create_variable(scriptDataType);

        if (!pVar)
        {
            return ScriptLoadStatus::ERROR_RESERVING_VARIABLE;
        }

        varList.emplace((Variable*)pScript, std::move(pVar));
    }
    else if (baseType == ScriptBaseType::FUNCTOR)
    {
        Pointer_t<Functor>&& pFunc = create_functor(scriptDataType);

        if (!pFunc)
        {
            return ScriptLoadStatus::ERROR_RESERVING_FUNCTION;
        }

        funcList.emplace((Functor*)pScript, std::move(pFunc));
    }

    return ScriptLoadStatus::SUCCESS;
}



/*-------------------------------------
 * Load a specific type of script
-------------------------------------*/
ScriptLoadStatus _load_single_element(
    VariableMap_t& varList,
    FunctorMap_t& funcList,
    std::istream& istr,
    const ScriptBaseType baseType)
{
    void* inAddr = nullptr;
    istr >> inAddr; // import the scriptable's address

    if (istr.get() == std::char_traits<char>::eof() || !istr.good())
    {
        return ScriptLoadStatus::ERROR_BAD_STREAM;
    }

    if (baseType == ScriptBaseType::VARIABLE)
    {
        Pointer_t<Variable>& pScript = varList.at((Variable*)inAddr);
        if (!pScript)
        {
            std::cerr << "Failed to allocate variable " << (const void*)inAddr << std::endl;
            return ScriptLoadStatus::ERROR_ALLOCATING_VARIABLE;
        }

        if (!pScript->load(istr, varList, funcList))
        {
            std::cerr << "Failed to read variable " << (const void*)inAddr << std::endl;
            return ScriptLoadStatus::ERROR_READING_VARIABLE_DATA;
        }
    }
    else if (baseType == ScriptBaseType::FUNCTOR)
    {
        Pointer_t<Functor> &pScript = funcList.at((Functor*)inAddr);
        if (!pScript)
        {
            std::cerr << "Failed to allocate function " << (const void*)inAddr << std::endl;
            return ScriptLoadStatus::ERROR_ALLOCATING_FUNCTION;
        }

        if (!pScript->load(istr, varList, funcList))
        {
            std::cerr << "Failed to read function " << (const void*)inAddr << std::endl;
            return ScriptLoadStatus::ERROR_READING_FUNCTION_DATA;
        }
    }

    return ScriptLoadStatus::SUCCESS;
}



/*-------------------------------------
 * Write an initial set of data for a script type
-------------------------------------*/
template <typename data_t>
ScriptSaveStatus _save_initializer_info(std::ostream& ostr, const Pointer_t<data_t>& pScript)
{
    if (!ostr.good())
    {
        return ScriptSaveStatus::ERROR_BAD_STREAM;
    }

    if (!pScript)
    {
        return pScript->base_type() == ScriptBaseType::VARIABLE
            ? ScriptSaveStatus::ERROR_NULL_VARIABLE
            : ScriptSaveStatus::ERROR_NULL_FUNCTION;
    }

    const ScriptBaseType baseType = pScript->base_type();
    const hash_t hashType = pScript->sub_type();

    ostr
        << '\n' << static_cast<typename std::underlying_type<decltype(baseType)>::type>(baseType)
        << ' ' << hashType
        << ' ' << (const void*)pScript.get();

    return ScriptSaveStatus::SUCCESS;
}



} // end anonymous namespace



/*-------------------------------------
 * Load a list of variables.
-------------------------------------*/
LS_SCRIPT_API ScriptLoadInfo LS_SCRIPT_CALL load_script_file(const std::string& filename, VariableMap_t& varList, FunctorMap_t& funcList)
{
    varList.clear();
    funcList.clear();

    ScriptLoadInfo info = {ScriptLoadStatus::SUCCESS, filename};

    unsigned numVars = 0;
    unsigned numFuncs = 0;
    std::ifstream fin{filename, std::ios_base::in | std::ios_base::binary};

    if (!fin.good())
    {
        std::cerr << "Unable to open a script file for reading: " << filename << '.' << std::endl;
        info.status = ScriptLoadStatus::ERROR_OPENING_FILE;
        return info;
    }

    fin >> numVars >> numFuncs;
    varList.reserve(numVars);
    funcList.reserve(numVars);

    for (unsigned v = 0; v < numVars; ++v)
    {
        ScriptLoadStatus result = _load_initializer_info(varList, funcList, fin, ScriptBaseType::VARIABLE);
        if (result != ScriptLoadStatus::SUCCESS)
        {
            fin.close();
            std::cerr << "Failed to initialize a variable object from " << filename << '.' << std::endl;
            info.status = result;
            return info;
        }
    }

    for (unsigned f = 0; f < numFuncs; ++f)
    {
        ScriptLoadStatus result = _load_initializer_info(varList, funcList, fin, ScriptBaseType::FUNCTOR);
        if (result != ScriptLoadStatus::SUCCESS)
        {
            fin.close();
            std::cerr << "Failed to initialize a functor object from " << filename << '.' << std::endl;
            info.status = result;
            return info;
        }
    }

    // all variables and functors have been initialized, now load their data.
    while (numVars--)
    {
        ScriptLoadStatus result = _load_single_element(varList, funcList, fin, ScriptBaseType::VARIABLE);
        if (result != ScriptLoadStatus::SUCCESS)
        {
            fin.close();
            std::cerr << "Failed to read a variable object from " << filename << '.' << std::endl;
            info.status = result;
            return info;
        }
    }

    while (numFuncs--)
    {
        ScriptLoadStatus result = _load_single_element(varList, funcList, fin, ScriptBaseType::FUNCTOR);
        if (result != ScriptLoadStatus::SUCCESS)
        {
            fin.close();
            std::cerr << "Failed to read a functor object from " << filename << '.' << std::endl;
            info.status = result;
            return info;
        }
    }

    fin.close();

    return info;
}



/*-------------------------------------
 * Save a list of variables and functors.
-------------------------------------*/
LS_SCRIPT_API ScriptSaveInfo LS_SCRIPT_CALL save_script_file(
    const std::string& filename,
    const VariableMap_t& inVarList,
    const FunctorMap_t& inFuncList
)
{
    ScriptSaveInfo info = {ScriptSaveStatus::SUCCESS, filename};
    std::ofstream fout{filename, std::ios_base::binary | std::ios_base::out};

    if (!fout.good())
    {
        std::cerr << "Unable to open a script file for saving: " << filename << '.' << std::endl;
        info.status = ScriptSaveStatus::ERROR_CREATING_STREAM;
        return info;
    }

    // output the number of all variables and functors.
    fout << inVarList.size() << ' ' << inFuncList.size();

    // write function to save all "scriptable" addresses
    for (const VariableMap_t::value_type& scriptIter : inVarList)
    {
        ScriptSaveStatus status = _save_initializer_info<Variable>(fout, scriptIter.second);
        if (status != ScriptSaveStatus::SUCCESS)
        {
            fout.close();
            std::cerr
                << "Failed to save variable initialization data of "
                << (const void*)scriptIter.second.get()
                << " to : " << filename << '.'
                << std::endl;
            info.status = status;
            return info;
        }
    };

    for (const FunctorMap_t::value_type& scriptIter : inFuncList)
    {
        ScriptSaveStatus status = _save_initializer_info<Functor>(fout, scriptIter.second);
        if (status != ScriptSaveStatus::SUCCESS)
        {
            fout.close();
            std::cerr
            << "Failed to save functor initialization data of "
            << (const void*)scriptIter.second.get()
            << " to : " << filename << '.'
            << std::endl;
            info.status = status;
            return info;
        }
    };

    if (!fout.good())
    {
        std::cerr << "A stream error occurred while saving the script file: " << filename << '.' << std::endl;
        fout.close();
        info.status = ScriptSaveStatus::ERROR_BAD_STREAM;
        return info;
    }

    // all initial data has been saved, now serialize all scripts
    for (const VariableMap_t::value_type& pScript : inVarList)
    {
        const Pointer_t <Variable>& pVar = pScript.second;
        fout << '\n' << (const void*)pVar.get() << ' ';
        if (!pVar->save(fout))
        {
            std::cerr
                << "Unable to save script variable " << (const void*)pVar.get()
                << " to " << filename
                << std::endl;
            info.status = ScriptSaveStatus::ERROR_SAVING_VARIABLE;
            return info;
        }
    }

    for (const FunctorMap_t::value_type& pScript : inFuncList)
    {
        const Pointer_t <Functor>& pFunc = pScript.second;
        fout << '\n' << (const void*)pFunc.get() << ' ';
        if (!pFunc->save(fout))
        {
            std::cerr
                << "Unable to save script function " << (const void*)pFunc.get()
                << " to " << filename
                << std::endl;
            info.status = ScriptSaveStatus::ERROR_SAVING_FUNCTION;
            return info;
        }
    }

    if (!fout.good())
    {
        info.status = ScriptSaveStatus::ERROR_BAD_STREAM;
    }

    fout.close();
    return info;
}



} // end script namespace
} // end ls namespace
