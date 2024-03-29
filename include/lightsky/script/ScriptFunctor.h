/*
 * File:   functor.h
 * Author: Miles Lacey
 *
 * Created on April 13, 2014, 9:07 PM
 */

#ifndef __LS_SCRIPT_FUNCTOR_H__
#define __LS_SCRIPT_FUNCTOR_H__

#include <iostream> // std::cout, std::cin, std::cerr
#include <memory> // std::nothrow
#include <typeinfo> // typeid(x)
#include <utility> // std::move()

#include "lightsky/script/Setup.h"
#include "lightsky/script/Scriptable.h"
#include "lightsky/script/ScriptVariable.h"
#include "lightsky/script/ScriptFactory.h"



namespace ls
{
namespace script
{

/**
 *  @brief func_ref_t is a reference-to-function typedef to make things
 *  easier to understand in-code.
 *
 *  Use this typedef to instantiate a reference to a scripted function
 *  which takes an array of script variables as its parameters.
 */
typedef void (*const FuncRef_t)(Variable** const);



/**
 * @brief Status of a functor compilation.
 */
enum class CompileStatus
{
    SUCCESS,
    ERROR_INVALID_ARG_COUNT,
    ERROR_NULL_ARG,
    ERROR_INVALID_ARG_TYPE,
};



/**
 * @brief Return structure from a call to "Functor::compile()".
 *
 * This struct contains all information readily available about the functor's
 * compilation.
 */
struct CompileInfo
{
    CompileStatus status;
    unsigned argIndex;
    void* pArgVal;
};



/**
 * @brief Functor Base Class
 *
 * The functor base class is constructed with a reference to a native C/C++
 * function. It contains methods to store and load its parameters from a
 * script file, self-compile, and change its arguments at runtime.
 */
class LS_SCRIPT_API Functor : public Scriptable
{
  protected:
    /**
     *  @brief A verification method for single arguments.
     *
     *  This is similar to the 'compile' method, but allows one to check a
     *  single functor argument and verify that it is safe to operate at
     *  run-time. This is explicitly called for each argument when calling
     *  the 'compile()' method.
     *
     *  @param g
     *  A constant reference to a functor object.
     *
     *  @param i
     *  The index of the argument in 'f' to verify.
     *
     *  @param t
     *  A dummy type which allows argument type information to be matched
     *  against something.
     *
     *  @return TRUE if the argument in 'f', specified by 'i', is able
     *  to be used, FALSE if not.
     */
    template <typename arg_t>
    static CompileInfo check_single_arg(const Functor& f, unsigned i, arg_t* t);

    /**
     *  @brief A verification method for single arguments.
     *
     *  This is similar to the 'compile' method, but allows one to check a
     *  single functor argument and verify that it is safe to operate at
     *  run-time. This is explicitly called for each argument when calling
     *  the 'compile()' method.
     *
     *  @param g
     *  A constant reference to a functor object.
     *
     *  @param i
     *  The index of the argument in 'f' to verify.
     *
     *  @param t
     *  A dummy type which allows argument type information to be matched
     *  against something.
     *
     *  @param ts
     *  Addition types for subsequent argument matching.
     *
     *  @return TRUE if the argument in 'f', specified by 'i', is able
     *  to be used, FALSE if not.
     */
    template <typename arg_t, typename... args_t>
    static CompileInfo check_args(const Functor& f, unsigned i, arg_t* t, args_t*... ts);

    /**
     *  @brief A verification method for single arguments.
     *
     *  This is similar to the 'compile' method, but allows one to check a
     *  single functor argument and verify that it is safe to operate at
     *  run-time. This is explicitly called for each argument when calling
     *  the 'compile()' method.
     *
     *  @param g
     *  A constant reference to a functor object.
     *
     *  @param i
     *  The index of the argument in 'f' to verify.
     *
     *  @param t
     *  A dummy type which allows argument type information to be matched
     *  against something.
     *
     *  @return TRUE if the argument in 'f', specified by 'i', is able
     *  to be used, FALSE if not.
     */
    template <typename arg_t>
    static CompileInfo check_args(const Functor& f, unsigned i, arg_t* t);

