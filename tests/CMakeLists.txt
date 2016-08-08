
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
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if (NOT APPLE)
        add_definitions("-pthread")
    endif()
endif()



# -------------------------------------
# Dependency Setup
# -------------------------------------
set(
    LS_SCRIPT_TEST_DEPS
    lsscript
    lsmath
    lsutils
    lssetup
)



# -------------------------------------
# Source Paths
# -------------------------------------
set(LS_SCRIPT_TEST_COMMON_SOURCES)



# -------------------------------------
# Executable Setup
# -------------------------------------
function(LS_SCRIPT_ADD_TEST testname)
    add_executable(${testname} "${testname}.cpp")
    add_dependencies(${testname} ${LS_SCRIPT_TEST_DEPS})
    target_link_libraries(${testname} ${LS_SCRIPT_TEST_DEPS})
endfunction(LS_SCRIPT_ADD_TEST)

LS_SCRIPT_ADD_TEST(lsscript_benchmark)
LS_SCRIPT_ADD_TEST(lsscript_sequencing)
LS_SCRIPT_ADD_TEST(lsscript_serializing)
