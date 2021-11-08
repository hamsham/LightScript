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



/*-----------------------------------------------------------------------------
 * Load Scripts
-----------------------------------------------------------------------------*/
/**
 * @brief Error codes for loading.
 */
enum class ScriptLoadStatus
{
    SUCCESS,
    ERROR_OPENING_FILE,
    ERROR_UNKNOWN_TYPE_INFO,
    ERROR_BAD_STREAM,
    ERROR_RESERVING_VARIABLE,
    ERROR_RESERVING_FUNCTION,
    ERROR_ALLOCATING_VARIABLE,
    ERROR_READING_VARIABLE_DATA,
    ERROR_ALLOCATING_FUNCTION,
    ERROR_READING_FUNCTION_DATA
};



/**
 * @brief Descriptive information when loading.
 */
struct ScriptLoadInfo
{
    ScriptLoadStatus status;
    std::string filename;
};



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
LS_SCRIPT_API ScriptLoadInfo LS_SCRIPT_CALL load_script_file(
    const std::string& filename,
    VariableMap_t& outVarMap,
    FunctorMap_t& outFuncMap
);



/*-----------------------------------------------------------------------------
 * Save Scripts
-----------------------------------------------------------------------------*/
enum class ScriptSaveStatus
{
    SUCCESS,
    ERROR_CREATING_STREAM,
    ERROR_BAD_STREAM,
    ERROR_NULL_VARIABLE,
    ERROR_NULL_FUNCTION,
    ERROR_SAVING_VARIABLE,
    ERROR_SAVING_FUNCTION
};



struct ScriptSaveInfo
{
    ScriptSaveStatus status;
    std::string fileName;
};



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
LS_SCRIPT_API ScriptSaveInfo LS_SCRIPT_CALL save_script_file(
    const std::string& filename,
    const VariableMap_t& inVarList,
    const FunctorMap_t& inFuncList
);



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_SERIALIZER_H__ */
