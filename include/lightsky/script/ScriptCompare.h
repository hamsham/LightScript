/*
 * File:   ScriptCompare.h
 * Author: hammy
 *
 * Created on August 8, 2021, 5:23 PM
 */

#ifndef __LS_SCRIPT_BITUTIL_H__
#define __LS_SCRIPT_BITUTIL_H__

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptBasicVar.h"
#include "lightsky/script/ScriptFunctor.h"



/*-----------------------------------------------------------------------------
 * Comparison Declarations
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * Booleans
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool);

// Logical And
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareAndBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool);

// Logical Or
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareOrBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotBool, ScriptVar_bool, ScriptVar_bool);



/*-------------------------------------
 * Bytes
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeBytes, ScriptVar_bool, ScriptVar_byte, ScriptVar_byte);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotByte, ScriptVar_bool, ScriptVar_byte);



/*-------------------------------------
 * Shorts
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeShorts, ScriptVar_bool, ScriptVar_short, ScriptVar_short);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotShort, ScriptVar_bool, ScriptVar_short);



/*-------------------------------------
 * UShorts
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeUshorts, ScriptVar_bool, ScriptVar_ushort, ScriptVar_ushort);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotUshort, ScriptVar_bool, ScriptVar_ushort);



/*-------------------------------------
 * Ints
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeInts, ScriptVar_bool, ScriptVar_int, ScriptVar_int);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotInt, ScriptVar_bool, ScriptVar_int);



/*-------------------------------------
 * Uints
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeUints, ScriptVar_bool, ScriptVar_uint, ScriptVar_uint);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotUint, ScriptVar_bool, ScriptVar_uint);



/*-------------------------------------
 * Longs
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeLongs, ScriptVar_bool, ScriptVar_long, ScriptVar_long);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotLong, ScriptVar_bool, ScriptVar_long);



/*-------------------------------------
 * Ulongs
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeUlongs, ScriptVar_bool, ScriptVar_ulong, ScriptVar_ulong);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotUlong, ScriptVar_bool, ScriptVar_ulong);



/*-------------------------------------
 * Floats
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeFloats, ScriptVar_bool, ScriptVar_float, ScriptVar_float);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotFloat, ScriptVar_bool, ScriptVar_float);



/*-------------------------------------
 * Doubles
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Less Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLtDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Less Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareLeDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Greater Than
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGtDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Greater Than or Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareGeDoubles, ScriptVar_bool, ScriptVar_double, ScriptVar_double);

// Unary Not
LS_SCRIPT_DECLARE_FUNC_SHARED(LogicalNotDouble, ScriptVar_bool, ScriptVar_double);



/*-------------------------------------
 * Strings
-------------------------------------*/
// Is Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareEqStrings, ScriptVar_bool, ScriptVar_string, ScriptVar_string);

// Not Equal
LS_SCRIPT_DECLARE_FUNC_SHARED(CompareNeStrings, ScriptVar_bool, ScriptVar_string, ScriptVar_string);



#endif /* __LS_SCRIPT_BITUTIL_H__ */
