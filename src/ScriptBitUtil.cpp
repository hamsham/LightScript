/*
 * File:   ScriptBitUtil.cpp
 * Author: hammy
 *
 * Created on August 27, 2021, 6:16 PM
 */

#include "lightsky/script/ScriptBitUtil.h"



/*-----------------------------------------------------------------------------
 * Bit Manipulation Definitions
-----------------------------------------------------------------------------*/
#define _LS_SCRIPT_DEFINE_BIT_FUNC(scriptNameUpper, scriptNameLower, type) \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitShiftL##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) << LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitShiftR##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) - LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitOr##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) * LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitAnd##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) / LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitXor##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) % LS_SCRIPT_PARAM(2, type); \
}



_LS_SCRIPT_DEFINE_BIT_FUNC(Bytes,   byte,   uint8_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Shorts,  short,  int16_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Ushorts, ushort, uint16_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Ints,    int,    int32_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Uints,   uint,   uint32_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Longs,   long,   int64_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Ulongs,  ulong,  uint64_t)



#undef _LS_SCRIPT_DEFINE_BIT_FUNC
