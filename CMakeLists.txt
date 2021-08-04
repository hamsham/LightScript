
# #####################################
# Project Setup
# #####################################
cmake_minimum_required(VERSION 3.18)

project(LightScript CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(OUTPUT_NAME lsscript)



# -------------------------------------
# Target Setup
# -------------------------------------
set(CMAKE_PREFER_PTHREAD)
find_package(Threads REQUIRED)



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
add_library(${OUTPUT_NAME} SHARED ${LS_SCRIPT_HEADERS} ${LS_SCRIPT_SOURCES})

# LS Script must be built as a shared library to support
# global variables across multiple libraries and processes.
target_compile_definitions(${OUTPUT_NAME} PRIVATE -DLS_BUILD_SHARED -DLS_SHARED)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${OUTPUT_NAME}
        PRIVATE
            -Wall
            -Werror
            -Wextra
            -pedantic
            -pedantic-errors
            -Wno-implicit-fallthrough
            -Wno-pessimizing-move
    )

    # Some attributes get incorrectly parsed during macro expansion of templates
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        target_compile_options(${OUTPUT_NAME} PRIVATE -Wno-attributes)
    endif()
endif()

target_include_directories(${OUTPUT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)



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
