#!/bin/bash

if [[ $# -eq 0 ]] ; then
    echo 'specify (relative) student workspace directory'
    exit 0
fi

# Remove the last slash character, if it exists
targetDir=${1%/}

cp run-plain-lab5.sh ${targetDir}/

# Create target directory, if it does not exist
mkdir -p $1/lab5-1/

# Copy CMake's build-file, tests and their expected results
cp lab5-1/CMakeLists.txt ${targetDir}/lab5-1/
cp lab5-1/test*.txt ${targetDir}/lab5-1/
#cp lab5-1/expected*.txt ${targetDir}/lab5-1/
cp lab5-1/Makefile ${targetDir}/lab5-1/
cp -r lab5-1/samples01 ${targetDir}/lab5-1/
cp -r lab5-1/samples02 ${targetDir}/lab5-1/
cp -r lab5-1/samples03 ${targetDir}/lab5-1/
cp -r lab5-1/samples04 ${targetDir}/lab5-1/
cp -r lab5-1/samples05 ${targetDir}/lab5-1/

