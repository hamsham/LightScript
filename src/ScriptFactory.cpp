/*
 * File:   factory.cpp
 * Author: Miles Lacey
 *
 * Created on June 26, 2013, 5:58 AM
 */

#include <utility> // std::make_pair<>(...)
#include <unordered_map>

#include "lightsky/utils/Log.h"
#include "lightsky/utils/Assertions.h"

#include "lightsky/script/Script.h"
#include "lightsky/script/ScriptFactory.h"

using ls::script::hash_t;
using ls::script::VarFactory_t;
using ls::script::FuncFactory_t;
using ls::script::Pointer_t;


/*
 * Anonymous namespace to hide global variables
 */
namespace {

/*-----------------------------------------------------------------------------
 * Variable and Function factories
 *
 * These maps are populated at the program's initialization (before main()).
 *
 * They hold pointers to functions which only return a new instance of
 * whichever type is requested
 *
 * They are retrieved from functions as static variables in order to ensure a
 * proper order-of-creation. The ls::script::ScriptFactory MUST be instantiated
 * and initialized before any other script variable used in client code to
 * prevent crashing at startup.
 *
 * See the following for additional details on order-of-creation:
 *      http://stackoverflow.com/questions/25857340/access-violation-inserting-element-into-global-map?lq=1
 *
 *      http://stackoverflow.com/questions/13353519/access-violation-when-inserting-element-into-global-map
-----------------------------------------------------------------------------*/

/**
 * Global Variable Factory
 */
std::unordered_map<hash_t, VarFactory_t>& get_var_factory() {
    static std::unordered_map<hash_t, VarFactory_t> gVarFactoryList {};
    return gVarFactoryList;
}

/**
 * Global Functor Factory
 */
std::unordered_map<hash_t, FuncFactory_t>& get_func_factory() {
    static std::unordered_map<hash_t, FuncFactory_t> gFuncFactoryList {};
    return gFuncFactoryList;
}

} // anonymous namespace

namespace ls {

/*-----------------------------------------------------------------------------
 * Factory Method Registration
-----------------------------------------------------------------------------*/

/*-------------------------------------
 * Variable Factory Registration
-------------------------------------*/
const VarFactory_t& script::register_var_factory(hash_t factoryId, const VarFactory_t& pFactory) {
    if (get_var_factory().count(factoryId)) {
        return get_var_factory()[factoryId];
    }

    get_var_factory().insert(std::pair<hash_t, VarFactory_t> {factoryId, pFactory});
    return get_var_factory()[factoryId];
}

/*-------------------------------------
 * Functor Factory Registration
-------------------------------------*/
const FuncFactory_t& script::register_func_factory(hash_t factoryId, const FuncFactory_t& pFactory) {
    if (get_func_factory().count(factoryId)) {
        return get_func_factory()[factoryId];
    }

    get_func_factory().insert(std::pair<hash_t, FuncFactory_t> {factoryId, pFactory});
    return get_func_factory()[factoryId];
}

/*-----------------------------------------------------------------------------
 * Script Object Creation/Instantiation
 *
 * Get the corresponding function pointer from gVarFactory/gFuncFactory.
 * If the pointer isn't NULL, run the function in order to return a
 * new instance of the requested object
-----------------------------------------------------------------------------*/

/*-------------------------------------
 * Variable Creation
-------------------------------------*/
Pointer_t<script::Variable> script::create_variable(hash_t factoryId) {
    for (const std::pair<hash_t, VarFactory_t>& iter : get_var_factory()) {
        if (iter.first == factoryId) {
            return (*iter.second)();
        }
    }

    return Pointer_t<Variable> {nullptr};
}

/*-------------------------------------
 * Variable Deletion
-------------------------------------*/
void script::destroy_variable(Pointer_t<Variable>& pVariable) {
    pVariable.reset();
}

/*-------------------------------------
 * Functor Creation
-------------------------------------*/
Pointer_t<script::Functor> script::create_functor(hash_t factoryId) {
    for (const std::pair<hash_t, FuncFactory_t>& iter : get_func_factory()) {
        if (iter.first == factoryId) {
            return (*iter.second)();
        }
    }

    return Pointer_t<Functor> {nullptr};
}

/*-------------------------------------
 * Functor Deletion
-------------------------------------*/
void script::destroy_functor(Pointer_t<Functor>& pFunc) {
    pFunc.reset();
}

} // end ls namespace
