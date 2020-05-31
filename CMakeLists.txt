option(BUILD_OFFLINE "Build offline" OFF)

cmake_minimum_required(VERSION 3.7.2)
project (leetCode)

set(CMAKE_CXX_STANDARD 17)

set(source_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(target_dir ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${target_dir})


# Skip download & update?
if(${BUILD_OFFLINE})
    set(gtest_BUILD_OFFLINE 1)
else()
    set(gtest_BUILD_OFFLINE 0)
endif()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}"
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
    "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

file(GLOB headers RELATIVE "${source_dir}" "${source_dir}/*.test.h")

foreach(header_file ${headers})
    set(CMAKE_CONFIGURABLE_FILE_CONTENT
        "${CMAKE_CONFIGURABLE_FILE_CONTENT}#include \"${header_file}\"\n")

    string(REPLACE ".test.h" "" file_name "${header_file}")
endforeach()

set(test_file "run-tests.cpp")
configure_file("${source_dir}/${test_file}.in"
    "${source_dir}/${test_file}"
    @ONLY
)

file(GLOB h_files "${source_dir}/*.h")

add_executable(run-test "${source_dir}/${test_file}" "${h_files}")
target_link_libraries(run-test gtest_main)

unset(CMAKE_CONFIGURABLE_FILE_CONTENT)
