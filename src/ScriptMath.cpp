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
LS_SCRIPT_DEFINE_FUNC(AddInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) + LS_SCRIPT_PARAM(2, int);
};

/*
 * Subtraction
 */
LS_SCRIPT_DEFINE_FUNC(SubInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) - LS_SCRIPT_PARAM(2, int);
};

/*
 * Multiplication
 */
LS_SCRIPT_DEFINE_FUNC(MulInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) * LS_SCRIPT_PARAM(2, int);
};

/*
 * Division
 */
LS_SCRIPT_DEFINE_FUNC(DivInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) / LS_SCRIPT_PARAM(2, int);
};

/*
 * Modulus
 */
LS_SCRIPT_DEFINE_FUNC(ModInts, ScriptVar_int, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int) = LS_SCRIPT_PARAM(1, int) % LS_SCRIPT_PARAM(2, int);
};

/*-----------------------------------------------------------------------------
 Floats
-----------------------------------------------------------------------------*/

/*
 * Addition
 */
LS_SCRIPT_DEFINE_FUNC(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) + LS_SCRIPT_PARAM(2, float);
};

/*
 * Subtraction
 */
LS_SCRIPT_DEFINE_FUNC(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) - LS_SCRIPT_PARAM(2, float);
};

/*
 * Multiplication
 */
LS_SCRIPT_DEFINE_FUNC(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) * LS_SCRIPT_PARAM(2, float);
};

/*
 * Division
 */
LS_SCRIPT_DEFINE_FUNC(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) / LS_SCRIPT_PARAM(2, float);
};

/*
 * Modulus
 */
LS_SCRIPT_DEFINE_FUNC(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = std::fmod(LS_SCRIPT_PARAM(1, float), LS_SCRIPT_PARAM(2, float));
};



} // end script namespace
} // end ls namespace
