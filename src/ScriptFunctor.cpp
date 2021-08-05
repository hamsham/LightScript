/*
 * File:   functor.cpp
 * Author: Miles Lacey
 *
 * Created on April 13, 2014, 9:07 PM
 */

#include <utility> // std::move

#include "lightsky/script/ScriptFactory.h"
#include "lightsky/script/ScriptFunctor.h"



namespace ls
{
namespace script
{

/*-----------------------------------------------------------------------------
    Functor Base Class
-----------------------------------------------------------------------------*/

/*-------------------------------------
    Destructor
-------------------------------------*/
Functor::~Functor()
{
}



/*-------------------------------------
    Constructor
-------------------------------------*/
Functor::Functor(Variable** const pArguments, FuncRef_t pFunc) :
    Scriptable{},
    pNextFunc{nullptr},
    pFunction{pFunc},
    pArgs{pArguments}
{
}



/*-------------------------------------
    Copy Operator
-------------------------------------*/
Functor& Functor::operator=(const Functor& f)
{
    Scriptable::operator=(f);

    for (unsigned i = 0; i < f.num_args(); ++i)
    {
        pArgs[i] = f.pArgs[i];
    }
    pNextFunc = f.pNextFunc;

    return *this;
}



/*-------------------------------------
    Move Operator
-------------------------------------*/
Functor& Functor::operator=(Functor&& f)
{
    Scriptable::operator=(std::move(f));

    for (unsigned i = 0; i < f.num_args(); ++i)
    {
        pArgs[i] = f.pArgs[i];
        f.pArgs[i] = nullptr;
    }

    pNextFunc = f.pNextFunc;
    f.pNextFunc = nullptr;

    return *this;
}



/*-------------------------------------
    Loading a functor from an input stream
-------------------------------------*/
bool Functor::load(std::istream& istr, VariableMap_t&, FunctorMap_t& flm)
{
    hash_t nextType = 0;
    Functor * ptr = nullptr;

    istr >> nextType >> (void*&)ptr;

    pNextFunc = flm.count(ptr) ? flm[ptr].get() : nullptr;

    // Return false if no instance of a "valid" variable was contained in the
    // import map.
    if (pNextFunc == nullptr && ptr != nullptr)
    {
        return false;
    }

    return true;
}



/*-------------------------------------
    Saving a functor to an output stream
-------------------------------------*/
bool Functor::save(std::ostream& ostr) const
{
    if (pNextFunc == nullptr)
    {
        ostr << 0 << ' ' << 0;
    }
    else
    {
        ostr << pNextFunc->sub_type() << ' ' << (void*)pNextFunc;
    }

    return ostr.good();
}



/*-----------------------------------------------------------------------------
    NULL Functor Template Type.
-----------------------------------------------------------------------------*/
LS_API void Functor_t<0, void>::func_impl(Variable** const)
{
}



/*-------------------------------------
    Destructor
-------------------------------------*/
Functor_t<0, void>::~Functor_t()
{
}



/*-------------------------------------
    Constructor
-------------------------------------*/
Functor_t<0, void>::Functor_t() :
    Functor{nullptr, func_impl}
{
}



/*-------------------------------------
    Copy Constructor
-------------------------------------*/
Functor_t<0, void>::Functor_t(const Functor_t& f) :
    Functor{nullptr, func_impl}
{
    Functor::operator=(f);
}



/*-------------------------------------
    Move Constructor
-------------------------------------*/
Functor_t<0, void>::Functor_t(Functor_t && f) :
    Functor{nullptr, func_impl}
{
    Functor::operator=(std::move(f));
}



/*-------------------------------------
    Copy Assignment
-------------------------------------*/
Functor_t<0, void>& Functor_t<0, void>::operator=(const Functor_t& f)
{
    Functor::operator=(f);
    return *this;
}



/*-------------------------------------
    Move Assignment
-------------------------------------*/
Functor_t<0, void>& Functor_t<0, void>::operator=(Functor_t && f)
{
    Functor::operator=(std::move(f));
    return *this;
}



/*-------------------------------------
    RTTI
-------------------------------------*/
hash_t Functor_t<0, void>::sub_type() const
{
    return 0;
}



/*-------------------------------------
    Argument Count Retrieval
-------------------------------------*/
unsigned Functor_t<0, void>::num_args() const
{
    return 0;
}



/*-------------------------------------
    Load from an Input Stream
-------------------------------------*/
bool Functor_t<0, void>::load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm)
{
    return Functor::load(istr, vlm, flm);
}



/*-------------------------------------
    Save to an Output Stream
-------------------------------------*/
bool Functor_t<0, void>::save(std::ostream& ostr) const
{
    return Functor::save(ostr);
}



/*-------------------------------------
    Argument Verification/Compilation
-------------------------------------*/
bool Functor_t<0, void>::compile()
{
    return true;
}



} // end script namespace
} // end ls namespace



/*-----------------------------------------------------------------------------
    Built-In Types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DEFINE_FUNC_SHARED(empty, void)
{
    (void)pArgs;
}
