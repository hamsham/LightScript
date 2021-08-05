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
LS_SCRIPT_DEFINE_VAR_SHARED(byte, uint8_t);

LS_SCRIPT_DEFINE_VAR_SHARED(short, int16_t);

LS_SCRIPT_DEFINE_VAR_SHARED(ushort, uint16_t);

LS_SCRIPT_DEFINE_VAR_SHARED(int, int32_t);

LS_SCRIPT_DEFINE_VAR_SHARED(uint, uint32_t);

LS_SCRIPT_DEFINE_VAR_SHARED(long, int64_t);

LS_SCRIPT_DEFINE_VAR_SHARED(ulong, uint64_t);

LS_SCRIPT_DEFINE_VAR_SHARED(float, float);

LS_SCRIPT_DEFINE_VAR_SHARED(double, double);

LS_SCRIPT_DEFINE_VAR_SHARED(string, std::string);



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