    /**
     *  @brief the 'nextFunc' member is a pointer to another function that
     *  can be run after *this.
     *
     *  This member allows functions to be chained together at runtime,
     *  creating a linked-list of functions.
     */
    Functor* pNextFunc = nullptr;

    /**
     *  @brief 'pFunction' is a reference to a native function wrapper.
     *
     *  This member references a wrapper function which takes an array of
     *  script variables as parameters. Use the wrapper function to map
     *  argument parameters to actual, native parameters and a return
     *  value.
     */
    FuncRef_t pFunction;

    /**
     *  @brief An array of pointers to variables.
     *
     *  Retaining an array of argument pointers allows variables to be
     *  mapped to functors at run-time.
     */
    Variable** const pArgs;

    /**
     *  @brief Protected Constructor
     *
     *  This constructor MUST be called by any derived functor constructors
     *  in order to properly initialize *this and all members contained in
     *  *this.
     */
    Functor(Variable** const pArguments, FuncRef_t pFunc);

  public:
    /**
     *  @brief Functor Destructor
     *
     *  Frees all resources used by *this.
     */
    virtual ~Functor() = 0;

    /**
     *  @brief Basic constructor
     *
     *  This constructor has been deleted due to the need for
     *  construction of protected members by derived classes.
     */
    Functor() = delete;

    /**
     *  @brief Copy Constructor
     *
     *  This constructor has been deleted due to the need for
     *  construction of protected members by derived classes.
     */
    Functor(const Functor& f) = delete;

    /**
     *  @brief Move Constructor
     *
     *  This constructor has been deleted due to the need for
     *  construction of protected members by derived classes.
     */
    Functor(Functor&& f) = delete;

    /**
     *  @brief Copy Assignment
     *
     *  Copies pointers of arguments from the input parameter into *this.
     *  Remember to compile *this after a copy is performed in order to
     *  ensure program stability.
     *
     *  @param f
     *  A constant reference to a functor object with the same signature as
     *  *this.
     *
     *  @return a reference to *this.
     */
    Functor& operator=(const Functor& f);

    /**
     *  @brief Move Assignment
     *
     *  Moves pointers of arguments from the input parameter into *this.
     *  Remember to compile *this after a move is performed in order to
     *  ensure program stability.
     *
     *  @param f
     *  An r-value reference to a functor object with the same signature as
     *  *this.
     *
     *  @return a reference to *this.
     */
    Functor& operator=(Functor && f);

    /**
     *  @brief Get the function that has been assigned to run after *this.
     *
     *  Functors in the scripting system are linked to each other by
     *  pointers. When another function is assigned as the 'next' functor,
     *  then it will run after *this one has completed.
     *
     *  @return a pointer to the functor object which has been assigned to
     *  run after *this.
     */
    Functor* next_func_ptr();

    /**
     *  @brief Assign a functor to run after *this.
     *
     *  Functors in the scripting system are linked to each other by
     *  pointers. When another function is assigned as the 'next' functor,
     *  then it will run after *this one has completed.
     *
     *  @param f
     *  A pointer to a functor object. If the input parameter is NULL, then
     *  the function sequence will halt after this functor has completed
     *  its 'run()' method.
     */
    void next_func_ptr(Functor* const f);

    /**
     *  @brief Get *this object's scriptable type.
     *
     *  @return ScriptBaseType::SCRIPT_FUNC
     */
    ScriptBaseType base_type() const final;

    /**
     *  @brief Get the run-time-type information of *this functor.
     *
     *  This method will return a hash-code, indicating what type of
     *  functor *this is. The has code is unique to types of functors, not
     *  individual functor objects. This hash code is used by the global
     *  script factories in order to generate a functor at run-time.
     *
     *  @return hash_t
     *  A hash-code that will identify the RTTI information of *this.
     */
    virtual hash_t sub_type() const = 0;

