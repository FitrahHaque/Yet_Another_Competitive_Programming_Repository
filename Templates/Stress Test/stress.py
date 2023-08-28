import os

file1 = "file1"
file2 = "file2"

os.system(f'g++ -std=c++17 -o test_gen test_gen.cpp')
os.system(f'g++ -std=c++17 -o {file1} {file1}.cpp')
os.system(f'g++ -std=c++17 -o {file2} {file2}.cpp')

while True:
    os.system('./test_gen')
    os.system(f'./{file1} < input.txt > out1.txt')
    os.system(f'./{file2} < input.txt > out2.txt')

    if os.system('cmp -s out1.txt out2.txt') == 0:
        print("Test Case OK")
    else:
        print("ERROR ENCOUNTERED")
        os.system('diff -y out1.txt out2.txt > differences.txt')
        break