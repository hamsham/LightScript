/*
 * File:   scriptMath.h
 * Author: hammy
 *
 * Created on December 27, 2014, 1:53 AM
 */

#ifndef __LS_SCRIPT_MATH_H__
#define __LS_SCRIPT_MATH_H__

#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFunctor.h"
#include "lightsky/script/ScriptBasicVar.h"

/*-----------------------------------------------------------------------------
    Built-In Math Types
-----------------------------------------------------------------------------*/
namespace ls
{
namespace script
{



/*-----------------------------------------------------------------------------
 Integers
-----------------------------------------------------------------------------*/
/*
 * Addition
 */
LS_SCRIPT_DECLARE_FUNC(AddInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Subtraction
 */
LS_SCRIPT_DECLARE_FUNC(SubInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Multiplication
 */
LS_SCRIPT_DECLARE_FUNC(MulInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Division
 */
LS_SCRIPT_DECLARE_FUNC(DivInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Modulus
 */
LS_SCRIPT_DECLARE_FUNC(ModInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);



/*-----------------------------------------------------------------------------
 Floating-Point Numbers
-----------------------------------------------------------------------------*/
/*
 * Addition
 */
LS_SCRIPT_DECLARE_FUNC(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Subtraction
 */
LS_SCRIPT_DECLARE_FUNC(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Multiplication
 */
LS_SCRIPT_DECLARE_FUNC(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Division
 */
LS_SCRIPT_DECLARE_FUNC(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Modulus
 */
LS_SCRIPT_DECLARE_FUNC(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_MATH_H__ */
