cmake_minimum_required(VERSION 2.8)

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
add_library("${OUTPUT_NAME}" SHARED "${LS_SCRIPT_SOURCES}")


# -------------------------------------
# Dependency Setup
# -------------------------------------
set(LS_SCRIPT_DEPS
    "${LIBRARY_OUTPUT_PATH}/${LS_STATIC_LIB_PREFIX}lssetup${LS_STATIC_LIB_SUFFIX}"
    "${LIBRARY_OUTPUT_PATH}/${LS_STATIC_LIB_PREFIX}lsutils${LS_STATIC_LIB_SUFFIX}"
    "${LIBRARY_OUTPUT_PATH}/${LS_STATIC_LIB_PREFIX}lsmath${LS_STATIC_LIB_SUFFIX}"
)

target_link_libraries("${OUTPUT_NAME}" ${LS_SCRIPT_DEPS})



# -------------------------------------
# Library Setup
# -------------------------------------
add_dependencies("${OUTPUT_NAME}" lssetup lsutils lsmath)



# -------------------------------------
# Library Installation Setup
# -------------------------------------
install(TARGETS "${OUTPUT_NAME}" LIBRARY DESTINATION lib)
