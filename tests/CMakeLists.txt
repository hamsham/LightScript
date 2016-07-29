
# -------------------------------------
# Project Setup
# -------------------------------------
project(ls_script_tests CXX)



# -------------------------------------
# Include Paths
# -------------------------------------
include_directories(".")



# -------------------------------------
# Compiler Options
# -------------------------------------
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU"
    OR
    CMAKE_CXX_COMPILER_ID MATCHES "Clang"
)
    if (NOT APPLE)
        set(LS_SCRIPT_TEST_BUILD_FLAGS "-pthread")
    endif()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LS_SCRIPT_TEST_BUILD_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LS_SCRIPT_TEST_BUILD_FLAGS}")
    
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")

else()

    message(FATAL_ERROR "Your compiler is currently unsupported.")

endif()



# -------------------------------------
# Dependency Setup
# -------------------------------------
set(
    LS_SCRIPT_TEST_DEPS
    ls_script
    ls_math
    ls_utils
    ls_setup
)



# -------------------------------------
# Source Paths
# -------------------------------------
set(LS_SCRIPT_TEST_COMMON_SOURCES)



# -------------------------------------
# Executable Setup
# -------------------------------------
function(LS_SCRIPT_TEST_BLT testname)
    add_executable(${testname} "${testname}.cpp")
    add_dependencies(${testname} ${LS_SCRIPT_TEST_DEPS})
    target_link_libraries(${testname} ${LS_SCRIPT_TEST_DEPS})
endfunction(LS_SCRIPT_TEST_BLT)

LS_SCRIPT_TEST_BLT(lsscript_benchmark)
LS_SCRIPT_TEST_BLT(lsscript_sequencing)
LS_SCRIPT_TEST_BLT(lsscript_serializing)
