/*
 * File:   newsimpletest.cpp
 * Author: hammy
 *
 * Created on Mar 22, 2015, 8:03:41 PM
 */

#include <iostream>

#include "lightsky/script/Script.h"



/*-----------------------------------------------------------------------------
 * Test Script File
-----------------------------------------------------------------------------*/
static constexpr char TEST_FILE[] = u8R"***(test_file.lss)***";



/*-----------------------------------------------------------------------------
 * Namespacing setup
-----------------------------------------------------------------------------*/
template <class data_t> using lsPointer = ls::script::Pointer_t<data_t>;

using lsVariable = ls::script::Variable;
using ls::script::create_variable;
using ls::script::destroy_variable;

using lsFunctor = ls::script::Functor;
using ls::script::create_functor;
using ls::script::destroy_functor;

using ls::script::ScriptRunner;
using ls::script::VariableMap_t;
using ls::script::FunctorMap_t;



/*-----------------------------------------------------------------------------
 * Function Entry Point
-----------------------------------------------------------------------------*/
namespace ls
{
namespace script
{
// dummy value to get the entry points
LS_SCRIPT_DECLARE_FUNC(Entry, void);

LS_SCRIPT_DEFINE_FUNC(Entry, void)
{
    (void)pArgs;
};



} // end script namespace
} // end ls namespace



/*-----------------------------------------------------------------------------
 * Verify that the functors compile.
-----------------------------------------------------------------------------*/
void validate_scripts(FunctorMap_t& funcMap)
{
    for (std::pair<lsFunctor * const, lsPointer <lsFunctor>>&funcIter : funcMap)
    {
        bool result = funcIter.second->compile();
        assert(result == true);
        if (!result)
        {
            std::cerr << "Failed to compile script!" << std::endl;
        }
    }
}



/*-----------------------------------------------------------------------------
 * Generate the test maps
-----------------------------------------------------------------------------*/
void generate_scripts(VariableMap_t& varMap, FunctorMap_t& funcMap)
{
    lsPointer<lsFunctor> testFunc1 = create_functor(ls::script::ScriptHash_AddInts);
    lsPointer<lsFunctor> testFunc2 = create_functor(ls::script::ScriptHash_SubInts);
    lsPointer<lsFunctor> testFunc3 = create_functor(ls::script::ScriptHash_MulInts);
    lsPointer<lsFunctor> testFunc4 = create_functor(ls::script::ScriptHash_DivInts);
    lsPointer<lsFunctor> testEntry1 = create_functor(ls::script::ScriptHash_Entry);

    lsPointer<lsVariable> testVar1 = create_variable(ls::script::ScriptHash_int);
    lsPointer<lsVariable> testVar2 = create_variable(ls::script::ScriptHash_int);
    lsPointer<lsVariable> testVar3 = create_variable(ls::script::ScriptHash_int);
    lsPointer<lsVariable> testVar4 = create_variable(ls::script::ScriptHash_string);

    LS_SCRIPT_VAR_DATA(testVar1, int) = 1;
    LS_SCRIPT_VAR_DATA(testVar2, int) = 2;
    LS_SCRIPT_VAR_DATA(testVar3, int) = 0; // dummy value
    LS_SCRIPT_VAR_DATA(testVar4, string) = "Hello World!";

    testEntry1->next_func_ptr(testFunc1.get());

    testFunc1->arg(0, testVar1.get()); // param 1 = 1
    testFunc1->arg(1, testVar2.get()); // param 2 = 2
    testFunc1->arg(2, testVar3.get()); // return value should equal 1+2=3
    testFunc1->next_func_ptr(testFunc2.get());

    testFunc2->arg(0, testVar1.get());
    testFunc2->arg(1, testVar2.get());
    testFunc2->arg(2, testVar2.get()); // should equal 1-2=-3
    testFunc2->next_func_ptr(testFunc3.get());

    testFunc3->arg(0, testVar1.get());
    testFunc3->arg(1, testVar2.get());
    testFunc3->arg(2, testVar2.get()); // should equal 1*2=2
    testFunc3->next_func_ptr(testFunc4.get());

    testFunc4->arg(0, testVar1.get());
    testFunc4->arg(1, testVar2.get());
    testFunc4->arg(2, testVar2.get()); // should equal 1/2=1 (int division)
    testFunc4->next_func_ptr(nullptr);

    validate_scripts(funcMap);

    varMap[testVar1.get()] = std::move(testVar1);
    varMap[testVar2.get()] = std::move(testVar2);
    varMap[testVar3.get()] = std::move(testVar3);
    varMap[testVar4.get()] = std::move(testVar4);

    funcMap[testFunc1.get()] = std::move(testFunc1);
    funcMap[testFunc2.get()] = std::move(testFunc2);
    funcMap[testFunc3.get()] = std::move(testFunc3);
    funcMap[testFunc4.get()] = std::move(testFunc4);
    funcMap[testEntry1.get()] = std::move(testEntry1);
}



