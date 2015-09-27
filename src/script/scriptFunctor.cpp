/* 
 * File:   functor.cpp
 * Author: Miles Lacey
 * 
 * Created on April 13, 2014, 9:07 PM
 */

#include <utility> // std::move

#include "lightsky/script/scriptFactory.h"
#include "lightsky/script/scriptFunctor.h"

namespace ls {
namespace script {

/*-----------------------------------------------------------------------------
    Functor Base Class
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Destructor
-------------------------------------*/
functor::~functor() {
}

/*-------------------------------------
    Constructor
-------------------------------------*/
functor::functor(variable** const pArguments, func_ref_t pFunc) :
    scriptable{},
    nextFunc{nullptr},
    pFunction{pFunc},
    pArgs{pArguments}
{}

/*-------------------------------------
    Copy Operator
-------------------------------------*/
functor& functor::operator =(const functor& f) {
    scriptable::operator=(f);
    
    for (unsigned i = 0; i < f.getNumArgs(); ++i) {
        pArgs[i] = f.pArgs[i];
    }
    nextFunc = f.nextFunc;
    
    return *this;
}

/*-------------------------------------
    Move Operator
-------------------------------------*/
functor& functor::operator =(functor&& f) {
    scriptable::operator=(std::move(f));
    
    for (unsigned i = 0; i < f.getNumArgs(); ++i) {
        pArgs[i] = f.pArgs[i];
        f.pArgs[i] = nullptr;
    }
    
    nextFunc = f.nextFunc;
    f.nextFunc = nullptr;
    
    return *this;
}

/*-------------------------------------
    Loading a functor from an input stream
-------------------------------------*/
bool functor::load(std::istream& istr, variableMap_t&, functorMap_t& flm) {
    hash_t nextType = 0;
    functor* ptr = nullptr;

    istr >> nextType >> (void*&)ptr;

    nextFunc = flm.count(ptr) ? flm[ptr].get() : nullptr;

    // Return false if no instance of a "valid" variable was contained in the
    // import map.
    if (nextFunc == nullptr && ptr != nullptr) {
        return false;
    }

    return true;
}

/*-------------------------------------
    Saving a functor to an output stream
-------------------------------------*/
bool functor::save(std::ostream& ostr) const {
    if (nextFunc == nullptr) {
        ostr << 0 << ' ' << 0;
    }
    else {
        ostr << nextFunc->getScriptSubType() << ' ' << (void*)nextFunc;
    }
    
    return ostr.good();
}

/*-----------------------------------------------------------------------------
    NULL Functor Template Type.
-----------------------------------------------------------------------------*/
func_ref_t functor_t<0, void>::functionImpl = *[](variable** const)->void {    
};

/*-------------------------------------
    Destructor
-------------------------------------*/
functor_t<0, void>::~functor_t() {
}

/*-------------------------------------
    Constructor
-------------------------------------*/
functor_t<0, void>::functor_t() :
    functor{nullptr, functionImpl}
{}

/*-------------------------------------
    Copy Constructor
-------------------------------------*/
functor_t<0, void>::functor_t(const functor_t& f) :
    functor{nullptr, functionImpl}
{
    functor::operator=(f);
}

/*-------------------------------------
    Move Constructor
-------------------------------------*/
functor_t<0, void>::functor_t(functor_t&& f) :
    functor{nullptr, functionImpl}
{
    functor::operator=(std::move(f));
}

/*-------------------------------------
    Copy Assignment
-------------------------------------*/
functor_t<0, void>& functor_t<0, void>::operator =(const functor_t& f) {
    functor::operator=(f);
    return *this;
}

/*-------------------------------------
    Move Assignment
-------------------------------------*/
functor_t<0, void>& functor_t<0, void>::operator =(functor_t&& f) {
    functor::operator=(std::move(f));
    return *this;
}

/*-------------------------------------
    RTTI
-------------------------------------*/
hash_t functor_t<0, void>::getScriptSubType() const {
    return 0;
}

/*-------------------------------------
    Argument Count Retrieval
-------------------------------------*/
unsigned functor_t<0, void>::getNumArgs() const {
    return 0;
}

/*-------------------------------------
    Load from an Input Stream
-------------------------------------*/
bool functor_t<0, void>::load(std::istream& istr, variableMap_t& vlm, functorMap_t& flm) {
    return functor::load(istr, vlm, flm);
}

/*-------------------------------------
    Save to an Output Stream
-------------------------------------*/
bool functor_t<0, void>::save(std::ostream& ostr) const {
    return functor::save(ostr);
}

/*-------------------------------------
    Argument Verification/Compilation
-------------------------------------*/
bool functor_t<0, void>::compile() {
    return true;
}

/*-----------------------------------------------------------------------------
    Built-In Types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DEFINE_FUNC(empty, void) {
    (void)pArgs;
};

} // end script namespace
} // end ls namespace
