# Learning Objectives:

- High Level & Low Level Language
- Variables in C++
- Comments in C++
---

# High Level & Low Level Language

1. **High Level Laneguage** : These are programmer-friendly languages that are manageable, easy to understand, debug, and widely used in today’s times. High-level languages require the use of a compiler or an interpreter for their translation into the machine code. These languages have a very low memory efficiency. It means that they consume more memory than any low-level language.
High level languages are farther from the hardware with lots of layers of abstraction.

1. **Low Level Language** : These are machine-friendly languages that are very difficult to understand by human beings but easy to interpret by machines. Low-level language requires an assembler for directly translating the instructions to the machine language. These languages have a very high memory efficiency. It means that they consume less memory as compared to any high-level language. Low level languages are nearest to the hardware.
---

# Variables in C++

1. Variables are like containers for storing our data. 

1. Data of various data types (integers, floating numbers, booleans, etc.) are used in C++ programs, for example, "int" is used for denoting integers (0,1,-1,-200 etc.), the "float" is used for denoting floating-point (decimal) numbers (0.0001, -6.2594 etc.), "char" is used for storing a single character enclosed within single quotes (‘ ‘) ('A', 'c', 'E', etc.), and many more data types are available, we will discuss them in upcoming lectures. 

# Important Code: 

```cpp
#include <iostream>

using namespace std;

int main()
{
    // int a = 4;
    // int b = 8;
    int a = 14, b = 15;
    float pi = 3.14, c = 3.14f, d = 3.14F;
    double d = 6.7899;
    char alpha = 'a';
    bool is_True = false;
    // false = 0
    // true = 1
    long d = 123456789, e = 123456789L, f = 123456789l;
    long long g = 1234567890123456789, h = 1234567890123456789LL, i = 1234567890123456789ll;
    long double j = 3.141592653589793238462643383279;

    size_t k = 1234567890;
    // size_t is an unsigned integral datatype. 
    // It can only be used for storing NON-NEGATIVE integral type values.
    // It can be used for storing any POSITIVE value of integer, long, or long long datatype. 
    

    cout << "This is Tutorial 4.\nHere, the value of a = " << a << ".\nAnd, the value of b = " << b <<".";
    //"\n" is used to give line breaks in the output.
    // "\n" is called Escape Sequence Character.
    cout << "\nThe value of pi = " << pi << ".";
    cout << "\nThe value of char = " << alpha << ".";
    cout << "\nThe value of is_True = " << is_True << ".\n"; // 0
    return 0;
}
```

---

# Comments in C++

```cpp
#include<iostream>

using namespace std;

 int main() {
    cout << "Hello World";

    // This is Single-Line Comment

    /* This
    is 
    multiline 
    comment
    */

    return 0;
 }
```