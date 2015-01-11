# CMake configuration
cmake_minimum_required(VERSION 2.8)

# Build configuration
project(json CXX)
enable_testing()


# Compiler configuration
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
include_directories(.)

# Products
add_library(
json
jsonarray.cpp
jsonarray.hpp
jsonobject.cpp
jsonobject.hpp
jsonvalue.cpp
jsonvalue.hpp
visitor.cpp
visitor.hpp
printvisitor.cpp
printvisitor.hpp
fileoutputvisitor.cpp
fileoutputvisitor.hpp
primitives/jsonbool.cpp
primitives/jsonbool.hpp
primitives/jsonnull.cpp
primitives/jsonnull.hpp
primitives/jsonnumber.cpp
primitives/jsonnumber.hpp
primitives/jsonstring.cpp
primitives/jsonstring.hpp
)

# Add unit tests
add_executable(json.test main.cpp)

target_link_libraries(json.test json)
add_test(test.json.test json.test)

# Submission

# The make_manifest macro creates targets that generate a PDF of
# your code for grading.
macro(make_manifest)
  # Complete the paths to all files
  set(files "")
  foreach(i ${ARGV})
    set(f ${CMAKE_CURRENT_SOURCE_DIR}/${i})
    list(APPEND files ${f})
  endforeach()

  # Generate the manifest target
  add_custom_target(manifest
    COMMAND a2ps -Afill -o manifest.ps ${files}
    COMMAND ps2pdf manifest.ps)
endmacro()


make_manifest(
main.cpp 
jsonarray.cpp
jsonarray.hpp
jsonobject.cpp
jsonobject.hpp
jsonvalue.cpp
jsonvalue.hpp
printvisitor.cpp
printvisitor.hpp
visitor.cpp
visitor.hpp
fileoutputvisitor.cpp
fileoutputvisitor.hpp
primitives/jsonbool.cpp
primitives/jsonbool.hpp
primitives/jsonnull.cpp
primitives/jsonnull.hpp
primitives/jsonnumber.cpp
primitives/jsonnumber.hpp
primitives/jsonstring.cpp
primitives/jsonstring.hpp)
