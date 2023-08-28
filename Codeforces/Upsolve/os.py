import os
import random
import subprocess

# Replace these paths with your actual paths
cpp_file_path = "/Users/ihtemad/Documents/Code/competitive_programming/Yet_Another_Competitive_Programming_Repository/Codeforces/Upsolve/1808C.cpp"
executable_path = "/Users/ihtemad/Documents/Code/competitive_programming/Yet_Another_Competitive_Programming_Repository/Codeforces/Upsolve/1808C"

# Compile C++ code using g++
compile_command = f'g++ -std=c++17 "{cpp_file_path}" -o "{executable_path}"'
compile_process = subprocess.Popen(compile_command, shell=True, stderr=subprocess.PIPE)
_, compile_error = compile_process.communicate()

if compile_process.returncode == 0:
    # Run the compiled program with input
    testcases = 100
    input_data = f'{testcases}\n'
    for i in range(testcases):
        num1 = random.randint(1, 10**4)
        num2 = random.randint(num1, 10**4)
        input_data += f"{num1} {num2}\n"
    run_command = f'"{executable_path}"'
    with open("input.txt", "w") as file:
        file.write(input_data)
    run_process = subprocess.Popen(run_command, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = run_process.communicate()

    if run_process.returncode == 0:
        print("Program output:")
        print(stdout.decode())
    else:
        print("Error running the program:")
        print(stderr.decode())
else:
    print("Compilation error:")
    print(compile_error.decode())
