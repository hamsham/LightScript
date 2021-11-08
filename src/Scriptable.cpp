
#include "lightsky/script/Scriptable.h"



namespace ls
{
namespace script
{



/*-------------------------------------
    Destructor
-------------------------------------*/
LS_SCRIPT_API Scriptable::~Scriptable()
{
}



/*-------------------------------------
    Constructor
-------------------------------------*/
LS_SCRIPT_API Scriptable::Scriptable()
{
}



/*-------------------------------------
    Copy Constructor
-------------------------------------*/
LS_SCRIPT_API Scriptable::Scriptable(const Scriptable&)
{
}



/*-------------------------------------
    Move Constructor
-------------------------------------*/
LS_SCRIPT_API Scriptable::Scriptable(Scriptable&&)
{
}



/*-------------------------------------
    Copy Operator
-------------------------------------*/
LS_SCRIPT_API Scriptable& Scriptable::operator=(const Scriptable&)
{
    return *this;
}



/*-------------------------------------
    Move Operator
-------------------------------------*/
LS_SCRIPT_API Scriptable& Scriptable::operator=(Scriptable&&)
{
    return *this;
}



} // end script namespace
} // end ls namespace
