#!/bin/bash
#must have sudo rights

#echo "Pulling from git..."
#git clone git@github.com:username/ds-workspace-username.git

declare -a tsts=("01" "02" "03" "04" "05" "06" "07" "08" "09" "10")

cd lab1-1
echo "Compiling..."
make clean
make all


echo "-----------------------------"
echo "******** sample1.cpp ********"
echo "-----------------------------"
for i in "${tsts[@]}"
do
   echo "----- test1.${i}.txt -----"
   ./sample1.out < test1.${i}.txt > test1.${i}.out.txt
   diff -i -w -B test1.${i}.out.txt expected1.${i}.txt | head -4
   echo "------------------------"
done
echo 

echo "-----------------------------"
echo "******** sample2.cpp ********"
echo "-----------------------------"
for i in "${tsts[@]}"
do
   echo "----- test2.${i}.txt -----"
   ./sample2.out < test2.${i}.txt > test2.${i}.out.txt
   diff -i -w -B test2.${i}.out.txt expected2.${i}.txt | head -4
   echo "------------------------"
done
echo 


echo "Cleaning up..."
#make clean
cd ../
#sudo rm -fr ds-workspace-username/
echo
echo "Done!"
