
# -------------------------------------
# Project Setup
# -------------------------------------
project(LightScript CXX)
set(OUTPUT_NAME lsscript)



# -------------------------------------
# Source Paths
# -------------------------------------
set(LS_SCRIPT_HEADERS
    include/lightsky/script/generic/ScriptFunctor_impl.h
    include/lightsky/script/generic/ScriptVariable_impl.h
    include/lightsky/script/Script.h
    include/lightsky/script/Scriptable.h
    include/lightsky/script/ScriptBasicVar.h
    include/lightsky/script/ScriptFactory.h
    include/lightsky/script/ScriptFunctor.h
    include/lightsky/script/ScriptIO.h
    include/lightsky/script/ScriptMath.h
    include/lightsky/script/ScriptRunner.h
    include/lightsky/script/ScriptSerializer.h
    include/lightsky/script/ScriptVariable.h
    include/lightsky/script/Setup.h
)

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

add_library(${OUTPUT_NAME} SHARED ${LS_SCRIPT_HEADERS} ${LS_SCRIPT_SOURCES})

target_include_directories(${OUTPUT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

# Dependencies
target_link_libraries(${OUTPUT_NAME} LightSky::Math LightSky::Utils LightSky::Setup)



# -------------------------------------
# Library Installation Setup
# -------------------------------------
install(TARGETS ${OUTPUT_NAME}
    EXPORT LightScript
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/lightsky/script DESTINATION include/lightsky)

install(EXPORT LightScript
    FILE LightScript.cmake
    NAMESPACE LightSky::
    DESTINATION lib/cmake/LightSky
)

export(EXPORT LightScript NAMESPACE LightSky::)
add_library(LightSky::Script ALIAS lsscript)



# -------------------------------------
# Unit Tests
# -------------------------------------
option(LS_BUILD_SCRIPT_TESTS "Build tests for the LightScript library." ON)

if(LS_BUILD_SCRIPT_TESTS)
    add_subdirectory(tests)
endif()