    /**
     *  @brief Retrieve the number of arguments required to run *this.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @return An unsigned integral type, indicating how many arguments
     *  *this functor needs to run.
     */
    virtual unsigned num_args() const = 0;

    /**
     *  @brief Retrieve an arguments from *this.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @return A pointer to an internal variable that will be used to run
     *  *this.
     */
    Variable* arg(unsigned index) const;

    /**
     *  @brief Assign a variable to be functor argument.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @note Always remember to recompile your functors after manipulating
     *  functor arguments to ensure they don't crash at run-time. The
     *  scripting system provides the means to verify type information but
     *  does not perform these checks for you.
     *
     *  @param v
     *  A pointer to an variable object that will be used to run
     *  *this.
     */
    void arg(unsigned index, Variable* v);

    /**
     *  @brief Load functor data from an std::istream
     *
     *  A serialization method to will help reload data from a standard
     *  input stream. This method uses the overloaded input stream operator
     *  'std::istream::operator>> (T)' in order to load functor data into
     *  *this.
     *
     *  @param istr
     *  A reference to a std::istream object which contains functor data
     *  to be loaded into *this.
     *
     *  @param vlm
     *  A variable-loading factory that will be used to map variable data
     *  from the input stream into *this.
     *
     *  @param flm
     *  A function-loading factory that will be used to map functor data
     *  from the input stream into *this.
     *
     *  @return a boolean value that will determine if data was
     *  successfully loaded into *this (TRUE) or not (FALSE).
     */
    virtual bool load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm);

    /**
     *  @brief Save all data from *this into an std::ostream.
     *
     *  In this instance, functors, references to other functors, and
     *  variables are all saved using RTTI information. Scriptable objects
     *  are not saved, just their type-info. All data is mapped to/from the
     *  'loaderMap' objects in order to ensure cross-references are
     *  maintained when reloaded from an input stream.
     *
     *  @param ostr
     *  A reference to an std::ostream object.
     *
     * @return TRUE if the data was successfully saved, FALSE if not.
     */
    virtual bool save(std::ostream& ostr) const;

    /**
     *  @brief Compile/Verify function arguments
     *
     *  This method ensures that a functor is safe to operate at run-time.
     *  It uses custom RTTI information, combined with derived-type's
     *  template parameters to ensure that the proper arguments are placed
     *  in the correct order at run-time, before execution.
     *
     *  @note Because the scripting system does not manage the order in
     *  which you actually use arguments, please ensure that your
     *  functor-mapping code is consistent with the derived functor's
     *  template parameters.
     *
     *  @return A CompileInfo structure, containing the status code, argument
     *  index, and argument pointer of the last argument checked before this
     *  function returned. A successful compilation will have the returned
     *  CompileInfo structure's status set as CompileStatus::SUCCESS.
     */
    virtual CompileInfo compile() = 0;

    /**
     *  @brief Run a functor at run-time.
     */
    void run();
};



/**
 * @brief Functor Class Template Type
 *
 * The template functor type inherits all members and data from the functor
 * base class.
 */
template <hash_t hashId, typename... args_t>
class Functor_t final : public Functor
{
  private:

    /**
     *  @brief An array of pointers to scriptable variables.
     *
     *  This member contains reference pointers to scriptable variables
     *  which will be manipulated/used by *this.
     */
    Variable* parameters[sizeof...(args_t)] = {nullptr};

    /**
     *  @brief Implementation of the function to be run.
     *
     *  This static member is defined through the LS_SCRIPT_DEFINE_FUNC
     *  macro. The static func_impl member is what will actually be
     *  called when this function is run. Use this to define mappings of
     *  internal argument indices to actual native function parameters and
     *  return values.
     *
     *  @param pArgs
     *  A pointer to an array of pointers to scriptable variables (this
     *  will actually be the 'parameters' member in *this).
     */
    static void func_impl(Variable** const);

