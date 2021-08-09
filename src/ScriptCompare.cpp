/*
 * File:   ScriptCompare.cpp
 * Author: hammy
 *
 * Created on August 8, 2021, 5:23 PM
 */

#include "lightsky/script/ScriptCompare.h"



/*-----------------------------------------------------------------------------
 * Boolean Comparison Definitions
-----------------------------------------------------------------------------*/
// Is Equal
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareEqBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, bool) == LS_SCRIPT_PARAM(2, bool);
}

// Not Equal
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareNeBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, bool) != LS_SCRIPT_PARAM(2, bool);
}

// Logical And
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareAndBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, bool) && LS_SCRIPT_PARAM(2, bool);
}

// Logical Or
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareOrBools, ScriptVar_bool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, bool) || LS_SCRIPT_PARAM(2, bool);
}

// Unary Not
LS_SCRIPT_DEFINE_FUNC_SHARED(LogicalNotBool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = !(LS_SCRIPT_PARAM(1, bool));
}



/*-----------------------------------------------------------------------------
 * Math-Type Comparison Definitions
-----------------------------------------------------------------------------*/
#define _LS_SCRIPT_DEFINE_CMP_FUNC(scriptNameUpper, scriptNameLower, type) \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareEq##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) == LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareNe##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) != LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareLt##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) < LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareLe##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) <= LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareGt##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) > LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareGe##scriptNameUpper##s, ScriptVar_bool, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, type) >= LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(LogicalNot##scriptNameUpper, ScriptVar_bool, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, bool) = !(LS_SCRIPT_PARAM(1, type)); \
}



_LS_SCRIPT_DEFINE_CMP_FUNC(Byte,   byte,   uint8_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Short,  short,  int16_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Ushort, ushort, uint16_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Int,    int,    int32_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Uint,   uint,   uint32_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Long,   long,   int64_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Ulong,  ulong,  uint64_t)
_LS_SCRIPT_DEFINE_CMP_FUNC(Float,  float,  float)
_LS_SCRIPT_DEFINE_CMP_FUNC(Double, double, double)



/*-----------------------------------------------------------------------------
 * String Comparison Definitions
-----------------------------------------------------------------------------*/
// Is Equal
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareEqStrings, ScriptVar_bool, ScriptVar_string, ScriptVar_string)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, std::string) == LS_SCRIPT_PARAM(2, std::string);
}

// Not Equal
LS_SCRIPT_DEFINE_FUNC_SHARED(CompareNeStrings, ScriptVar_bool, ScriptVar_string, ScriptVar_string)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, std::string) != LS_SCRIPT_PARAM(2, std::string);
}



#undef _LS_SCRIPT_DEFINE_CMP_FUNC
