#!/bin/bash

if [[ $# -eq 0 ]] ; then
    echo 'specify (relative) student workspace directory'
    exit 0
fi

# Remove the last slash character, if it exists
targetDir=${1%/}

cp run-plain-lab4.sh ${targetDir}/

# Create target directory, if it does not exist
# mkdir -p $1/lab3-1/

# Create target directory, if it does not exist
mkdir -p $1/lab4-1/

# Copy CMake's build-file, tests and their expected results
cp lab4-1/CMakeLists.txt ${targetDir}/lab4-1/
cp lab4-1/test*.txt ${targetDir}/lab4-1/
cp lab4-1/expected*.txt ${targetDir}/lab4-1/
cp lab4-1/Makefile ${targetDir}/lab4-1/


