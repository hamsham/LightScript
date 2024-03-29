/*
 * File:   factory.h
 * Author: Miles Lacey
 *
 * Created on June 26, 2013, 5:58 AM
 */

#ifndef __LS_SCRIPT_FACTORY_H__
#define __LS_SCRIPT_FACTORY_H__

#include <unordered_map>

#include "lightsky/script/Setup.h"



namespace ls
{
namespace script
{

/*-----------------------------------------------------------------------------
 * Script Factory Functions
-----------------------------------------------------------------------------*/
/**
 * @brief varFactory_t
 *
 * This type represents a pointer to a function which instantiates a particular
 * variable type.
 */
typedef Pointer_t<Variable>(*VarFactory_t)();



/**
 * @brief funcFactory_t
 *
 * This type represents a pointer to a function which instantiates a particular
 * function type.
 */
typedef Pointer_t<Functor>(*FuncFactory_t)();



/*-----------------------------------------------------------------------------
 * Script Factory Maps
 *
 * A Factory map will map the hashed IDs of scriptable objects to their factory
 * functions. This allows script objects to be created through a simple map
 * for ease of use.
-----------------------------------------------------------------------------*/
/**
 * @brief varFactoryMap_t
 *
 * This type maps script variables to their factory functions.
 */
typedef std::unordered_map<hash_t, VarFactory_t> VarFactoryMap_t;

/**
 * @brief varFactoryMap_t
 *
 * This type maps script functors to their factory functions.
 */
typedef std::unordered_map<hash_t, FuncFactory_t> FuncFactoryMap_t;



/*-----------------------------------------------------------------------------
 * Factory Method Registration
-----------------------------------------------------------------------------*/
/**
 * @brief Register a factory function for instantiating a script variable type.
 *
 * Register a global factory method for a particular variable type and map it
 * to the hashId provided. This will allow a variable to be instantiated using
 * the function "createVariable(...)," combined with the same hash. Using this
 * method will overwrite any previously registered factory.
 *
 * @param factoryId
 * The hash value which will be used to map the provided factory method to the
 * global variable map.
 *
 * @param pFactory
 * A constant reference to the function object which instantiates a particular
 * variable object.
 *
 * @return A constant reference to the global factory method responsible for
 * creating a variable object using the hash provided.
 */
LS_SCRIPT_API const VarFactory_t& LS_SCRIPT_CALL register_var_factory(hash_t factoryId, const VarFactory_t& pFactory);



/**
 * @brief Register a factory function for instantiating a functor type.
 *
 * Register a global factory method for a particular function type and map it
 * to the hashId provided. This will allow a function to be instantiated using
 * the function "createFunctor(...)," combined with the same hash. Using this
 * method will overwrite any previously registered factory.
 *
 * @param factoryId
 * The hash value which will be used to map the provided factory method to the
 * global function map.
 *
 * @param pFactory
 * A constant reference to the function object which instantiates a particular
 * function object.
 *
 * @return A constant reference to the global factory method responsible for
 * creating a function object using the hash provided.
 */
LS_SCRIPT_API const FuncFactory_t& LS_SCRIPT_CALL register_func_factory(hash_t factoryId, const FuncFactory_t& pFactory);



/*-----------------------------------------------------------------------------
 * Script Object Instantiation/Deletion
-----------------------------------------------------------------------------*/
/**
 * @brief Create a script variable using the global variable factory
 *
 * @param factoryId
 * A hash value that determines the type of variable that should be returned.
 *
 * @return a pointer to the script variable requested. This pointer must be
 * destroyed with the "delete" operator.
 * This function will return NULL if the variable requested could not be
 * instantiated.
 */
LS_SCRIPT_API Pointer_t<Variable> LS_SCRIPT_CALL create_variable(hash_t factoryId);



/**
 * @brief Destroy/free an instance of a script variable object.
 *
 * @param pVariable
 * A reference to a pointer_t<> object which points to an instance of a
 * variable created using the "createVariable(...)" function.
 */
LS_SCRIPT_API void LS_SCRIPT_CALL destroy_variable(Pointer_t<Variable>& pVariable);



/**
 * @brief Create a script function using the global functor factory
 *
 * @param factoryId
 * A hash value that determines the type of functor that should be returned.
 *
 * @return a pointer to the script functor requested. This pointer must be
 * destroyed with the "delete" operator.
 * This function will return NULL if the functor requested could not be
 * instantiated.
 */
LS_SCRIPT_API Pointer_t<Functor> LS_SCRIPT_CALL create_functor(hash_t factoryId);



/**
 * @brief Destroy/free an instance of a script functor object.
 *
 * @param pFunc
 * A reference to a pointer_t<> object which points to an instance of a
 * functor created using the "createVariable(...)" function.
 */
LS_SCRIPT_API void LS_SCRIPT_CALL destroy_functor(Pointer_t<Functor>& pFunc);



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_FACTORY_H__ */
