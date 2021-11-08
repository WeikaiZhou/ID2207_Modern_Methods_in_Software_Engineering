# ID2207_Final_Project
This is the project of ID2207 at KTH in FALL 2021.

## Content_Of_Project
This project includes `main.cpp`, `login.h`, `employee.h`, `database.h`, `testClientRequest.cpp`, `testEventPlan.cpp`, `testFM.cpp` and `testHR.cpp`.

## Compile_And_Run_The_Code
During the development, the compiling of the code is based on a Linux system that has already installed `g++` compiler. If your Linux system does not support `g++` compiler, you can enter the following code in the terminal to install: `sudo apt install g++ make cmake gdb valgrind`. Then, in the terminal, one can use `g++ -o out main.cpp` to compile the project and `./out` to run.

To compile and run the test functions, one can use `g++ -o testCR testClientRequest.cpp`, `g++ -o testEP testEventPlan.cpp`, `g++ -o testFM testFM.cpp` and `g++ -o testHR testHR.cpp` in the terminal to compile all the four test functions separately. To run the compiled code, one can `./testCR`, `./testEP`, `./testFM` and `./testHR` to run. If some information is output in the terminal, then there will be some bugs in the program and you can easily find them according to the error message. Otherwise, the program has passed the test.

For MacOS, you can use similar methods to compile and run the code in the terminal. For windows, you can use an IDE that supports C/C++ to compile and run the code.

Corresponding users that has already added into the system are listed below:

| User                    | Username   | Password |
| ----------------------- | ---------- | -------- |
| Customer Service        | CS         | 000      |
| Senior Customer Service | SCS        | 000      |
| Financial Manager       | FM         | 000      |
| Administration Manager  | AM         | 000      |
| Production Manager      | PM         | 000      |
| Service Manager         | SM         | 000      |
| HR Team                 | HR         | 000      |
| Chef                    | Chef       | 000      |
| Decoration              | Decoration | 000      |

## Honor_Code
If there are similar questions, problem sets or projects in the future, it is the responsibility of KTH students not to copy or modify these codes, or other files because it is against the Honor Code. The owner of this repository doesn't take any commitment for other's faults.
