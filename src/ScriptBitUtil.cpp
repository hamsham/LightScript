/*
 * File:   ScriptBitUtil.cpp
 * Author: hammy
 *
 * Created on August 7, 2021, 6:16 PM
 */

#include "lightsky/script/ScriptBitUtil.h"



/*-----------------------------------------------------------------------------
 * Bit Manipulation Definitions
-----------------------------------------------------------------------------*/
#define _LS_SCRIPT_DEFINE_BIT_FUNC(scriptNameUpper, scriptNameLower, type) \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitShiftL##scriptNameUpper##s, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) << LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitShiftR##scriptNameUpper##s, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) >> LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitOr##scriptNameUpper##s, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) | LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitAnd##scriptNameUpper##s, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) & LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitXor##scriptNameUpper##s, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = LS_SCRIPT_PARAM(1, type) ^ LS_SCRIPT_PARAM(2, type); \
} \
\
LS_SCRIPT_DEFINE_FUNC_SHARED(BitFlip##scriptNameUpper, ScriptVar_##scriptNameLower, ScriptVar_##scriptNameLower) \
{ \
    LS_SCRIPT_PARAM(0, type) = ~(LS_SCRIPT_PARAM(1, type)); \
}



_LS_SCRIPT_DEFINE_BIT_FUNC(Byte,   byte,   uint8_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Short,  short,  int16_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Ushort, ushort, uint16_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Int,    int,    int32_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Uint,   uint,   uint32_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Long,   long,   int64_t)
_LS_SCRIPT_DEFINE_BIT_FUNC(Ulong,  ulong,  uint64_t)



#undef _LS_SCRIPT_DEFINE_BIT_FUNC
