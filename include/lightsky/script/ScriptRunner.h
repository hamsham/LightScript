/*
 * File:   scriptRunner.h
 * Author: hammy
 *
 * Created on February 25, 2015, 9:42 PM
 */

#ifndef __LS_SCRIPT_RUNNER_H__
#define __LS_SCRIPT_RUNNER_H__

#include "lightsky/script/Setup.h"



namespace ls
{
namespace script
{

class Functor;



/**
 * @brief The Base class for running script functions.
 *
 * This class iterates over script functions (after they have been compiled) in
 * a linked-list fashion, providing only the most basic functionality required
 * to run a series of script objects. It essentially calls the following in a
 * loop:
 *      while (some_functor != nullptr) {
 *          some_functor->run();
 *          some_functor = some_functor->getNextFunc();
 *      }
 *
 * It is strongly recommended to compile each of the functor objects before
 * running them through a scriptRunner in order to catch any potential errors
 * which may cause the program to crash.
 */
class LS_SCRIPT_API ScriptRunner{
    public:
    /**
     * @brief Destructor
     */
    virtual ~ScriptRunner();

    /**
     * @brief Run Constructor
     *
     * Directly calls "run(...)," then returns.
     *
     * No checking is done to see if functors are to be run in a loop.
     *
     * @param pEntryFunction
     * A pointer to the function which will be run first in a series of
     * linked functors.
     *
     * @param pSentinel
     * A pointer to the functor which will be used to signal the end of the
     * the script sequence. Since this functor is not run at all, it can be
     * left as NULL.
     */
    ScriptRunner(Functor * const pEntryFunction, const Functor * const pSentinel = nullptr);

    /**
     * @brief Constructor
     */
    ScriptRunner();

    /**
     * @brief Copy Constructor
     *
     * Copies all data from the input parameter into *this.
     *
     * @param s
     * A constant reference to another scriptRunner, who's data will be
     * copied into *this.
     */
    ScriptRunner(const ScriptRunner& s);

    /**
     * @brief Move Constructor
     *
     * Moves all data from the input parameter into *this without
     * performing any copies.
     *
     * @param s
     * An r-value reference to another scriptRunner, who's data will be
     * moved into *this.
     */
    ScriptRunner(ScriptRunner&& s);

    /**
     * @brief Copy Operator
     *
     * Copies all data from the input parameter into *this.
     *
     * @param s
     * A constant reference to another scriptRunner, who's data will be
     * copied into *this.
     *
     * @return
     * A reference to *this.
     */
    ScriptRunner& operator=(const ScriptRunner& s);

    /**
     * @brief Move Constructor
     *
     * Moves all data from the input parameter into *this without
     * performing any copies.
     *
     * @param s
     * An r-value reference to another scriptRunner, who's data will be
     * moved into *this.
     *
     * @return
     * A reference to *this.
     */
    ScriptRunner& operator=(ScriptRunner&& s);

    /**
     *
     * @brief Run all funtors linked together in a sequence.
     *
     * No checking is done to see if functors are to be run in a loop.
     *
     * @param pEntryFunction
     * A pointer to the function which will be run first in a series of
     * linked functors.
     *
     * @param pSentinel
     * A pointer to the functor which will be used to signal the end of the
     * the script sequence. Since this functor is not run at all, it can be
     * left as NULL.
     *
     * @return TRUE if the sequence was successfully run, or FALSE if an
     * error occurred.
     */
    virtual bool run(Functor * const pEntryFunction, const Functor * const pSentinel = nullptr);
};



} // end script namespace
} // end ls namespace

#endif  /* __LS_SCRIPT_RUNNER_H__ */