  public:
    /**
     *  @brief Destructor
     *
     *  Frees all resources used by *this.
     */
    virtual ~Functor_t() override;

    /**
     *  @brief Constructor
     *
     *  Initializes *this and all base classes.
     */
    Functor_t();

    /**
     *  @brief Copy Constructor
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     */
    Functor_t(const Functor_t& f);

    /**
     *  @brief Move Constructor
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     */
    Functor_t(Functor_t&& f);

    /**
     *  @brief Copy Assignment
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(const Functor_t&);

    /**
     *  @brief Move Assignment
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(Functor_t && );

    /**
     *  @brief Get the run-time-type information of *this functor.
     *
     *  This method will return a hash-code, indicating what type of
     *  functor *this is. The has code is unique to types of functors, not
     *  individual functor objects. This hash code is used by the global
     *  script factories in order to generate a functor at run-time.
     *
     *  @return hash_t
     *  A hash-code that identifies the RTTI information of *this.
     */
    hash_t sub_type() const final;

    /**
     *  @brief Retrieve the number of arguments required to run *this.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @return An unsigned integral type, indicating how many arguments
     *  *this functor needs to run.
     */
    virtual unsigned num_args() const final;

    /**
     *  @brief Load functor data from an std::istream
     *
     *  A serialization method to will help reload data from a standard
     *  input stream. This method uses the overloaded input stream operator
     *  'std::istream::operator>> (T)' in order to load functor data into
     *  *this.
     *
     *  @param istr
     *  A reference to a std::istream object which contains functor data
     *  to be loaded into *this.
     *
     *  @param vlm
     *  A variable-loading factory that will be used to map variable data
     *  from the input stream into *this.
     *
     *  @param flm
     *  A function-loading factory that will be used to map functor data
     *  from the input stream into *this.
     *
     *  @return a boolean value that will determine if data was
     *  successfully loaded into *this (TRUE) or not (FALSE).
     */
    bool load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm) final;

    /**
     *  @brief Save all data from *this into an std::ostream.
     *
     *  In this instance, functors, references to other functors, and
     *  variables are all saved using RTTI information. Scriptable objects
     *  are not saved, just their type-info. All data is mapped to/from the
     *  'loaderMap' objects in order to ensure cross-references are
     *  maintained when reloaded from an input stream.
     *
     *  @param ostr
     *  A reference to an std::ostream object.
     *
     * @return TRUE if the data was successfully saved, FALSE if not.
     */
    bool save(std::ostream& ostr) const final;

    /**
     *  @brief Compile/Verify function arguments
     *
     *  This method ensures that a functor is safe to operate at run-time.
     *  It uses custom RTTI information, combined with derived-type's
     *  template parameters to ensure that the proper arguments are placed
     *  in the correct order at run-time.
     *
     *  @note Because the scripting system does not manage the order in
     *  which you actually use arguments, please ensure that your
     *  functor-mapping code is consistent with the derived functor's
     *  template parameters.
     *
     *  @return TRUE if a functor managed to compile correctly, FALSE if
     *  not. If this function returns false, please check std::cerr for
     *  information on what went wrong. This will be changed in the future
     *  in order to provide more convenient error tracking.
     */
    CompileInfo compile() final;
};



/**
 * @brief Functor Template Type with void parameters
 */
template <hash_t hashId>
class Functor_t<hashId, void> final : public Functor
{
  private:

    /**
     *  @brief Implementation of the function to be run.
     *
     *  This static member is defined through the LS_SCRIPT_DEFINE_FUNC
     *  macro. The static func_impl member is what will actually be
     *  called when this function is run. Use this to define mappings of
     *  internal argument indices to actual native function parameters and
     *  return values.
     *
     *  @param pArgs
     *  A pointer to an array of pointers to scriptable variables (this
     *  will actually be the 'parameters' member in *this).
     */
    static void func_impl(Variable** const);

