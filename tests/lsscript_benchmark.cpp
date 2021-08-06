/*
 * File:   benchTest.cpp
 * Author: hammy
 *
 * Created on Dec 12, 2014, 7:26:20 AM
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <utility> /* std::move */
#include "lightsky/script/Script.h"

template <class data_t> using lsPointer = ls::script::Pointer_t<data_t>;

using lsVariable = ls::script::Variable;
using ls::script::create_variable;
using ls::script::destroy_variable;

using lsFunctor = ls::script::Functor;
using ls::script::create_functor;
using ls::script::destroy_functor;



/******************************************************************************
 * Benchmark Setup
 ******************************************************************************/
#define NUM_TEST_RUNS 1000000000
namespace chrono = std::chrono;
typedef chrono::steady_clock::time_point hr_time;
typedef chrono::milliseconds hr_prec;

int add_nums(int x, int y)
{
    return x + y;
}

int sub_nums(int x, int y)
{
    return x - y;
}



/******************************************************************************
 * REFERENCE FUNCTION
 ******************************************************************************/
void native_bench()
{
    int testVar1 = 42;
    int testVar2 = 77;
    int testVar3 = 13;

    hr_time t1, t2;
    t1 = chrono::steady_clock::now();
    int (*pFunc[2])(int, int) = {&add_nums, &sub_nums};

    for (unsigned i = 0; i < NUM_TEST_RUNS; ++i)
    {
        testVar1 = (*pFunc[i % 2])(testVar2, testVar3);
    }

    (void)testVar1;

    t2 = chrono::steady_clock::now();
    std::cout.precision(std::numeric_limits<double>::digits10);
    std::cout
        << "Native Benchmark: "
        << chrono::duration_cast< hr_prec >(t2 - t1).count() / 1000.0
        << std::endl;

    return;
}



/******************************************************************************
 * SCRIPTED BENCHMARK
 ******************************************************************************/
void script_bench()
{
    lsPointer<lsFunctor>&& testFunc1 = create_functor(ScriptHash_AddInts);
    lsPointer<lsFunctor>&& testFunc2 = create_functor(ScriptHash_SubInts);

    lsPointer<lsVariable>&& testVar1 = create_variable(ScriptHash_int);
    lsPointer<lsVariable>&& testVar2 = create_variable(ScriptHash_int);
    lsPointer<lsVariable>&& testVar3 = create_variable(ScriptHash_int);

    LS_SCRIPT_VAR_DATA(testVar1, int) = 42;
    LS_SCRIPT_VAR_DATA(testVar2, int) = 77;
    LS_SCRIPT_VAR_DATA(testVar3, int) = 13;

    testFunc1->arg(0, testVar1.get());
    testFunc1->arg(1, testVar2.get());
    testFunc1->arg(2, testVar3.get());

    testFunc2->arg(2, testVar3.get());
    testFunc2->arg(0, testVar2.get());
    testFunc2->arg(1, testVar1.get());

    testFunc1->next_func_ptr(testFunc2.get());
    testFunc2->next_func_ptr(testFunc1.get());

    if (testFunc1->compile().status != ls::script::CompileStatus::SUCCESS
    || testFunc2->compile().status != ls::script::CompileStatus::SUCCESS)
    {
        std::cerr << "Error: Unable to compile the test functions." << std::endl;
        return;
    }

    hr_time t1, t2;
    t1 = chrono::steady_clock::now();
    lsFunctor* pFunc = testFunc1.get();

    for (unsigned i = 0; i < NUM_TEST_RUNS; ++i)
    {
        pFunc->run();
        pFunc = pFunc->next_func_ptr();
    }

    t2 = chrono::steady_clock::now();
    std::cout.precision(std::numeric_limits<double>::digits10);
    std::cout
        << "Script benchmark: "
        << chrono::duration_cast< hr_prec >(t2 - t1).count() / 1000.0
        << std::endl;

    destroy_functor(testFunc2);
    destroy_functor(testFunc1);

    destroy_variable(testVar3);
    destroy_variable(testVar2);
    destroy_variable(testVar1);

    return;
}



/*-----------------------------------------------------------------------------
 * Main()
-----------------------------------------------------------------------------*/
int main()
{
    for (unsigned i = 5; i-- > 0;) {
        std::thread t2 {&native_bench};
        std::thread t1 {&script_bench};

        t2.join();
        t1.join();
    }

    return 0;
}
