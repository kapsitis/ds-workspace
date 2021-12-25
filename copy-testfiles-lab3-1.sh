#!/bin/bash

if [[ $# -eq 0 ]] ; then
    echo 'specify (relative) student workspace directory'
    exit 0
fi

# Remove the last slash character, if it exists
targetDir=${1%/}

cp run-plain-lab3-1.sh ${targetDir}/
cp run-plain-lab3-2.sh ${targetDir}/

# Create target directory, if it does not exist
# mkdir -p $1/lab3-1/

# Create target directory, if it does not exist
mkdir -p $1/lab3-1/
mkdir -p $1/lab3-2/
# Copy CMake's build-file, tests and their expected results
cp lab3-1/CMakeLists.txt ${targetDir}/lab3-1/
cp lab3-1/test*.txt ${targetDir}/lab3-1/
cp lab3-1/expected*.txt ${targetDir}/lab3-1/
cp lab3-1/Makefile ${targetDir}/lab3-1/

cp lab3-1/CMakeLists.txt ${targetDir}/lab3-2/
cp lab3-1/test*.txt ${targetDir}/lab3-2/
cp lab3-1/expected*.txt ${targetDir}/lab3-2/
cp lab3-1/Makefile ${targetDir}/lab3-2/