  public:
    /**
     *  @brief Destructor
     *
     *  Frees all resources used by *this.
     */
    virtual ~Functor_t() override;

    /**
     *  @brief Constructor
     *
     *  Initializes *this and all base classes.
     */
    Functor_t();

    /**
     *  @brief Copy Constructor
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     */
    Functor_t(const Functor_t& f);

    /**
     *  @brief Move Constructor
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     */
    Functor_t(Functor_t&& f);

    /**
     *  @brief Copy Assignment
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(const Functor_t& f);

    /**
     *  @brief Move Assignment
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(Functor_t&& f);

    /**
     *  @brief Get the run-time-type information of *this functor.
     *
     *  This method will return a hash-code, indicating what type of
     *  functor *this is. The has code is unique to types of functors, not
     *  individual functor objects. This hash code is used by the global
     *  script factories in order to generate a functor at run-time.
     *
     *  @return hash_t
     *  A hash-code that identifies the RTTI information of *this.
     */
    hash_t sub_type() const final;

    /**
     *  @brief Retrieve the number of arguments required to run *this.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @return An unsigned integral type, indicating how many arguments
     *  *this functor needs to run.
     */
    virtual unsigned num_args() const final;

    /**
     *  @brief Load functor data from an std::istream
     *
     *  A serialization method to will help reload data from a standard
     *  input stream. This method uses the overloaded input stream operator
     *  'std::istream::operator>> (T)' in order to load functor data into
     *  *this.
     *
     *  @param istr
     *  A reference to a std::istream object which contains functor data
     *  to be loaded into *this.
     *
     *  @param vlm
     *  A variable-loading factory that will be used to map variable data
     *  from the input stream into *this.
     *
     *  @param flm
     *  A function-loading factory that will be used to map functor data
     *  from the input stream into *this.
     *
     *  @return a boolean value that will determine if data was
     *  successfully loaded into *this (TRUE) or not (FALSE).
     */
    bool load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm) final;

    /**
     *  @brief Save all data from *this into an std::ostream.
     *
     *  In this instance, functors, references to other functors, and
     *  variables are all saved using RTTI information. Scriptable objects
     *  are not saved, just their type-info. All data is mapped to/from the
     *  'loaderMap' objects in order to ensure cross-references are
     *  maintained when reloaded from an input stream.
     *
     *  @param ostr
     *  A reference to an std::ostream object.
     *
     * @return TRUE if the data was successfully saved, FALSE if not.
     */
    bool save(std::ostream& ostr) const final;

    /**
     *  @brief Compile/Verify function arguments
     *
     *  This method ensures that a functor is safe to operate at run-time.
     *  It uses custom RTTI information, combined with derived-type's
     *  template parameters to ensure that the proper arguments are placed
     *  in the correct order at run-time, before execution.
     *
     *  @note Because the scripting system does not manage the order in
     *  which you actually use arguments, please ensure that your
     *  functor-mapping code is consistent with the derived functor's
     *  template parameters.
     *
     *  @return A CompileInfo structure, containing the status code, argument
     *  index, and argument pointer of the last argument checked before this
     *  function returned. A successful compilation will have the returned
     *  CompileInfo structure's status set as CompileStatus::SUCCESS.
     */
    CompileInfo compile() final;

};



/**
 * @brief Null Functor Template Type (no parameters)
 */
template <>
class LS_SCRIPT_API Functor_t<0, void> final : public Functor
{
  private:

    /**
     *  @brief Implementation of the function to be run.
     *
     *  This static member is defined through the LS_SCRIPT_DEFINE_FUNC
     *  macro. The static func_impl member is what will actually be
     *  called when this function is run. Use this to define mappings of
     *  internal argument indices to actual native function parameters and
     *  return values.
     *
     *  @param pArgs
     *  A pointer to an array of pointers to scriptable variables (this
     *  will actually be the 'parameters' member in *this).
     */
    static void func_impl(Variable** const);

