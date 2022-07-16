cmake_minimum_required(VERSION 3.14)
project(leetCode)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS "src/*.test.cc")

include(GoogleTest)
foreach (_sourceFile ${SOURCES})
    get_filename_component(_name ${_sourceFile} NAME_WE)
    add_executable(
            ${_name}
            ${_sourceFile}
    )
    target_link_libraries(
            ${_name}
            gtest_main
    )
    gtest_discover_tests(${_name})
endforeach ()

