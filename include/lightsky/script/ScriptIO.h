/*
 * File:   scriptIO.h
 * Author: Miles LAcey
 *
 * Created on March 24, 2015, 8:48 PM
 */

#ifndef __LS_SCRIPT_IO_H__
#define __LS_SCRIPT_IO_H__

#include <iostream>

#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"
#include "lightsky/script/ScriptBasicVar.h"

/*-----------------------------------------------------------------------------
 Data Input/Output
-----------------------------------------------------------------------------*/
namespace ls {
namespace script {

/*-------------------------------------
 * Standard Output
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(StdPrint, void*);

/*-----------------------------------------------------------------------------
 * Print functions for basic data types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DECLARE_FUNC(StdPrintChar, ScriptVar_StdPrint, ScriptVar_char);
LS_SCRIPT_DECLARE_FUNC(StdPrintShort, ScriptVar_StdPrint, ScriptVar_short);
LS_SCRIPT_DECLARE_FUNC(StdPrintInt, ScriptVar_StdPrint, ScriptVar_int);
LS_SCRIPT_DECLARE_FUNC(StdPrintUint, ScriptVar_StdPrint, ScriptVar_uint);
LS_SCRIPT_DECLARE_FUNC(StdPrintLong, ScriptVar_StdPrint, ScriptVar_long);
LS_SCRIPT_DECLARE_FUNC(StdPrintUlong, ScriptVar_StdPrint, ScriptVar_ulong);
LS_SCRIPT_DECLARE_FUNC(StdPrintFloat, ScriptVar_StdPrint, ScriptVar_float);
LS_SCRIPT_DECLARE_FUNC(StdPrintDouble, ScriptVar_StdPrint, ScriptVar_double);
LS_SCRIPT_DECLARE_FUNC(StdPrintString, ScriptVar_StdPrint, ScriptVar_string);

} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_IO_H__ */
