# What are Macros?

A macro is a label that is defined in the source code which gets replaced by its value by the preprocessor before compilation.  Whenever that label name is used in the code, it is replaced by the contents of the macro. Macros are initialized with the `#define` preprocessor command and can be undefined with the `#undef` command.

There are two types of macros: **object-like macros** and **function-like macros**.

## Basic Syntax

```cpp
#define MACRO_NAME replacement_code
```

# Object-Like Macros & Function-Like Macros

```cpp
#include <iostream>

// Object-Like Macro : These macros are replaced by their value in the source code before compilation. Their primary purpose is to define constants to be used in the code.
#define PI 3.14159 

// Function-like Macro : These macros behave like functions. They take arguments and used them in the replaced function code. Note: When defining a function-like macro, there cannot be a space between the macro name and the opening parenthesis. Also Note that other macros can also be used in defining a subsequent macro. Here PI macro is used in defining the AREA(r) macro.
#define AREA(r) r * r * PI 

int main() {

    float radius = 5;
    float result;

    // Using Object Like Macro PI
    std::cout << "Value of PI: " << PI << std::endl;

    // Using Function Like Macro AREA(r)
    result = AREA(radius);
    cout << "Area is " << result;

    return 0;
}
```

# Predefined Macros

C++ has a number of predefined macros, including the following:


- `__DATE__`: Current date formatted as MMM DD YYYY.
- `__TIME__`: Current time formatted as HH:MM:SS.
- `__FILE__`: Current filename.
- `__LINE__`: Current line number.

The following example uses the predefined macros mentioned above:

```cpp
#include <iostream>

using namespace std;

int main() {

  string file = __FILE__;
  // Alternate way to declare a string:
  // char file[] = __FILE__;  // String is nothing but an array of characters

  string date = __DATE__;
  // char date[] = __DATE__;   // String is nothing but an array of characters 

  string time = __TIME__;
  // char time[] = __TIME__;    // String is nothing but an array of characters

  int line = __LINE__;

  cout << "File name: " << file << "\n";  // File name: play.cpp
  cout << "Date: " << date << "\n";  // Date: Feb  2 2025
  cout << "Time: " << time << "\n";  // Time: 13:26:24
  cout << "Line number: " << line << "\n"; // Line number: 17
}
```

# Undefining a Macro

Once defined, a macro can be undefined with the `#undef` command. Using the macro after that point will result in a compilation error.

## Example:

```cpp
#include <iostream>

using namespace std;

#define TEST 1

int main() {
  #ifdef TEST
    cout << "TEST defined\n";
  #else
    cout << "TEST undefined\n";
  #endif

  #undef TEST

  #ifdef TEST
    cout << "TEST defined\n";
  #else
    cout << "TEST undefined\n";
  #endif
}
```
This results in the output:

```terminal
TEST defined
TEST undefined
```