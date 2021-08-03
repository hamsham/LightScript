/*
 * File:   scriptIO.cpp
 * Author: Miles LAcey
 *
 * Created on March 24, 2015, 8:48 PM
 */

#include "lightsky/script/ScriptIO.h"

/*-----------------------------------------------------------------------------
 Data Input/Output
-----------------------------------------------------------------------------*/
namespace ls
{
namespace script
{

/*-------------------------------------
 * Standard Output
-------------------------------------*/
LS_SCRIPT_DEFINE_VAR(StdPrint, void*);

/*-----------------------------------------------------------------------------
 * Print functions for basic data types
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * Because this library needs more macros.
-------------------------------------*/
#define LS_SCRIPT_DEFINE_VAR_PRINT(formalName, basicName, dataType) \
    LS_SCRIPT_DEFINE_FUNC(StdPrint##formalName, ScriptVar_StdPrint, ScriptVar_##basicName) \
    { \
        (void)pArgs; \
        std::cout << LS_SCRIPT_PARAM(1, dataType); \
    }

LS_SCRIPT_DEFINE_VAR_PRINT(Byte, byte, uint8_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Short, short, int16_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Ushort, ushort, uint16_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Int, int, int32_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Uint, uint, uint32_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Long, long, int64_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Ulong, ulong, uint64_t);

LS_SCRIPT_DEFINE_VAR_PRINT(Float, float, float);

LS_SCRIPT_DEFINE_VAR_PRINT(Double, double, double);

LS_SCRIPT_DEFINE_VAR_PRINT(String, string, std::string);

#undef LS_SCRIPT_DEFINE_VAR_PRINT
} // end script namespace
} // end ls namespace
