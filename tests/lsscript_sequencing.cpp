/*
 * File:   sequence_test.cpp
 * Author: hammy
 *
 * Created on Feb 26, 2015, 12:38:57 AM
 */

#include <cassert>
#include <iostream>
#include "lightsky/script/Script.h"

template <class data_t> using lsPointer = ls::script::Pointer_t<data_t>;

using lsVariable = ls::script::Variable;
using ls::script::create_variable;
using ls::script::destroy_variable;

using lsFunctor = ls::script::Functor;
using ls::script::create_functor;
using ls::script::destroy_functor;

using ls::script::ScriptRunner;



int main()
{
    lsPointer<lsFunctor> testFunc1 = create_functor(ls::script::ScriptHash_AddInts);
    lsPointer<lsFunctor> testFunc2 = create_functor(ls::script::ScriptHash_SubInts);
    lsPointer<lsFunctor> testFunc3 = create_functor(ls::script::ScriptHash_MulInts);
    lsPointer<lsFunctor> testFunc4 = create_functor(ls::script::ScriptHash_DivInts);

    lsPointer<lsVariable> testVar1 = create_variable(ls::script::ScriptHash_int);
    lsPointer<lsVariable> testVar2 = create_variable(ls::script::ScriptHash_int);
    lsPointer<lsVariable> testVar3 = create_variable(ls::script::ScriptHash_int);

    lsPointer<lsVariable> testVar5 = create_variable(ls::script::ScriptHash_string);
    if (!testVar5)
    {
        std::cout << "Unable to create a string variable." << std::endl;
    }

    LS_SCRIPT_VAR_DATA(testVar1, int) = 1;
    LS_SCRIPT_VAR_DATA(testVar2, int) = 2;
    LS_SCRIPT_VAR_DATA(testVar3, int) = 0; // dummy value

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

    ScriptRunner runner {};
    runner.run(testFunc1.get());

    assert(LS_SCRIPT_VAR_DATA(testVar3, int) == 1 / 2);

    std::cout << "Successfully ran the script tests." << std::endl;
    std::cout << "The final variable values are:" << std::endl;
    std::cout << "\tVariable 1: " << LS_SCRIPT_VAR_DATA(testVar1, int) << std::endl;
    std::cout << "\tVariable 2: " << LS_SCRIPT_VAR_DATA(testVar2, int) << std::endl;
    std::cout << "\tVariable 3: " << LS_SCRIPT_VAR_DATA(testVar3, int) << std::endl;

    return 0;
}