  public:
    /**
     *  @brief Destructor
     *
     *  Frees all resources used by *this.
     */
    virtual ~Functor_t() override;

    /**
     *  @brief Constructor
     *
     *  Initializes *this and all base classes.
     */
    Functor_t();

    /**
     *  @brief Copy Constructor
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     */
    Functor_t(const Functor_t& f);

    /**
     *  @brief Move Constructor
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     */
    Functor_t(Functor_t&& f);

    /**
     *  @brief Copy Assignment
     *
     *  Copies all data from a functor of the same type into *this.
     *
     *  @param f
     *  A constant reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(const Functor_t& f);

    /**
     *  @brief Move Assignment
     *
     *  Moves all data from a functor of the same type into *this without
     *  performing any copies.
     *
     *  @param f
     *  An r-value reference to another functor of the same template type.
     *
     *  @return a reference to *this.
     */
    Functor_t& operator=(Functor_t && f);

    /**
     *  @brief Get the run-time-type information of *this functor.
     *
     *  This method will return a hash-code, indicating what type of
     *  functor *this is. The has code is unique to types of functors, not
     *  individual functor objects. This hash code is used by the global
     *  script factories in order to generate a functor at run-time.
     *
     *  @return hash_t
     *  A hash-code that identifies the RTTI information of *this.
     */
    hash_t sub_type() const final;

    /**
     *  @brief Retrieve the number of arguments required to run *this.
     *
     *  The number of arguments to the functor is not always the same
     *  number of arguments that *this functor's native function needs.
     *  Functor arguments can be mapped to return values, or to sequences
     *  of internal functions. It is up to the definition code to determine
     *  where functor arguments are mapped.
     *
     *  @return An unsigned integral type, indicating how many arguments
     *  *this functor needs to run.
     */
    virtual unsigned num_args() const final;

    /**
     *  @brief Load functor data from an std::istream
     *
     *  A serialization method to will help reload data from a standard
     *  input stream. This method uses the overloaded input stream operator
     *  'std::istream::operator>> (T)' in order to load functor data into
     *  *this.
     *
     *  @param istr
     *  A reference to a std::istream object which contains functor data
     *  to be loaded into *this.
     *
     *  @param vlm
     *  A variable-loading factory that will be used to map variable data
     *  from the input stream into *this.
     *
     *  @param flm
     *  A function-loading factory that will be used to map functor data
     *  from the input stream into *this.
     *
     *  @return a boolean value that will determine if data was
     *  successfully loaded into *this (TRUE) or not (FALSE).
     */
    bool load(std::istream& istr, VariableMap_t& vlm, FunctorMap_t& flm) final;

    /**
     *  @brief Save all data from *this into an std::ostream.
     *
     *  In this instance, functors, references to other functors, and
     *  variables are all saved using RTTI information. Scriptable objects
     *  are not saved, just their type-info. All data is mapped to/from the
     *  'loaderMap' objects in order to ensure cross-references are
     *  maintained when reloaded from an input stream.
     *
     *  @param ostr
     *  A reference to an std::ostream object.
     *
     * @return TRUE if the data was successfully saved, FALSE if not.
     */
    bool save(std::ostream& ostr) const final;

    /**
     *  @brief Compile/Verify function arguments
     *
     *  This method ensures that a functor is safe to operate at run-time.
     *  It uses custom RTTI information, combined with derived-type's
     *  template parameters to ensure that the proper arguments are placed
     *  in the correct order at run-time, before execution.
     *
     *  @note Because the scripting system does not manage the order in
     *  which you actually use arguments, please ensure that your
     *  functor-mapping code is consistent with the derived functor's
     *  template parameters.
     *
     *  @return A CompileInfo structure, containing the status code, argument
     *  index, and argument pointer of the last argument checked before this
     *  function returned. A successful compilation will have the returned
     *  CompileInfo structure's status set as CompileStatus::SUCCESS.
     */
    CompileInfo compile() final;
};



} // end script namespace
} // end ls namespace



