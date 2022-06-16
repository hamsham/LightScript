
# -------------------------------------
# Project Setup
# -------------------------------------
project(ls_script_tests CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)



# -------------------------------------
# Executable Setup
# -------------------------------------
function(add_lsscript_executable testname)
    add_executable(${testname} "${testname}.cpp")
    target_link_libraries(${testname} LightSky::Script Threads::Threads)
endfunction(add_lsscript_executable)

add_lsscript_executable(lsscript_benchmark)
add_lsscript_executable(lsscript_sequencing)
add_lsscript_executable(lsscript_serializing)
