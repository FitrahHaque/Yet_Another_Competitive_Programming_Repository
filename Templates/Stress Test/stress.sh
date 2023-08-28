#!/bin/sh
file1="file1"
file2="file2"
g++ -std=c++17 -o test_gen test_gen.cpp
g++ -std=c++17 -o $file1 $file1.cpp
g++ -std=c++17 -o $file2 $file2.cpp

while true
do
    ./test_gen
    ./$file1 < input.txt > out1.txt
    ./$file2 < input.txt > out2.txt

    if cmp -s "out1.txt" "out2.txt"; then
        echo "Test Case OK"
    else
        echo "ERROR ENCOUNTERED"
        diff "out1.txt" "out2.txt" > differences.txt
        break
    fi
done
# chmod +x stress.sh
# ./stress.sh
