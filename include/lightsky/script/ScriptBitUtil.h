/*
 * File:   ScriptBitUtil.h
 * Author: hammy
 *
 * Created on August 27, 2021, 6:16 PM
 */

#ifndef __LS_SCRIPT_BITUTIL_H__
#define __LS_SCRIPT_BITUTIL_H__

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptBasicVar.h"
#include "lightsky/script/ScriptFunctor.h"



/*-----------------------------------------------------------------------------
 * Bit Manipulation Declarations
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * Bytes
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorBytes, ScriptVar_byte, ScriptVar_byte, ScriptVar_byte);



/*-------------------------------------
 * Shorts
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorShorts, ScriptVar_short, ScriptVar_short, ScriptVar_short);



/*-------------------------------------
 * Unsigned Shorts
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorUshorts, ScriptVar_ushort, ScriptVar_ushort, ScriptVar_ushort);



/*-------------------------------------
 * Ints
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorInts, ScriptVar_int, ScriptVar_int, ScriptVar_int);



/*-------------------------------------
 * Unsigned Ints
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorUints, ScriptVar_uint, ScriptVar_uint, ScriptVar_uint);



/*-------------------------------------
 * Longs
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorLongs, ScriptVar_long, ScriptVar_long, ScriptVar_long);



/*-------------------------------------
 * Unsigned longs
-------------------------------------*/
// Left Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftLUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Right Shift
LS_SCRIPT_DECLARE_FUNC_SHARED(BitShiftRUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Inclusive OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitOrUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Logical AND
LS_SCRIPT_DECLARE_FUNC_SHARED(BitAndUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);

// Exclusive-OR
LS_SCRIPT_DECLARE_FUNC_SHARED(BitXorUlongs, ScriptVar_ulong, ScriptVar_ulong, ScriptVar_ulong);



#endif /* __LS_SCRIPT_BITUTIL_H__ */
