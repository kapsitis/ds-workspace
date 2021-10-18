#!/bin/bash

# Remove the last slash character, if it exists
targetDir=${1%/}

cp run-tests-lab2-2.sh ${targetDir}/

# Create target directory, if it does not exist
mkdir -p $1/lab2-2/
# Copy CMake's build-file, tests and their expected results
cp lab2-2/CMakeLists.txt ${targetDir}/lab2-2/
cp lab2-2/test*.txt ${targetDir}/lab2-2/
cp lab2-2/expected*.txt ${targetDir}/lab2-2/

# The subdirectory $1/lab2-2/src should already contain 3 files:
# ${targetDir}/lab2-2/src/CircularList.cpp
# ${targetDir}/lab2-2/src/CircularList.h
# ${targetDir}/lab2-2/src/CircularListMain.cpp

# Create target directory, if it does not exist
mkdir -p ${targetDir}/lab2-2/test
# Copy (or overwrite) Catch2 unit-test related files
cp lab2-2/test/catch.hpp ${targetDir}/lab2-2/test/
cp lab2-2/test/main.cpp ${targetDir}/lab2-2/test/
cp lab2-2/test/TestCircularList.cpp ${targetDir}/lab2-2/test/

# Copy Catch2 integration with CMake's CTest module.
mkdir -p ${targetDir}/lab2-2/cmake/Modules/
#cp lab2-1/cmake/Modules/ParseAndAddCatchTests.cmake ${targetDir}/cmake/Modules/


