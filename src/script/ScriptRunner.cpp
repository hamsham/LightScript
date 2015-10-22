/* 
 * File:   scriptRunner.cpp
 * Author: hammy
 * 
 * Created on February 25, 2015, 9:42 PM
 */

#include <utility> // std::move()

#include "lightsky/setup/Macros.h"

#include "lightsky/script/ScriptFunctor.h"
#include "lightsky/script/ScriptRunner.h"

namespace ls {
namespace script {

/*-------------------------------------
 * Destructor
-------------------------------------*/
ScriptRunner::~ScriptRunner() {
}

/*-------------------------------------
 * Run Constructor
-------------------------------------*/
ScriptRunner::ScriptRunner(Functor* const pEntryFunction, const Functor* const pSentinel) {
    run(pEntryFunction, pSentinel);
}

/*-------------------------------------
 * Basic Constructor
-------------------------------------*/
ScriptRunner::ScriptRunner() {
}

/*-------------------------------------
 * Copy Constructor
-------------------------------------*/
ScriptRunner::ScriptRunner(const ScriptRunner&) {
}

/*-------------------------------------
 * Move Constructor
-------------------------------------*/
ScriptRunner::ScriptRunner(ScriptRunner&&) {
}

/*-------------------------------------
 * Copy Constructor
-------------------------------------*/
ScriptRunner& ScriptRunner::operator=(const ScriptRunner&) {
    return *this;
}

/*-------------------------------------
 * Move Constructor
-------------------------------------*/
ScriptRunner& ScriptRunner::operator=(ScriptRunner&&) {
    return *this;
}

/*-------------------------------------
 * Script Running
-------------------------------------*/
bool ScriptRunner::run(Functor* const pEntryFunction, const Functor* const pSentinel) {
    Functor* pFunc = pEntryFunction;
    
    while (pFunc != pSentinel) {
        pFunc->run();
        pFunc = pFunc->get_next_func();
    }
    
    return true;
}

} // end script namespace
} // end ls namespace
