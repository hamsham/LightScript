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



namespace ls
{
namespace script
{

/*-----------------------------------------------------------------------------
    Basic Built-In types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * char, ScriptVar_char
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(byte, uint8_t);

/*-------------------------------------
 * short, ScriptVar_short
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(short, int16_t);

/*-------------------------------------
 * ushort, ScriptVar_ushort
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(ushort, uint16_t);

/*-------------------------------------
 * int, ScriptVar_int
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(int, int32_t);

/*-------------------------------------
 * uint, ScriptVar_uint
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(uint, uint32_t);

/*-------------------------------------
 * long, ScriptVar_long
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(long, int64_t);

/*-------------------------------------
 * ulong, ScriptVar_ulong
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(ulong, uint64_t);

/*-------------------------------------
 * float, ScriptVar_float
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(float, float);

/*-------------------------------------
 * double, scriptvar_double
-------------------------------------*/
LS_SCRIPT_DECLARE_VAR(double, double);

/*-------------------------------------
 * std::string, ScriptVar_string
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_LOAD(std::string);

LS_SCRIPT_OVERRIDE_VAR_SAVE(std::string);

LS_SCRIPT_DECLARE_VAR(string, std::string); // ScriptVar_string



} // end script namepace
} // end ls namespace

#endif  /* __LS_SCRIPT_BASIC_VARIABLE_H__ */
