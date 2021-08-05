/*
 * File:   variable.cpp
 * Author: Miles Lacey
 *
 * Created on April 13, 2014, 9:05 PM
 */

#include "lightsky/script/ScriptVariable.h"

/*-----------------------------------------------------------------------------
    Non-Templated Class Definitions
-----------------------------------------------------------------------------*/
namespace ls
{
namespace script
{



/*-------------------------------------
    Variable Object Destructor
-------------------------------------*/
Variable::~Variable()
{
}



/*-------------------------------------
    Variable Object Constructor
-------------------------------------*/
Variable::Variable() :
    Scriptable{}
{
}



/*-------------------------------------
    Variable Object Copy Constructor
-------------------------------------*/
Variable::Variable(const Variable& v) :
    Scriptable{v}
{
}



/*-------------------------------------
    Variable Object Move Constructor
-------------------------------------*/
Variable::Variable(Variable&& v) :
    Scriptable{std::move(v)}
{
}



/*-------------------------------------
    Variable Object Copy Assignment
-------------------------------------*/
Variable& Variable::operator=(const Variable& v)
{
    Scriptable::operator=(v);
    return *this;
}



/*-------------------------------------
    Variable Object Move Assignment
-------------------------------------*/
Variable& Variable::operator=(Variable&& v)
{
    Scriptable::operator=(std::move(v));
    return *this;
}



} // end script namespace
} // end ls namespace
