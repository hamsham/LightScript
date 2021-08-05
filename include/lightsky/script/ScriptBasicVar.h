/*
 * File:   scriptBasicVar.h
 * Author: Miles Lacey
 *
 * Created on March 12, 2015, 12:52 AM
 */

#ifndef __LS_SCRIPT_BASIC_VARIABLE_H__
#define __LS_SCRIPT_BASIC_VARIABLE_H__

#include <cstdint>
#include "lightsky/script/ScriptVariable.h"



/*-----------------------------------------------------------------------------
    Basic Built-In types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * char, ScriptVar_byte
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(byte, uint8_t);

/*-------------------------------------
 * short, ScriptVar_short
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(short, int16_t);

/*-------------------------------------
 * ushort, ScriptVar_ushort
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(ushort, uint16_t);

/*-------------------------------------
 * int, ScriptVar_int
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(int, int32_t);

/*-------------------------------------
 * uint, ScriptVar_uint
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(uint, uint32_t);

/*-------------------------------------
 * long, ScriptVar_long
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(long, int64_t);

/*-------------------------------------
 * ulong, ScriptVar_ulong
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(ulong, uint64_t);

/*-------------------------------------
 * float, ScriptVar_float
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(float, float);

/*-------------------------------------
 * double, scriptvar_double
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR_SHARED(double, double);

/*-------------------------------------
 * std::string, ScriptVar_string
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_LOAD(LS_API, std::string);

LS_SCRIPT_OVERRIDE_VAR_SAVE(LS_API, std::string);

LS_SCRIPT_DECLARE_VAR_SHARED(string, std::string); // ScriptVar_string



#endif  /* __LS_SCRIPT_BASIC_VARIABLE_H__ */
