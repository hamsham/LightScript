
#include "ls/script/Scriptable.h"

namespace ls {
namespace script {

/*-------------------------------------
    Destructor
-------------------------------------*/
Scriptable::~Scriptable() {
}

/*-------------------------------------
    Constructor
-------------------------------------*/
Scriptable::Scriptable() {
}

/*-------------------------------------
    Copy Constructor
-------------------------------------*/
Scriptable::Scriptable(const Scriptable&) {
}

/*-------------------------------------
    Move Constructor
-------------------------------------*/
Scriptable::Scriptable(Scriptable&&) {
}

/*-------------------------------------
    Copy Operator
-------------------------------------*/
Scriptable& Scriptable::operator =(const Scriptable&) {
    return *this;
}

/*-------------------------------------
    Move Operator
-------------------------------------*/
Scriptable& Scriptable::operator =(Scriptable&&) {
    return *this;
}

} // end script namespace
} // end ls namespace
