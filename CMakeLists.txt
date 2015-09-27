cmake_minimum_required(VERSION 2.8)

# -------------------------------------
# Project Setup
# -------------------------------------
project(LightScript CXX)
set(OUTPUT_NAME lsscript)



# -------------------------------------
# Compiler Options
# -------------------------------------
if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU"
    OR
    "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"
)
    set(warnings "-Wall -Werror -Wextra -pedantic -pedantic-errors")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 ${warnings}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${warnings}")

    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG} -std=c99 ${warnings}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 ${warnings}")

    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE} -std=c99 ${warnings}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 ${warnings}")
else()
    message(FATAL_ERROR "Your compiler is currently unsupported.")
endif()



# -------------------------------------
# Source Paths
# -------------------------------------
include_directories("include")



# -------------------------------------
# Library Setup
# -------------------------------------
add_library("${OUTPUT_NAME}" STATIC
            "src/script/scriptBasicVar.cpp"
            "src/script/scriptFactory.cpp"
            "src/script/scriptFunctor.cpp"
            "src/script/scriptIO.cpp"
            "src/script/scriptMath.cpp"
            "src/script/scriptRunner.cpp"
            "src/script/scriptSerializer.cpp"
            "src/script/scriptVariable.cpp"
            "src/script/scriptable.cpp"
            "src/script/setup.cpp"
)



# -------------------------------------
# Library Installation Setup
# -------------------------------------
install(TARGETS "${OUTPUT_NAME}" ARCHIVE DESTINATION lib)
install(DIRECTORY include/lightsky/script DESTINATION include/lightsky)
