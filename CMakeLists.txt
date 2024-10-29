cmake_minimum_required(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})

# Set the project name to the repository name
project(${CMAKE_CURRENT_SOURCE_DIR})
# Set the C++ standard version
set(CMAKE_CXX_STANDARD 17)
# Enforce that the compiler must support this standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Set -g flag in order for degugger to stop at breakpoints
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
# Set the directory of test sources
set(TEST_DIR "test")

# Collect test sources
file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.cpp")
# Add an executable for tests
foreach(test_file ${TEST_SOURCES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_executable(${test_name} ${test_file})
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
# Enable testing
enable_testing()
