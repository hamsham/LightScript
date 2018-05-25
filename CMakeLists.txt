
# -------------------------------------
# Project Setup
# -------------------------------------
project(LightScript CXX)
set(OUTPUT_NAME lsscript)



# -------------------------------------
# Source Paths
# -------------------------------------
include_directories("include")

set(LS_SCRIPT_SOURCES
    src/ScriptBasicVar.cpp
    src/ScriptFactory.cpp
    src/ScriptFunctor.cpp
    src/ScriptIO.cpp
    src/ScriptMath.cpp
    src/ScriptRunner.cpp
    src/ScriptSerializer.cpp
    src/ScriptVariable.cpp
    src/Scriptable.cpp
    src/Setup.cpp
)



# -------------------------------------
# Library Setup
# -------------------------------------
# LS Script must be built as a shared library to support
# global variables across multiple libraries and processes.
add_definitions(-DLS_BUILD_SHARED -DLS_SHARED)
add_library("${OUTPUT_NAME}" SHARED "${LS_SCRIPT_SOURCES}")


# -------------------------------------
# Dependency Setup
# -------------------------------------
set(LS_SCRIPT_DEPS
    lssetup
    lsutils
    lsmath
    lsgame
)

target_link_libraries("${OUTPUT_NAME}" ${LS_SCRIPT_DEPS})



# -------------------------------------
# Library Setup
# -------------------------------------
add_dependencies("${OUTPUT_NAME}" lssetup lsutils lsmath)



# -------------------------------------
# Library Installation Setup
# -------------------------------------
install(TARGETS "${OUTPUT_NAME}"
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/lightsky/script DESTINATION include/lightsky)



# -------------------------------------
# Library Tests
# -------------------------------------
set(LS_BUILD_SCRIPT_TESTS TRUE CACHE BOOL "Build tests for the LightScript library.")

if(LS_BUILD_SCRIPT_TESTS)
    add_subdirectory("tests")
endif()

