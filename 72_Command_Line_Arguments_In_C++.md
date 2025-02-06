# Command Line Arguments in C++

**Command-line arguments** are ***arguments that are passed to a program when it is executed from the command line terminal***. 

The `main()` function of C++ generally has the following signature:

```cpp
int main()
{

// Suitable Code

return 0;
}
```

But to pass command-line arguments, we typically define `main()` with two arguments, where the **first argument is the number of command-line arguments** and the **second is the list of command-line arguments**.

## Signature of main() Function for C++ Command Line Arguments

```cpp
int main(int argc, char *argv[]){
     // Suitable Code
     return 0;
}
```
## What is `int argc` and `char* arg[]` ?

- **int argc** : ***argc (ARGument Count)*** is an **integer** that **stores the number of command line arguments passed to the main function**. It also includes the count for the name of the program, so if we pass a value to a program, the value of argc would be 2 (one for argument and one for program name).

- **char \*argv[]** : ***argv[] (ARGument Vector)*** is a **array of *char* type  pointers** where every element of it is a memory address that points to a string representing a command line argument. argv does not store the actual argument, but the pointer to that argument. The `argv[0]` will always contain the name of the program. 

## Example Program: 

Here’s a simple example program that prints the command line arguments passed to it:

```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument No." << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```
To run the above program with command line arguments, compile it and execute the generated executable file from the command line or terminal:

```terminal
g++ program_name.cpp
./program_name arg1 arg2 arg3
```

### Output:

```terminal 
Number of arguments: 4
Arguments:
Argument No.0: G:\MY NOTES\CPP NOTES\playground\play.exe
Argument No.1: arg1
Argument No.2: arg2
Argument No.3: arg3
```

## Passing Space Seperated String as a Single Argument:

In C++ program, multiple command line arguments are passed to the function by separating them by a whitespace but what happens if you have to pass an argument string that already contains spaces. In such case, we can enclose that string in the double quotes to pass it as a single argument.

```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << "Argument No." << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

### Terminal Command:

```terminal
g++ program_name.cpp
./program_name "My name is Pritam"
```

### Output:

```terminal 
Number of arguments: 2
Arguments:
Argument No.0: G:\MY NOTES\CPP NOTES\playground\play.exe
Argument No.1: My name is Pritam
```