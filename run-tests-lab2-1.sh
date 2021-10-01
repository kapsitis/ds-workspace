#!/bin/bash

#echo "Pull the submitted files from GitHub"
#Better do this command manually in the place you want - authentication is easier.
#git clone git@github.com:username/ds-workspace-username.git



# These are the source files we expect to see:
declare -a infiles=("lab2-1/src/CircularList.cpp" 
    "lab2-1/src/CircularList.h"
    "lab2-1/src/CircularListMain.cpp")

echo "Checking for missing source files..." 
# Boolean flag, if there were any missing *.cpp files
missingFiles=0
for i in "${infiles[@]}"
do 
  if [ ! -f "${i}" ]; then
    echo "ERROR: File ${i} does not exist" 
    missingFiles=1
  fi
done
if [[ "$missingFiles" -eq "0" ]]; then
  echo "Check finished. No missing files"
else 
  echo "Check finished. Please copy the missing files in their locations."
  echo "The grading script may lead to unpredictable results, if required files are missing."
  exit 1
fi 


#######################################################
## Run tests in lab1-1 directory.                    ##
#######################################################

# Remove GRADES file (will append to it later on)
rm -f GRADES-LAB2-1.txt

cd lab2-1
rm -fr build

# There are 7 testcases (tests with their expected results)
declare -a tsts=( "01" "02" "03" "04" "05" "06" "07")

echo "-----------------------------"
echo "******** lab2-1/src  ********"
echo "-----------------------------"
echo "Compiling..."

mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Release

# If executable exists:
if [ -f "circlist_main" ]
then
  for i in "${tsts[@]}"
  do
    echo "----- test${i}.txt -----"
    # Run the test, record output in file test.MM.out.txt (wait for 10 seconds)
    timeout 10 ./circlist_main < ../test${i}.txt > ../test${i}.out.txt
    if [ $? == "0" ]
    then      
      # Add one extra newline at the end of the file (just in case if it is missing)
      echo >> test${i}.out.txt
      # Ignore case (-i), ignore extra whitespace (-w), ignore blank lines (-B).
      diff -i -w -B ../test${i}.out.txt ../expected${i}.txt
      # If the diff command found that two files are the same
      if [ $? == "0" ]
      then
        echo "Test${i}: PASS" >> ../../GRADES-LAB2-1.txt
      else
        echo "Test${i}: FAIL" >> ../../GRADES-LAB2-1.txt
      fi
    else
      echo "Test${i}: TIMEOUT" >> ../../GRADES-LAB2-1.txt
    fi        
  done
else 
  # Executable circlist_main not built.
  echo "circlist_main did not build"
  for i in "${tsts[@]}"
  do
    echo "Test${i}: ERROR" >> ../../GRADES-LAB2-1.txt
  done
fi
echo "------------------------"
echo 


echo "Cleaning up..."
#sudo rm -fr ds-workspace-username/
echo
echo "Done!"


