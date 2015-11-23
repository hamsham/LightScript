
# -------------------------------------
# Project Setup
# -------------------------------------
project(LightScript CXX)
set(OUTPUT_NAME lsscript)



# -------------------------------------
# Compiler Options
# -------------------------------------
set(LS_OLD_C_FLAGS "${CMAKE_C_FLAGS}")
set(LS_OLD_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU"
    OR
    CMAKE_CXX_COMPILER_ID MATCHES "Clang"
)
    if(WIN32)
        set(LS_SCRIPT_COMPILER_FLAGS "-shared -Wl,--out-implib,lib${OUTPUT_NAME}.a")
    endif()

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LS_SCRIPT_COMPILER_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LS_SCRIPT_COMPILER_FLAGS}")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")

    set(LS_SCRIPT_COMPILER_FLAGS "/DLL")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LS_SCRIPT_COMPILER_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LS_SCRIPT_COMPILER_FLAGS}")

else()

    message(FATAL_ERROR "Your compiler is currently unsupported: ${CMAKE_CXX_COMPILER_ID}")
endif()



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
    lssetup
    lsutils
    lsmath
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
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(DIRECTORY include/lightsky/script DESTINATION include/lightsky)



# -------------------------------------
# Library Tests
# -------------------------------------
set(CMAKE_C_FLAGS "${LS_OLD_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${LS_OLD_CXX_FLAGS}")

set(LS_BUILD_SCRIPT_TESTS TRUE CACHE BOOL "Build tests for the LightScript library.")

if(LS_BUILD_SCRIPT_TESTS)
    add_subdirectory("tests")
endif()
