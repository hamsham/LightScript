/*
 * File:   scriptMath.cpp
 * Author: hammy
 *
 * Created on December 27, 2014, 1:53 AM
 */

#include <cmath>

#include "lightsky/script/ScriptMath.h"



/*-----------------------------------------------------------------------------
 * Built-In Math Types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * Integral Types
-------------------------------------*/
// ...Because I'm lazy
#define _LS_SCRIPT_DEFINE_MATH_FUNC(scriptNameUpper, scriptNameLower, type) \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(Add##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) + LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(Sub##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) - LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(Mul##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) * LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(Div##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) / LS_SCRIPT_PARAM(2, type); \
} \
 \
LS_SCRIPT_DEFINE_FUNC_SHARED(Mod##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) % LS_SCRIPT_PARAM(2, type); \
}



_LS_SCRIPT_DEFINE_MATH_FUNC(Bytes,   byte,   uint8_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Shorts,  short,  int16_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Ushorts, ushort, uint16_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Ints,    int,    int32_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Uints,   uint,   uint32_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Longs,   long,   int64_t)
_LS_SCRIPT_DEFINE_MATH_FUNC(Ulongs,  ulong,  uint64_t)



#undef _LS_SCRIPT_DEFINE_MATH_FUNC



/*-------------------------------------
 * Floats
-------------------------------------*/
// Addition
LS_SCRIPT_DEFINE_FUNC_SHARED(AddFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) + LS_SCRIPT_PARAM(2, float);
}

// Subtraction
LS_SCRIPT_DEFINE_FUNC_SHARED(SubFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) - LS_SCRIPT_PARAM(2, float);
}

// Multiplication
LS_SCRIPT_DEFINE_FUNC_SHARED(MulFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) * LS_SCRIPT_PARAM(2, float);
}

// Division
LS_SCRIPT_DEFINE_FUNC_SHARED(DivFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float) / LS_SCRIPT_PARAM(2, float);
}

// Modulus
LS_SCRIPT_DEFINE_FUNC_SHARED(ModFloats, ScriptVar_float, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = std::fmod(LS_SCRIPT_PARAM(1, float), LS_SCRIPT_PARAM(2, float));
}



/*-------------------------------------
 * Doubles
-------------------------------------*/
// Addition
LS_SCRIPT_DEFINE_FUNC_SHARED(AddDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = LS_SCRIPT_PARAM(1, double) + LS_SCRIPT_PARAM(2, double);
}

// Subtraction
LS_SCRIPT_DEFINE_FUNC_SHARED(SubDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = LS_SCRIPT_PARAM(1, double) - LS_SCRIPT_PARAM(2, double);
}

// Multiplication
LS_SCRIPT_DEFINE_FUNC_SHARED(MulDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = LS_SCRIPT_PARAM(1, double) * LS_SCRIPT_PARAM(2, double);
}

// Division
LS_SCRIPT_DEFINE_FUNC_SHARED(DivDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = LS_SCRIPT_PARAM(1, double) / LS_SCRIPT_PARAM(2, double);
}

// Modulus
LS_SCRIPT_DEFINE_FUNC_SHARED(ModDoubles, ScriptVar_double, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = std::fmod(LS_SCRIPT_PARAM(1, double), LS_SCRIPT_PARAM(2, double));
}
