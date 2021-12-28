#!/bin/bash

#echo "Pull the submitted files from GitHub"
#Better do this command manually in the place you want - authentication is easier.
#git clone git@github.com:username/ds-workspace-username.git



#######################################################
## Run tests in lab5-1 directory.                    ##
#######################################################

# Remove GRADES file (will append to it later on)
rm -f GRADES-LAB5-1.txt

cd lab5-1
rm -fr build

# There are 7 testcases (tests with their expected results)
declare -a tsts=( "01" "02" "03" "04" "05")

echo "-----------------------------"
echo "******** lab5-1/src  ********"
echo "-----------------------------"
echo "Compiling..."

mkdir build
make all

cd build
#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
#cmake --build . --config Release

# If executable exists:
if [ -f "text_analysis_main" ]
then
  for i in "${tsts[@]}"
  do
    echo "----- test${i}.txt -----"
    # Run the test, record output in file test.MM.out.txt (wait for 10 seconds)
    timeout 10 ./text_analysis_main < ../test${i}.txt > ../test${i}.out.txt
    if [ $? == "0" ]
    then      
      # Add one extra newline at the end of the file (just in case if it is missing)
      echo >> test${i}.out.txt
      # Ignore case (-i), ignore extra whitespace (-w), ignore blank lines (-B).
      diff -i -w -B ../test${i}.out.txt ../expected${i}.txt
      # If the diff command found that two files are the same
      if [ $? == "0" ]
      then
        echo "Test${i}: PASS" >> ../../GRADES-LAB5-1.txt
      else
        echo "Test${i}: FAIL" >> ../../GRADES-LAB5-1.txt
      fi
    else
      echo "Test${i}: TIMEOUT" >> ../../GRADES-LAB5-1.txt
    fi        
  done
else 
  # Executable text_analysis_main not built.
  echo "text_analysis_main did not build"
  for i in "${tsts[@]}"
  do
    echo "Test${i}: ERROR" >> ../../GRADES-LAB5-1.txt
  done
fi
echo "------------------------"






