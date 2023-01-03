# Discussion on Header Files:

```cpp
// There are two types of Header Files:
// 1. System Header Files :: Comes with the compiler.
//----------------------------------------------------
#include <iostream>
// If you hold press 'ctrl' key and click on the 'iostream' -- this will open the iostream header file in VS Code and you can see its contents.

// 2. User Defined Header Files :: Written by the Programmer.
//-----------------------------------------------------------
// #include "this.h"
// Above line of code will produce an Error if no 'this.h' file is present in the same directory as 'playground.cpp' file.

// You can access the list of all 'cpp header files' through Google -->> Search for 'cppreference for header files' in google --> Go to 'C++ Standard Library headers - cppreference.com' link.

using namespace std;

int main() {
    cout << "Header Files in C++";
    return 0;
}
```

# Discussion on Operators:

```cpp
#include <iostream>

using namespace std;

int main() {

    int a = 4, b = 5;

    cout << "Operators in C++" << endl;
    // Instead of using "\n" we can also use '<< endl' to Start a New line in Output.

    // Following are the Types of Operators in C++
    //**********************************************

    // Arithmetic Operators
    //***********************
    cout << "Following are the Arithmetic Operators: " << endl;

    cout << "The value of a + b is " << a+b << endl; // Addition
    cout << "The value of a - b is " << a-b << endl; // Subtaction
    cout << "The value of a * b is " << a*b << endl; // Multiplication
    cout << "The value of a / b is " << a/b << endl; // Division
    cout << "The value of a % b is " << a%b << endl; // Modulus Operator
    cout << "The value of a++ is " << a++ << endl;   // First Print And Then Increase Value by 1.
    cout << "The value of a-- is " << a-- << endl;   // First Print And Then Decrease Value by 1.
    cout << "The value of ++a is " << ++a << endl;   // First Increase Value by 1 And Then Print.
    cout << "The value of --a is " << --a << endl;   // First Decrease Value by 1 And Then Print.

    cout << endl;

    // Assignment Operators
    //***********************
    // x = 5 
    // x += 5   ===>   x = x + 5
    // x -= 5   ===>   x = x - 5
    // x *= 5   ===>   x = x * 5
    // x /= 5   ===>   x = x / 5
    // x %= 5   ===>   x = x % 5
    // x &= 5   ===>   x = x & 5
    // x |= 5   ===>   x = x | 5
    // x ^= 5   ===>   x = x ^ 5
    // x >>= 5   ===>   x = x >> 5
    // x <<= 5   ===>   x = x << 5

    // Comparison Operators:
    //****************************
    cout << "Following are the Comparison Operators: " << endl;

    cout << "The value of a==b is " << (a==b) << endl;  // Is Equal to
    cout << "The value of a!=b is " << (a!=b) << endl;  // Is Not Equal to
    cout << "The value of a>=b is " << (a>=b) << endl;  // Greater Than Equal to
    cout << "The value of a<=b is " << (a<=b) << endl;  // Smaller Than Equal to
    cout << "The value of a>b is " << (a>b) << endl;    // Greater Than
    cout << "The value of a<b is " << (a<b) << endl;    // Smaller Than
   
    // Logical Operators
    //**********************
    cout << "Following are the Logical Operators: " << endl;
    // && ---> AND Operator
    // || ---> OR Operator
    // ! --->< Not Operator
    cout <<"The value of ((a==b) && (a>b)) is "<< ((a==b) && (a>b)) << endl; // 0
    cout <<"The value of ((a==b) || (a>b)) is "<< ((a==b) || (a>b)) << endl; // 0
    cout <<"The value of (!(a==b)) is "<< (!(a==b)) << endl; // 1

    return 0;
}

// VS Code Tricks:
//*******************

// To make an exactly same change in every line at the same position (all points falling in a single vertical line) : Shift + Alt + DRAG YOUR MOUSE 

// Alt + Mouse Clicks.
// Shift + Alt + Down Key
// Alt Z
```