#include "lightsky/script/generic/ScriptFunctor_impl.h"



/*-----------------------------------------------------------------------------
    Functor Utility Macros
-----------------------------------------------------------------------------*/
/**
 *  @brief Functor Declaration for Header Files
 *
 *  Use this macro in a header file in order to declare a functor and provide
 *  global access to the script type to be used.
 *
 *  For example, use it as follows:
 *      LS_SCRIPT_DECLARE_FUNC(add_nums, ScriptVar_int, ScriptVar_int);
 *      LS_SCRIPT_DECLARE_FUNC(strcat, ScriptVar_string, ScriptVar_string, ScriptVar_string);
 *
 *  The sample above will provide the declarations, hashes, and factories for
 *  two new functors. These functors themselves can be referenced like so:
 *      'ScriptFunc_addNums' and 'ScriptFunc_strcat'
 *
 *  The hashes can be referenced as such:
 *      'ScriptHash_addNums' and 'ScriptHash_strcat'
 *
 *  And the factory methods are accessible like this:
 *      ls::script::functor* pFunc;
 *      pFunc = ls::script::createScriptFunc(ScriptHash_addNums);
 *      ...
 *      delete pFunc;
 *
 *      pFunc = ls::script::createScriptFunc(ScriptHash_strcat);
 *      ...
 *      delete pFunc;
 */
#ifndef _LS_SCRIPT_DECLARE_FUNC_IMPL
    #define _LS_SCRIPT_DECLARE_FUNC_IMPL(LS_SCRIPT_API_TYPE, funcName, ...) \
        \
        enum : ls::script::hash_t { \
            ScriptHash_##funcName = LS_SCRIPT_HASH_FUNC(LS_STRINGIFY(funcName)) \
        }; \
        \
        typedef ls::script::Functor_t<ScriptHash_##funcName, __VA_ARGS__> ScriptFunc_##funcName; \
        \
        LS_SCRIPT_API_TYPE extern const ls::script::FuncFactory_t ScriptFactory_##funcName; \
        \
        template <> \
        LS_SCRIPT_API_TYPE void ScriptFunc_##funcName::func_impl(ls::script::Variable** const); \
        \
        LS_SCRIPT_EXTERN template class LS_SCRIPT_API_TYPE ls::script::Functor_t<ScriptHash_##funcName, __VA_ARGS__>
#endif /* _LS_SCRIPT_DECLARE_FUNC_IMPL */

#ifndef LS_SCRIPT_DECLARE_FUNC
    #define LS_SCRIPT_DECLARE_FUNC(funcName, ...) _LS_SCRIPT_DECLARE_FUNC_IMPL(LS_SCRIPT_STATIC_API, funcName, __VA_ARGS__)
#endif /* LS_SCRIPT_DECLARE_FUNC */

#ifndef LS_SCRIPT_DECLARE_FUNC_SHARED
    #define LS_SCRIPT_DECLARE_FUNC_SHARED(funcName, ...) _LS_SCRIPT_DECLARE_FUNC_IMPL(LS_SCRIPT_API, funcName, __VA_ARGS__)
#endif /* LS_SCRIPT_DECLARE_FUNC_SHARED */



