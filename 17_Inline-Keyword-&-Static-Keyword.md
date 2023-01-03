# Inline Keyword:

1. On running a C++ code, first ------- the compiler converts our code into binary code/machine language (compilation) ----> and then creates a .exe executable file of our code ----> which can run on any computer.

1. Now, during compilation only the `int main()` function of the program is converted into binary code format (which forms the contents of the .exe file).


## Without Using Inline Keyword

Consider the below code.

```cpp
#include <iostream>
using namespace std;

int productOf(int a, int b) {
    return a*b;
}

int main() {
    int x=4, y=5;
    
    //Printed 5 times
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;

    return 0;
}
```

In this case, after the compilation step of the program execution is completed, *the readable code version* of the *executable binary machine code* that makes the .exe file of the program, looks somewhat like this -

```cpp
int main() {
    int x=4, y=5;
    
    cout << "The product of x and y is" << 20 << endl;
    cout << "The product of x and y is" << 20 << endl;
    cout << "The product of x and y is" << 20 << endl;
    cout << "The product of x and y is" << 20 << endl;
    cout << "The product of x and y is" << 20 << endl;

    return 0;
}

```
**[The addresses from where the function is called and the definition of the function are different.]**

Here, during the compilation process, whenever the function `productOf(x,y)` is called, first the actual parameters (x=4, y=5) are copied from the calling function address and passed to the function definition address as formal parameters. There the function does the calculation (a * b) and returns the value 20 back to the memory address of the calling function. And, this process repeats every time the function `productOf(x,y)` gets called in the program. Now, this increases our compilation overhead for the program.


## Using Inline Keyword

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. 

The compiler can ignore the inline qualifier in case defined function is more than a line in order to optimse the code - on its own.

```cpp
#include <iostream>
using namespace std;

inline int productOf(int a, int b) {
    return a*b;
}

int main() {
    int x=4, y=5;
    
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;
    cout << "The product of x and y is" << productOf(x,y) << endl;

    return 0;
}
```

If we make a function as inline, then the compiler places a copy of the code of that function at each point where the function is called during compilation time.

In this case, after the compilation step of the program execution is completed, *the readable code version* of the *executable binary machine code* that makes the .exe file of the program, looks somewhat like this -

```cpp
int main() {
    int x=4, y=5;
    
    cout << "The product of x and y is" << return 4*5 << endl;
    cout << "The product of x and y is" << return 4*5 << endl;
    cout << "The product of x and y is" << return 4*5 << endl;
    cout << "The product of x and y is" << return 4*5 << endl;
    cout << "The product of x and y is" << return 4*5 << endl;

    return 0;
}
```
When the inline function is encountered, then the definition of the function is copied to it. In this case, there is no control transfer which saves a lot of time and also decreases the overhead.

Any changes made to an inline function will require the inline function to be recompiled again because the compiler would need to replace all the code with a new code; otherwise, it will execute the old functionality.

## Why do we need an inline function in C++?

Whenever a function is called, if the length of the function is small, then the substantial amount of execution time spent in overheads such as copying the variables from the calling function to the function defnition and then returning back the result to the calling function will be greater than the time taken required to execute that function.

C++ has provided one solution to this problem. In the case of function calling, the time for calling such small functions is huge, so to overcome such a problem, a new concept was introduced known as an inline function. When the function is encountered inside the main() method, it is expanded with its definition thus saving time.


## We cannot provide the inlining to the functions in the following circumstances:

1. If a function is recursive.
1. If a function contains a loop like for, while, do-while loop.
1. If a function contains static variables.
1. If a function contains a switch or go to statement


## Advantages of inline function:

1. In the inline function, we do not need to call a function, so it does not cause any overhead.
1. It also saves the overhead of the return statement from a function.
1. An inline function is mainly beneficial for the embedded systems as it yields less code than a normal function.

## Disadvantages of Inline Function:

1. If we use many inline functions, then the binary executable file also becomes large.

1. It also increases the compile-time overhead because whenever the changes are made inside the inline function, then the code needs to be recompiled again to reflect the changes; otherwise, it will execute the old functionality.

1. Sometimes inline functions are not useful for embedded systems because, in some cases, the size of the embedded code is considered more important than the speed.

1. It can also cause thrashing due to the increase in the size of the binary executable file. If the thrashing occurs in the memory, then it leads to the degradation in the performance of the computer.


# Static Keyword:

```cpp
#include <iostream>
using namespace std;

int staticDemo(int a, int b) {
    static int c = 0; 
    // Static Variable : A static variable is a variable that is declared using the `static` keyword (See the code above). Now the speciality of a static variable is that, when a static variable is declared inside a function definition, no matter how many times the function gets called inside the int main() function, the static variable inside the function definition gets initialized only once.

    // In more simple terms, even though the function `int staticDemo(int a, int b)` is called 4 times inside the int main() function, the above line of code i.e. static int c = 0; will run only for the 1st time the function gets called (i.e. 1st Iteration).

    // So the next time when the function gets called again (i.e. 2nd Iteration), 
    // the new value of c = 1 (which was the final value of c in the 1st Iteration of the function) ------ and NOT c = 0.

    c = c+1;
    // 1st Iteration: c = c + 1 ==> c = 0 + 1 ==> c = 1
    // 2nd ItertationL: c = c + 1 ==> c = 1 + 1 ==> c = 2

    return a*b+c;
    // 1st Iteration: return 21
    // 2nd ItertationL: return 22
}
int main() {
    int a, b;
    cout << "Enter the value of a:" << endl;
    cin >> a;
    cout << "Enter the value of b:" << endl;
    cin >> b;

    // Calling  staticDemo(int a, int b) function 4 times.
    cout << "Value of staticDemo is: " << staticDemo(4,5) << endl;
    
    // *************** staticDemo(4,5) : 1st Iteration : Dry Run *****************
    // int staticDemo(4,5) {
    // c = 0; 
    // c = c+1 ==> c = 0 + 1 ==> c = 1;
    // return a*b+c ==> 4*5+1 ==> 21;
    // }

    cout << "Value of staticDemo is: " << staticDemo(4,5) << endl;

    // *************** staticDemo(4,5) : 2nd Iteration : Dry Run *****************
    // int staticDemo(4,5) {
    // c = 1 
    // c = c+1 ==> c = 1 + 1 ==> c = 2;
    // return a*b+c ==> 4*5+2 ==> 22;
    // }

    cout << "Value of staticDemo is: " << staticDemo(4,5) << endl;

    // *************** staticDemo(4,5) : 3rd Iteration : Dry Run *****************
    // int staticDemo(4,5) {
    // c = 2; 
    // c = c+1 ==> c = 2 + 1 ==> c = 3;
    // return a*b+c ==> 4*5+3 ==> 23;
    // }

    cout << "Value of staticDemo is: " << staticDemo(4,5) << endl;

    // *************** staticDemo(4,5) : 4th Iteration : Dry Run *****************
    // int staticDemo(4,5) {
    // c = 3; 
    // c = c+1 ==> c = 3 + 1 ==> c = 4;
    // return a*b+c ==> 4*5+3 ==> 24;
    // }

    return 0;
}
```