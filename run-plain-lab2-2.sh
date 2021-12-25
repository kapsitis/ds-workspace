#!/bin/bash

#echo "Pull the submitted files from GitHub"
#Better do this command manually in the place you want - authentication is easier.
#git clone git@github.com:username/ds-workspace-username.git



#######################################################
## Run tests in lab2-2 directory.                    ##
#######################################################

# Remove GRADES file (will append to it later on)
rm -f GRADES-LAB2-2.txt

cd lab2-2
rm -fr build

# There are 7 testcases (tests with their expected results)
declare -a tsts=( "01" "02" "03" "04" "05")

echo "-----------------------------"
echo "******** lab2-2/src  ********"
echo "-----------------------------"
echo "Compiling..."

mkdir build
make all

cd build
#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
#cmake --build . --config Release

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
        echo "Test${i}: PASS" >> ../../GRADES-LAB2-2.txt
      else
        echo "Test${i}: FAIL" >> ../../GRADES-LAB2-2.txt
      fi
    else
      echo "Test${i}: TIMEOUT" >> ../../GRADES-LAB2-2.txt
    fi        
  done
else 
  # Executable circlist_main not built.
  echo "circlist_main did not build"
  for i in "${tsts[@]}"
  do
    echo "Test${i}: ERROR" >> ../../GRADES-LAB2-2.txt
  done
fi
echo "------------------------"
echo 


echo "Cleaning up..."
#sudo rm -fr ds-workspace-username/
echo
echo "Done!"


