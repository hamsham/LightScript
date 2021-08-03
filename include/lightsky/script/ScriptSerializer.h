/*
 * File:   scriptSerializer.h
 * Author: Miles Lacey
 *
 * Created on March 13, 2015, 9:26 PM
 */

#ifndef __LS_SCRIPT_SERIALIZER_H__
#define __LS_SCRIPT_SERIALIZER_H__

#include "lightsky/script/Setup.h"



namespace ls
{
namespace script
{

class Variable;
class Functor;



/**
 * @brief Load a file
 *
 * @param filename
 * A string object containing the relative path name to a file that
 * should be loadable into memory.
 *
 * @param outVarMap
 * A reference to an iteratable container object which will hold a set of
 * scriptable variable objects.
 *
 * @param outFuncMap
 * A reference to an iteratable container object which will hold a set of
 * scriptable functor objects.
 *
 * @return true if the file was successfully loaded. False if not.
 */
LS_API bool LS_CALL load_script_file(
    const std::string& filename,
    VariableMap_t& outVarMap,
    FunctorMap_t& outFuncMap
);



/**
 * @brief Remap the keys of a variable and functor map which had recently been
 * loaded.
 *
 * It is recommended to use this function after loading data from a file in
 * order to directly map all key values in the input maps to the pointers which
 * store their data.
 *
 * @param outVarMap
 * A reference to an iteratable container object which will hold a set of
 * scriptable variable objects.
 *
 * @param outFuncMap
 * A reference to an iteratable container object which will hold a set of
 * scriptable functor objects.
 */
LS_API void LS_CALL remap_script_keys(VariableMap_t& outVarMap, FunctorMap_t& outFuncMap);



/**
 * @brief Save a file
 *
 * Use this method to save data to a file, specific to the type of
 * resource used by derived classes.
 *
 * @param filename
 * A string object containing the relative path name to a file that
 * should be saved to the computer.
 *
 * @param inVarList
 * A constant reference to an iteratable container object which holds
 * a set of scriptable variable objects.
 *
 * @param inFuncList
 * A constant reference to an iteratable container object which holds
 * a set of scriptable functor objects.
 *
 * @return true if the file was successfully saved. False if not.
 */
LS_API bool LS_CALL save_script_file(
    const std::string& filename,
    const VariableMap_t& inVarList,
    const FunctorMap_t& inFuncList
);



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_SERIALIZER_H__ */
