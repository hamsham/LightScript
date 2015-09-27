/* 
 * File:   scriptBasicVar.cpp
 * Author: hammy
 * 
 * Created on March 12, 2015, 12:52 AM
 */

#include "lightsky/script/scriptFactory.h"
#include "lightsky/script/scriptBasicVar.h"

namespace ls {
namespace script {

/*-----------------------------------------------------------------------------
    Basic Built-In types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DEFINE_VAR(char,      char);
LS_SCRIPT_DEFINE_VAR(short,     short);
LS_SCRIPT_DEFINE_VAR(int,       int);
LS_SCRIPT_DEFINE_VAR(uint,      unsigned);
LS_SCRIPT_DEFINE_VAR(long,      long);
LS_SCRIPT_DEFINE_VAR(ulong,     unsigned long);
LS_SCRIPT_DEFINE_VAR(float,     float);
LS_SCRIPT_DEFINE_VAR(double,    double);
LS_SCRIPT_DEFINE_VAR(string,    std::string);

/*-----------------------------------------------------------------------------
    Built-In type overrides
-----------------------------------------------------------------------------*/
/*-------------------------------------
 * String Serialization
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_SAVE(std::string) {
    const std::string::size_type len = data.size()*sizeof(std::string::value_type);
    ostr << len;
    ostr.write(data.data(), len);
    return ostr.good();
}

/*-------------------------------------
 * String Deserialization
-------------------------------------*/
LS_SCRIPT_OVERRIDE_VAR_LOAD(std::string) {
    (void)varImporter;
    (void)funcImporter;
    std::string::size_type len = 0;
    istr >> len;

    data.resize(len, '\0');
    istr.read(&data[0], len);
    
    if (data.size() != len) {
        data.clear();
        return false;
    }
    
    return istr.good() || istr.eof();
}

} // end script namespace
} // end ls namespace
