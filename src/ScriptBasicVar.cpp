/*
 * File:   scriptBasicVar.cpp
 * Author: hammy
 *
 * Created on March 12, 2015, 12:52 AM
 */

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptBasicVar.h"



/*-----------------------------------------------------------------------------
    Basic Built-In types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DEFINE_VAR_SHARED(bool, bool);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignBool, ScriptVar_bool, ScriptVar_bool)
{
    LS_SCRIPT_PARAM(0, bool) = LS_SCRIPT_PARAM(1, bool);
}



LS_SCRIPT_DEFINE_VAR_SHARED(byte, uint8_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignByte, ScriptVar_byte, ScriptVar_byte)
{
    LS_SCRIPT_PARAM(0, uint8_t) = LS_SCRIPT_PARAM(1, uint8_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(short, int16_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignShort, ScriptVar_short, ScriptVar_short)
{
    LS_SCRIPT_PARAM(0, int16_t) = LS_SCRIPT_PARAM(1, int16_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(ushort, uint16_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignUshort, ScriptVar_ushort, ScriptVar_ushort)
{
    LS_SCRIPT_PARAM(0, uint16_t) = LS_SCRIPT_PARAM(1, uint16_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(int, int32_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignInt, ScriptVar_int, ScriptVar_int)
{
    LS_SCRIPT_PARAM(0, int32_t) = LS_SCRIPT_PARAM(1, int32_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(uint, uint32_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignUint, ScriptVar_uint, ScriptVar_uint)
{
    LS_SCRIPT_PARAM(0, uint32_t) = LS_SCRIPT_PARAM(1, uint32_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(long, int64_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignLong, ScriptVar_long, ScriptVar_long)
{
    LS_SCRIPT_PARAM(0, int64_t) = LS_SCRIPT_PARAM(1, int64_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(ulong, uint64_t);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignUlong, ScriptVar_ulong, ScriptVar_ulong)
{
    LS_SCRIPT_PARAM(0, uint64_t) = LS_SCRIPT_PARAM(1, uint64_t);
}



LS_SCRIPT_DEFINE_VAR_SHARED(float, float);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignFloat, ScriptVar_float, ScriptVar_float)
{
    LS_SCRIPT_PARAM(0, float) = LS_SCRIPT_PARAM(1, float);
}



LS_SCRIPT_DEFINE_VAR_SHARED(double, double);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignDouble, ScriptVar_double, ScriptVar_double)
{
    LS_SCRIPT_PARAM(0, double) = LS_SCRIPT_PARAM(1, double);
}



LS_SCRIPT_DEFINE_VAR_SHARED(string, std::string);
LS_SCRIPT_DEFINE_FUNC_SHARED(AssignString, ScriptVar_string, ScriptVar_string)
{
    LS_SCRIPT_PARAM(0, std::string) = LS_SCRIPT_PARAM(1, std::string);
}



/*-----------------------------------------------------------------------------
    Built-In type overrides
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * String Serialization
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_SAVE(LS_EXPORT_API, std::string)
{
    const std::string::size_type len = data.size() * sizeof(std::string::value_type);
    ostr << len;
    ostr.write(data.data(), len);
    return ostr.good();
}

/*-------------------------------------
 * String Deserialization
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_LOAD(LS_EXPORT_API, std::string)
{
    (void)varImporter;
    (void)funcImporter;
    std::string::size_type len = 0;
    istr >> len;

    data.resize(len, '\0');
    istr.read(&data[0], len);

    if (data.size() != len)
    {
        data.clear();
        return false;
    }

    return istr.good() || istr.eof();
}
