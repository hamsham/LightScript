/*
 * File:   scriptBasicVar.h
 * Author: Miles Lacey
 *
 * Created on March 12, 2015, 12:52 AM
 */

#ifndef __LS_SCRIPT_BASIC_VARIABLE_H__
#define __LS_SCRIPT_BASIC_VARIABLE_H__

#include <cstdint>

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"



/*-----------------------------------------------------------------------------
    Basic Built-In types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * bool, ScriptVar_bool
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(bool, bool);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignBool, ScriptVar_bool, ScriptVar_bool);

/*-------------------------------------
 * char, ScriptVar_byte
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(byte, uint8_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignByte, ScriptVar_byte, ScriptVar_byte);

/*-------------------------------------
 * short, ScriptVar_short
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(short, int16_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignShort, ScriptVar_short, ScriptVar_short);

/*-------------------------------------
 * ushort, ScriptVar_ushort
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(ushort, uint16_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignUshort, ScriptVar_ushort, ScriptVar_ushort);

/*-------------------------------------
 * int, ScriptVar_int
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(int, int32_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignInt, ScriptVar_int, ScriptVar_int);

/*-------------------------------------
 * uint, ScriptVar_uint
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(uint, uint32_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignUint, ScriptVar_uint, ScriptVar_uint);

/*-------------------------------------
 * long, ScriptVar_long
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(long, int64_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignLong, ScriptVar_long, ScriptVar_long);

/*-------------------------------------
 * ulong, ScriptVar_ulong
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(ulong, uint64_t);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignUlong, ScriptVar_ulong, ScriptVar_ulong);

/*-------------------------------------
 * float, ScriptVar_float
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(float, float);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignFloat, ScriptVar_float, ScriptVar_float);

/*-------------------------------------
 * double, scriptvar_double
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(double, double);
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignDouble, ScriptVar_double, ScriptVar_double);

/*-------------------------------------
 * std::string, ScriptVar_string
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_LOAD(LS_SCRIPT_API, std::string);

LS_SCRIPT_OVERRIDE_VAR_SAVE(LS_SCRIPT_API, std::string);

LS_SCRIPT_DECLARE_VAR_SHARED(string, std::string); // ScriptVar_string
LS_SCRIPT_DECLARE_FUNC_SHARED(AssignString, ScriptVar_string, ScriptVar_string);



#endif  /* __LS_SCRIPT_BASIC_VARIABLE_H__ */
