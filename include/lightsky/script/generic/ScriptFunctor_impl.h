
#include <cassert>

namespace ls
{
namespace script
{



/*-----------------------------------------------------------------------------
    Functor Base Class
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Retrieve the next function to run
-------------------------------------*/
inline
Functor* Functor::next_func_ptr()
{
    return pNextFunc;
}



/*-------------------------------------
    Set the next function to run.
-------------------------------------*/
inline
void Functor::next_func_ptr(Functor* const f)
{
    pNextFunc = f;
}



/*-------------------------------------
    Get the scriptable type.
-------------------------------------*/
inline
ScriptBaseType Functor::base_type() const
{
    return ScriptBaseType::FUNCTOR;
}



/*-------------------------------------
    Get a functor argument
-------------------------------------*/
inline
Variable* Functor::arg(unsigned index) const
{
    assert(index < this->num_args());
    return pArgs[index];
}



/*-------------------------------------
    Set a functor argument
-------------------------------------*/
inline
void Functor::arg(unsigned index, Variable* v)
{
    assert(index < this->num_args());
    pArgs[index] = v;
}



/*-------------------------------------
    Functor parameter type-checking for a single argument.
-------------------------------------*/
template <typename arg_t>
bool Functor::check_single_arg(const Functor& f, unsigned i, arg_t* t)
{
    if (i >= f.num_args())
    {
        std::cerr
            << "Error: Incorrect number of arguments being compiled: "
            << "\n\tFunction:   " << (void*)&f << '-' << f.sub_type()
            << "\n\tParameter:  " << i << '/' << f.num_args()
            << std::endl;
        return false;
    }

    if (f.arg(i) == nullptr)
    {
        std::cerr
            << "Error: Function contains a null parameter: "
            << "\n\tFunction:    " << (void*)&f << '-' << f.sub_type()
            << "\n\tParameter:   " << i << '/' << f.num_args()
            << std::endl;
        return false;
    }

    if (dynamic_cast<const arg_t*> (f.arg(i)) == nullptr)
    {
        std::cerr
            << "Error: TypeID of function argument does not match the type declared in its parent function."
            << "\n\tFunction:    " << (void*)&f << '-' << f.sub_type()
            << "\n\tInput type:  " << typeid(f.arg(i)).name()
            << "\n\tActual type: " << typeid(t).name()
            << std::endl;
        return false;
    }
    return true;
}



/*-------------------------------------
    Run a functor
-------------------------------------*/
inline
void Functor::run()
{
    pFunction(pArgs);
}



/*-------------------------------------
    Functor parameter type-checking (Recursive)
-------------------------------------*/
template <typename arg_t, typename... args_t> inline
bool Functor::check_args(const Functor& f, unsigned i, arg_t* t, args_t* ...)
{
    return check_single_arg<arg_t>(f, i, t)
           && check_args<args_t...>(f, i + 1, ((args_t*)nullptr)...);
}



/*-------------------------------------
    Functor parameter type-checking (Sentinel)
-------------------------------------*/
template <typename arg_t> inline
bool Functor::check_args(const Functor& f, unsigned i, arg_t* t)
{
    return check_single_arg<arg_t>(f, i, t);
}

/*-----------------------------------------------------------------------------
    Functor Derived Template Types
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Destructor
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>::~Functor_t()
{
}



/*-------------------------------------
    Constructor
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>::Functor_t() :
    Functor{parameters, func_impl}
{
}



/*-------------------------------------
    Copy Constructor
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>::Functor_t(const Functor_t& f) :
    Functor{parameters, func_impl}
{
    Functor::operator=(f);
}



/*-------------------------------------
    Move Constructor
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>::Functor_t(Functor_t && f)

:
Functor
{
parameters, func_impl
}
{
Functor::operator=(std::move(f));
}



/*-------------------------------------
    Copy Assignment
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>& Functor_t<hashId, args_t...>::operator=(const Functor_t& f)
{
    Functor::operator=(f);
    return *this;
}



/*-------------------------------------
    Move Assignment
-------------------------------------*/
template <hash_t hashId, typename... args_t>
Functor_t<hashId, args_t...>& Functor_t<hashId, args_t...>::operator=(Functor_t && f)
{
    Functor::operator=(std::move(f));
    return *this;
}



/*-------------------------------------
    RTTI
-------------------------------------*/
template <hash_t hashId, typename... args_t> inline
hash_t Functor_t<hashId, args_t...>::sub_type() const
{
    return hashId;
}



/*-------------------------------------
    Argument Count Retrieval
-------------------------------------*/
template <hash_t hashId, typename... args_t> inline
unsigned Functor_t<hashId, args_t...>::num_args() const
{
    return sizeof...(args_t);
}



/*-------------------------------------
    Load from an Input Stream
-------------------------------------*/
template <hash_t hashId, typename... args_t>
bool Functor_t<hashId, args_t...>::load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm)
{
    Functor::load(istr, vlm, flm);

    for (unsigned i = 0; i < sizeof...(args_t); ++i)
    {
        Variable* ptr = nullptr;
        istr >> (void*&)ptr;
        pArgs[i] = ptr ? vlm.at(ptr).get() : nullptr;
    }

    return istr.good() || istr.eof();
}



/*-------------------------------------
    Save to an Output Stream
-------------------------------------*/
template <hash_t hashId, typename... args_t>
bool Functor_t<hashId, args_t...>::save(std::ostream& ostr) const
{
    Functor::save(ostr);

    for (unsigned i = 0; i < sizeof...(args_t); ++i)
    {
        ostr << ' ' << (void*)pArgs[i];
    }
    return ostr.good();
}



/*-------------------------------------
    Argument Verification/Compilation
-------------------------------------*/
template <hash_t hashId, typename... args_t> inline
bool Functor_t<hashId, args_t...>::compile()
{
    return Functor::check_args(*this, 0, ((args_t*)nullptr)...);
}

/*-----------------------------------------------------------------------------
    Functor Derived Template Types (Void Functor Specialization).
-----------------------------------------------------------------------------*/
/*-------------------------------------
    Destructor
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>::~Functor_t()
{
}



/*-------------------------------------
    Constructor
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>::Functor_t() :
    Functor{nullptr, func_impl}
{
}



/*-------------------------------------
    Copy Constructor
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>::Functor_t(const Functor_t& f) :
    Functor{nullptr, func_impl}
{
    Functor::operator=(f);
}



/*-------------------------------------
    Move Constructor
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>::Functor_t(Functor_t && f)

:
Functor{
nullptr, func_impl}
{
Functor::operator=(std::move(f));

}



/*-------------------------------------
    Copy Assignment
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>& Functor_t<hashId, void>::operator=(const Functor_t& f)
{
    Functor::operator=(f);
    return *this;
}



/*-------------------------------------
    Move Assignment
-------------------------------------*/
template <hash_t hashId>
Functor_t<hashId, void>& Functor_t<hashId, void>::operator=(Functor_t && f)
{
    Functor::operator=(std::move(f));
    return *this;
}



/*-------------------------------------
    RTTI
-------------------------------------*/
template <hash_t hashId> inline
hash_t Functor_t<hashId, void>::sub_type() const
{
    return hashId;
}



/*-------------------------------------
    Argument Count Retrieval
-------------------------------------*/
template <hash_t hashId> inline
unsigned Functor_t<hashId, void>::num_args() const
{
    return 0;
}



/*-------------------------------------
    Load from an Input Stream
-------------------------------------*/
template <hash_t hashId>
bool Functor_t<hashId, void>::load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm)
{
    return Functor::load(istr, vlm, flm);
}



/*-------------------------------------
    Save to an Output Stream
-------------------------------------*/
template <hash_t hashId>
bool Functor_t<hashId, void>::save(std::ostream& ostr) const
{
    return Functor::save(ostr);
}



/*-------------------------------------
    Argument Verification/Compilation
-------------------------------------*/
template <hash_t hashId> inline
bool Functor_t<hashId, void>::compile()
{
    return true;
}



} // end script namespace
} // end ls namespace
