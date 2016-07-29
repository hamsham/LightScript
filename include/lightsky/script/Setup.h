/*
 * File:   setup.h
 * Author: Miles Lacey
 *
 * Created on June 26, 2013, 5:18 AM
 */

#ifndef __LS_SCRIPT_SETUP_H__
#define __LS_SCRIPT_SETUP_H__

#include <unordered_map>

#include "ls/setup/Api.h"
#include "ls/setup/Macros.h"

#include "ls/utils/Hash.h"
#include "ls/utils/Pointer.h"

namespace ls {
namespace script {

/*-----------------------------------------------------------------------------
    Hashing Setup
-----------------------------------------------------------------------------*/
/**
 * @brief Hash type used to associate script types to a serializable ID.
 */
using ls::utils::hash_t;

/**
 * @brief Scripting function used internally for generating script IDs.
 */
#define __LS_SCRIPT_H__ ASH_FUNC( str ) ls::utils::hash_fnv1( str )



/*-----------------------------------------------------------------------------
    Data Type information
-----------------------------------------------------------------------------*/
enum class script_base_t : int {
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
template <class data_t> using Pointer_t = ls::utils::Pointer<data_t>;

/*
 * Create an extern template for the dynamic pointer type.
 */
} // end script namespace

extern template class ls::utils::Pointer<ls::script::Variable>;
extern template class ls::utils::Pointer<ls::script::Functor>;

namespace script // continue script namespace
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
