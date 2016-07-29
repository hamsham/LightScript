
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
    "src/script/ScriptBasicVar.cpp"
    "src/script/ScriptFactory.cpp"
    "src/script/ScriptFunctor.cpp"
    "src/script/ScriptIO.cpp"
    "src/script/ScriptMath.cpp"
    "src/script/ScriptRunner.cpp"
    "src/script/ScriptSerializer.cpp"
    "src/script/ScriptVariable.cpp"
    "src/script/Scriptable.cpp"
    "src/script/Setup.cpp"
)



# -------------------------------------
# Library Setup
# -------------------------------------
# LS Scrip must be built as a shared library to support
# global variables across multiple libraries and processes.
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
# Library Tests
# -------------------------------------
set(LS_BUILD_SCRIPT_TESTS TRUE CACHE BOOL "Build tests for the LightScript library.")

if(LS_BUILD_SCRIPT_TESTS)
    add_subdirectory("tests")
endif()

