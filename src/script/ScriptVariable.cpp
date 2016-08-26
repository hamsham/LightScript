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
namespace ls {
namespace script {

/*-------------------------------------
    Variable Object Destructor
-------------------------------------*/
Variable::~Variable() {
}

/*-------------------------------------
    Variable Object Constructor
-------------------------------------*/
Variable::Variable() :
    Scriptable {}
{}

/*-------------------------------------
    Variable Object Copy Constructor
-------------------------------------*/
Variable::Variable(const Variable& v) :
    Scriptable {v}
{}

/*-------------------------------------
    Variable Object Move Constructor
-------------------------------------*/
Variable::Variable(Variable&& v) :
    Scriptable {std::move(v)}
{}

} // end script namespace
} // end ls namespace
