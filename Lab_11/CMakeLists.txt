# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(Sorting)

# C++ minimum version required
set(CMAKE_CXX_STANDARD 17)

# add an executable target
add_executable(main src/main.cpp "src/vector.cpp")

# for additional headers available for including from the sources of all targets
# include_directories(includes)

# add a library target
# add_library(<LIBRARY-TARGET-NAME> STATIC <SOURCES>)

# linking the library
# find_library(<VAR> <LIBRARY-TARGET-NAME> lib)
# target_link_libraries(<EXEC-TARGET-NAME> LINK_PUBLIC ${<VAR>})

# fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add an executable test target
add_executable(sort_test "tests/vector_test.cpp" "src/vector.cpp")

# link the Google Test library
target_link_libraries(sort_test gtest_main)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(sort_test)

