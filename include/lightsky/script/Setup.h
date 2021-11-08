/*
 * File:   setup.h
 * Author: Miles Lacey
 *
 * Created on June 26, 2013, 5:18 AM
 */

#ifndef __LS_SCRIPT_SETUP_H__
#define __LS_SCRIPT_SETUP_H__

#include <memory>
#include <algorithm>
#include <unordered_map>

#ifdef LS_HAVE_LS_POINTERS
    #include "lightsky/utils/Hash.h"
    #include "lightsky/utils/Pointer.h"
#endif



/*-----------------------------------------------------------------------------
    Common Macros
-----------------------------------------------------------------------------*/
/*
 * Dynamic Library Setup
 */
#if defined(_MSC_VER)
    #if defined(LS_BUILD_SHARED)
        #define LS_SCRIPT_API __declspec(dllexport)
        #define LS_SCRIPT_EXPORT_API __declspec(dllexport)
        #define LS_SCRIPT_EXTERN
    #else
        #define LS_SCRIPT_API __declspec(dllimport)
        #define LS_SCRIPT_EXPORT_API
        #define LS_SCRIPT_EXTERN extern
    #endif

    #define LS_SCRIPT_STATIC_API

#elif defined(__GNUC__)
    #if defined(LS_BUILD_SHARED)
        #define LS_SCRIPT_API __attribute__((__visibility__("default")))
        #define LS_SCRIPT_EXPORT_API __attribute__((__visibility__("default")))
    #else
        #define LS_SCRIPT_API
        #define LS_SCRIPT_EXPORT_API
    #endif

    #define LS_SCRIPT_STATIC_API
    #define LS_SCRIPT_EXTERN extern

#else
    #define LS_SCRIPT_API
    #define LS_SCRIPT_EXPORT_API
    #define LS_SCRIPT_STATIC_API
    #define LS_SCRIPT_EXTERN extern
#endif



/*
 * Calling Conventions
 */
#if !(defined (_WIN64) || defined (__amd64__) || defined (_M_X64)) && (defined (__i386__) || defined (_M_IX86_) || defined (__THW_INTEL__))
    #if defined(_MSC_VER)
        #define LS_SCRIPT_CALL __stdcall
    #elif defined __GNUC__
        #define LS_SCRIPT_CALL __attribute__((stdcall))
    #endif
#else
    #define LS_SCRIPT_CALL
#endif



/*
 * Stringification
 */
#ifndef LS_STRINGIFY
    #define LS_STRINGIFY(x) #x
#endif



namespace ls
{
namespace script
{



/*-----------------------------------------------------------------------------
    Hashing Setup
-----------------------------------------------------------------------------*/
/**
 * @brief Hash type used to associate script types to a serializable ID.
 */
#ifdef LS_HAVE_LS_POINTERS
    using ls::utils::hash_t;

    #ifndef LS_SCRIPT_HASH_FUNC
        #define LS_SCRIPT_HASH_FUNC ls::utils::hash_fnv1
    #endif

#else
    typedef std::size_t hash_t;

#endif /* LS_HAVE_LS_POINTERS */



/**
 * @brief Scripting function used internally for generating script IDs.
 */
#ifndef LS_SCRIPT_HASH_FUNC
/*-------------------------------------
 * FNV-1a hash implementation
 * ----------------------------------*/
constexpr hash_t hashFNV1_impl(const char* str, unsigned int hashVal) noexcept
{
    return (!*str) ? hashVal : hashFNV1_impl(str + 1, *str ^ (hashVal * 16777619));
}

/*-------------------------------------
 * FNV-1a hash interface
 * ----------------------------------*/
constexpr hash_t hash_fnv1(const char* str) noexcept
{
    return (!str) ? 0 : hashFNV1_impl(str, 2166136261);
}

#define LS_SCRIPT_HASH_FUNC(str) ls::script::hash_fnv1(str)

#endif



/*-----------------------------------------------------------------------------
    Data Type information
-----------------------------------------------------------------------------*/
enum class ScriptBaseType : int
{
    VARIABLE,
    FUNCTOR
};



/*-----------------------------------------------------------------------------
 Forward Declarations
-----------------------------------------------------------------------------*/
class Scriptable;
class Variable;
class Functor;



/*-----------------------------------------------------------------------------
 Dynamic Memory Types
-----------------------------------------------------------------------------*/
/**------------------------------------
 * Dynamic Memory Management for script objects.
------------------------------------*/
#ifdef LS_HAVE_LS_POINTERS
    template <class data_t> using Pointer_t = ls::utils::Pointer<data_t, ls::utils::PointerDeleter<data_t>>;
#else
    template <class data_t> using Pointer_t = std::unique_ptr<data_t, std::default_delete<data_t>>;
#endif /* LS_HAVE_LS_POINTERS */



} // end script namespace
} // end ls namespace



/*
 * Create an extern template for the dynamic pointer type... If we're not on MSVC
 */
#if !defined(_MSC_VER)

    #ifdef LS_HAVE_LS_POINTERS
        LS_SCRIPT_EXTERN template class LS_SCRIPT_API ls::utils::Pointer<ls::script::Variable, ls::utils::PointerDeleter<ls::script::Variable>>;
        LS_SCRIPT_EXTERN template class LS_SCRIPT_API ls::utils::Pointer<ls::script::Functor, ls::utils::PointerDeleter<ls::script::Functor>>;

    #else
        LS_SCRIPT_EXTERN template class LS_SCRIPT_API std::unique_ptr<ls::script::Variable, std::default_delete<ls::script::Variable>>;
        LS_SCRIPT_EXTERN template class LS_SCRIPT_API std::unique_ptr<ls::script::Functor, std::default_delete<ls::script::Functor>>;

    #endif /* LS_HAVE_LS_POINTERS */

#endif /* _MSC_VER */



// continue script namespace
namespace ls
{
namespace script
{



/*-----------------------------------------------------------------------------
    Containers
-----------------------------------------------------------------------------*/
/**
 * @brief File loading map for variable objects.
 */
typedef std::unordered_map<Variable*, Pointer_t<Variable>> VariableMap_t;

/**
 * @brief File loading map for functor objects.
 */
typedef std::unordered_map<Functor*, Pointer_t<Functor>> FunctorMap_t;



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_SETUP_H__ */