/**
 *  @brief Function Definition for source files.
 *
 *  The definition of functors MUST define how arguments will be mapped to
 *  native functions. For example, to use this, simply write as follows:
 *
 *      LS_SCRIPT_DEFINE_FUNC(add_nums, ScriptVar_int, ScriptVar_int) {
 *          LS_SCRIPT_PARAM(0, int) += LS_SCRIPT_PARAM(1, int);
 *      };
 *
 *      LS_SCRIPT_DEFINE_FUNC(strcat, ScriptVar_string, ScriptVar_string, ScriptVar_string) {
 *          LS_SCRIPT_PARAM(0, std::string) = LS_SCRIPT_PARAM(1, std::string) + LS_SCRIPT_PARAM(2, std::string);
 *      };
 *
 *  Although a bit verbose, the process is actually quite painless once you get
 *  used to it. As shown above, functor arguments/parameters are accessible
 *  through both indices and types. In order to ensure that the proper types
 *  get used by a functor, make sure that the 'compile()' method is called and
 *  returns TRUE before running a functor.
 *
 *  Finally, defining a functor using this macro enables linkage to the global
 *  factory methods. A functor can now be spawned in the following manner:
 *      ls::script::functor* pFunc;
 *      pFunc = ls::script::createScriptFunc(ScriptHash_addNums);
 *      if (pFunc->compile()) {
 *          pFunc->run();
 *      }
 *      delete pFunc;
 *
 */
#ifndef _LS_SCRIPT_DEFINE_FUNC_IMPL
    #define _LS_SCRIPT_DEFINE_FUNC_IMPL(LS_SCRIPT_API_TYPE, funcName, ...) \
        template class LS_SCRIPT_API_TYPE ls::script::Functor_t<ScriptHash_##funcName, __VA_ARGS__>; \
        \
        LS_SCRIPT_API_TYPE const ls::script::FuncFactory_t ScriptFactory_##funcName = ls::script::register_func_factory( \
            ScriptHash_##funcName, []()->ls::script::Pointer_t<ls::script::Functor> { \
                return ls::script::Pointer_t<ls::script::Functor>{new(std::nothrow) ScriptFunc_##funcName{}}; \
            } \
        ); \
        \
        template <> \
        LS_SCRIPT_API_TYPE void ScriptFunc_##funcName::func_impl(ls::script::Variable** const pArgs)
#endif /* _LS_SCRIPT_DEFINE_FUNC_IMPL */

#ifndef LS_SCRIPT_DEFINE_FUNC
    #define LS_SCRIPT_DEFINE_FUNC(funcName, ...) _LS_SCRIPT_DEFINE_FUNC_IMPL(LS_SCRIPT_STATIC_API, funcName, __VA_ARGS__)
#endif /* LS_SCRIPT_DEFINE_FUNC */

#ifndef LS_SCRIPT_DEFINE_FUNC_SHARED
    #define LS_SCRIPT_DEFINE_FUNC_SHARED(funcName, ...) _LS_SCRIPT_DEFINE_FUNC_IMPL(LS_SCRIPT_EXPORT_API, funcName, __VA_ARGS__)
#endif /* LS_SCRIPT_DEFINE_FUNC_SHARED */



/**
 *  @brief Function Argument Accessibility
 *
 *  Use this macro to access arguments/parameters when defining the functor.
 *  For example, use it like this:
 *
 *      LS_SCRIPT_DEFINE_FUNC(add_nums, ScriptVar_int, ScriptVar_int) {
 *          LS_SCRIPT_PARAM(0, int) += LS_SCRIPT_PARAM(1, int);
 *      };
 *
 *      LS_SCRIPT_DEFINE_FUNC(strcat, std::string, std::, std::string) {
 *          LS_SCRIPT_PARAM(0, std::string) = LS_SCRIPT_PARAM(1, std::string) + LS_SCRIPT_PARAM(2, std::string);
 *      };
 */
#ifndef LS_SCRIPT_PARAM
    #define LS_SCRIPT_PARAM(index, varType) \
        static_cast<ls::script::Variable_t<LS_SCRIPT_HASH_FUNC(LS_STRINGIFY(varType)), varType>*>(pArgs[index])->data
#endif /* LS_SCRIPT_PARAM */



/*-----------------------------------------------------------------------------
    Built-In Types
-----------------------------------------------------------------------------*/
LS_SCRIPT_DECLARE_FUNC_SHARED(empty, void);



#endif  /* __LS_SCRIPT_FUNCTOR_H__ */
