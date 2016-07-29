/*
 * File:   scriptable.h
 * Author: Miles Lacey
 */

#ifndef __LS_SCRIPT_SCRIPTABLE_H__
#define __LS_SCRIPT_SCRIPTABLE_H__

#include <iostream>

#include "ls/utils/Hash.h"
#include "ls/script/Setup.h"

namespace ls {
namespace script {



/**----------------------------------------------------------------------------
    @brief Script Object Base Class

    Defines all common interfaces for derived types.
-----------------------------------------------------------------------------*/
class LS_API Scriptable {
  public:
    /**
     *  @brief
     */
    virtual ~Scriptable() = 0;

    /**
     *  @brief Constructor
     *  Does nothing as there are no members in *this.
     */
    Scriptable();

    /**
     *  @brief Copy Constructor
     *  Does nothing as there are no members in *this.
     */
    Scriptable(const Scriptable&);

    /**
     *  @brief Move Constructor
     *  Does nothing as there are no members in *this.
     */
    Scriptable(Scriptable&&);

    /**
     *  @brief Copy Operator
     *  Does nothing as there are no members in *this.
     *
     *  @return a reference to *this.
     */
    Scriptable& operator=(const Scriptable&);

    /**
     *  @brief Move Operator
     *  Does nothing as there are no members in *this.
     *
     *  @return a reference to *this.
     */
    Scriptable& operator=(Scriptable&&);

    /**
     *  @brief getScriptType
     *  Retrieve the type of scripting object *this is.
     *
     *  @return script_base_t
     *  A hash code indicating the type of scripting object *this is. This
     *  may return a hash code which determines that this is either a
     *  scripting variable or scripting function.
     */
    virtual script_base_t get_script_type() const = 0;

    /**
     *  @brief getScriptSubType
     *  Used to determine the run-time-type information about the type of
     *  scripting object that *this is.
     *
     *  @return hash_t
     *  A hash code that indicates the specific type of object that *this
     *  is at run-time.
     */
    virtual hash_t get_script_subtype() const = 0;

    /**
     *  @brief load
     *  A serialization method that will help in reloading data from a
     *  standard input stream.
     *
     *  @param istr
     *  A reference to a std::istream object which contains scripting data
     *  to be loaded into *this.
     *
     *  @param varLoader
     *  A variable-loading factory that will be used to map variable data
     *  from the input stream into *this.
     *
     *  @param funcLoader
     *  A function-loading factory that will be used to map functor data
     *  from the input stream into *this.
     *
     *  @return a boolean value that will determine if data was
     *  successfully loaded into *this (TRUE) or not (FALSE).
     */
    virtual bool load(std::istream& istr, VariableMap_t& varLoader, FunctorMap_t& funcLoader) = 0;

    /**
     *  @brief save
     *  Sends all data from *this into an std::ostream.
     *
     *  @param ostr
     *  A reference to an std::ostream object. Each scriptable object will
     *  have its own save method.
     *
     * @return TRUE if the data was successfully saved, FALSE if not.
     */
    virtual bool save(std::ostream& ostr) const = 0;
};

} // end script namespace
} // end ls namespace

#endif /* __LS_SCRIPT_SCRIPTABLE_H__ */
