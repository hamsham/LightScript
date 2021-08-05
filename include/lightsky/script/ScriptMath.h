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
/*-----------------------------------------------------------------------------
 Integers
-----------------------------------------------------------------------------*/
/*
 * Addition
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(AddInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Subtraction
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(SubInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Multiplication
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(MulInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Division
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(DivInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

/*
 * Modulus
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(ModInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);



/*-----------------------------------------------------------------------------
 Floating-Point Numbers
-----------------------------------------------------------------------------*/
/*
 * Addition
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Subtraction
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Multiplication
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Division
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);

/*
 * Modulus
 */
LS_SCRIPT_DECLARE_FUNC_SHARED(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float);



#endif  /* __LS_SCRIPT_MATH_H__ */