/*-----------------------------------------------------------------------------
 * Save the script maps
-----------------------------------------------------------------------------*/
void save_scripts(const VariableMap_t& varImporter, const FunctorMap_t& funcImporter)
{
    if (!ls::script::save_script_file(TEST_FILE, varImporter, funcImporter))
    {
        std::cerr << "Failed to save variable & functor scripts!" << std::endl;
        assert(false);
    }
}



/*-----------------------------------------------------------------------------
 * Save the script maps
-----------------------------------------------------------------------------*/
void load_scripts(VariableMap_t& varImporter, FunctorMap_t& funcImporter)
{
    if(!ls::script::load_script_file(TEST_FILE, varImporter, funcImporter))
    {
        std::cerr << "Failed to load variable & functor scripts!" << std::endl;
        assert(false);
    }

    ls::script::remap_script_keys(varImporter, funcImporter);
}



/*-----------------------------------------------------------------------------
 * Run the scripts
-----------------------------------------------------------------------------*/
bool run_scripts(VariableMap_t& varMap, FunctorMap_t& funcMap)
{
    ScriptRunner runner {};

    ls::script::Functor* pEntryFunc = nullptr;

    for (std::pair<lsFunctor * const, lsPointer <lsFunctor>>&funcIter : funcMap)
    {
        lsPointer<lsFunctor>& func = funcIter.second;

        if (func->sub_type() == ls::script::ScriptHash_Entry)
        {
            pEntryFunc = func.get();
            break;
        }
    }

    assert(pEntryFunc != nullptr);

    runner.run(pEntryFunc);

    std::cout << "Successfully ran the script tests." << std::endl;
    std::cout << "The final variable values are:" << std::endl;

    for (std::pair<lsVariable * const, lsPointer <lsVariable>>&varIter : varMap)
    {
        lsPointer<lsVariable>& pVar = varIter.second;

        if (pVar->sub_type() == ls::script::ScriptHash_int)
        {
            std::cout << '\t' << LS_SCRIPT_VAR_DATA(pVar, int) << std::endl;
        }
        else if (pVar->sub_type() == ls::script::ScriptHash_string)
        {
            std::cout << '\t' << LS_SCRIPT_VAR_DATA(pVar, string) << std::endl;
        }
    }

    return true;
}



/*-----------------------------------------------------------------------------
 * Main()
-----------------------------------------------------------------------------*/
int main()
{
    VariableMap_t varMap {};
    FunctorMap_t funcMap {};

    generate_scripts(varMap, funcMap);
    validate_scripts(funcMap);
    run_scripts(varMap, funcMap);
    save_scripts(varMap, funcMap);

    varMap.clear();
    funcMap.clear();

    load_scripts(varMap, funcMap);
    validate_scripts(funcMap);
    run_scripts(varMap, funcMap);

    return 0;
}
