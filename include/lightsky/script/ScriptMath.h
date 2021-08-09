/*
 * File:   scriptMath.h
 * Author: hammy
 *
 * Created on December 27, 2014, 1:53 AM
 */

#ifndef __LS_SCRIPT_MATH_H__
#define __LS_SCRIPT_MATH_H__

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptBasicVar.h"
#include "lightsky/script/ScriptFunctor.h"



/*-----------------------------------------------------------------------------
 * Built-In Math Types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * Bytes
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);



/*-------------------------------------
 * Shorts
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);



/*-------------------------------------
 * Unsigned Shorts
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);



/*-------------------------------------
 * Integers
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);



/*-------------------------------------
 * Unsigned Ints
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);



/*-------------------------------------
 * Longs
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);



/*-------------------------------------
 * Unsigned Longs
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);



/*-------------------------------------
 * Floats
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);



/*-------------------------------------
 * Doubles
-------------------------------------*/
// Addition
LS_SCRIPT_DECLARE_FUNC_SHARED(AddDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double);

// Subtraction
LS_SCRIPT_DECLARE_FUNC_SHARED(SubDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double);

// Multiplication
LS_SCRIPT_DECLARE_FUNC_SHARED(MulDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double);

// Division
LS_SCRIPT_DECLARE_FUNC_SHARED(DivDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double);

// Modulus
LS_SCRIPT_DECLARE_FUNC_SHARED(ModDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double);



#endif  /* __LS_SCRIPT_MATH_H__ */
