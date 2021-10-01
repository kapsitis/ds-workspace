#!/bin/bash

# Remove the last slash character, if it exists
targetDir=${1%/}

cp run-tests-lab2-1.sh ${targetDir}/

# Create target directory, if it does not exist
mkdir -p $1/lab2-1/
# Copy CMake's build-file, tests and their expected results
cp lab2-1/CMakeLists.txt ${targetDir}/lab2-1/
cp lab2-1/test*.txt ${targetDir}/lab2-1/
cp lab2-1/expected*.txt ${targetDir}/lab2-1/

# The subdirectory $1/lab2-1/src should already contain 3 files:
# ${targetDir}/lab2-1/src/CircularList.cpp
# ${targetDir}/lab2-1/src/CircularList.h
# ${targetDir}/lab2-1/src/CircularListMain.cpp

# Create target directory, if it does not exist
mkdir -p ${targetDir}/lab2-1/tests
# Copy (or overwrite) Catch2 unit-test related files
cp lab2-1/test/catch.hpp ${targetDir}/lab2-1/test/
cp lab2-1/test/main.cpp ${targetDir}/lab2-1/test/
cp lab2-1/test/test_CircularList.cpp ${targetDir}/lab2-1/test/

# Copy Catch2 integration with CMake's CTest module.
mkdir -p ${targetDir}/lab2-1/cmake/Modules/
#cp lab2-1/cmake/Modules/ParseAndAddCatchTests.cmake ${targetDir}/cmake/Modules/


