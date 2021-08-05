/*
 * File:   scriptMath.cpp
 * Author: hammy
 *
 * Created on December 27, 2014, 1:53 AM
 */

#include <cmath>

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptMath.h"



/*-----------------------------------------------------------------------------
    Built-In Math Types
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 Integers
-----------------------------------------------------------------------------*/
/*
 * Addition
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(AddInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) + LS_SCRIPT_PARAM(2, int);
}

/*
 * Subtraction
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(SubInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) - LS_SCRIPT_PARAM(2, int);
}

/*
 * Multiplication
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(MulInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) * LS_SCRIPT_PARAM(2, int);
}

/*
 * Division
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(DivInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) / LS_SCRIPT_PARAM(2, int);
}

/*
 * Modulus
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(ModInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) % LS_SCRIPT_PARAM(2, int);
}

/*-----------------------------------------------------------------------------
 Floats
-----------------------------------------------------------------------------*/

/*
 * Addition
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) + LS_SCRIPT_PARAM(2, float);
}

/*
 * Subtraction
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) - LS_SCRIPT_PARAM(2, float);
}

/*
 * Multiplication
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) * LS_SCRIPT_PARAM(2, float);
}

/*
 * Division
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) / LS_SCRIPT_PARAM(2, float);
}

/*
 * Modulus
 */
LS_SCRIPT_DEFINE_FUNC_SHARED(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = std::fmod(LS_SCRIPT_PARAM(1, float), LS_SCRIPT_PARAM(2, float));
}
