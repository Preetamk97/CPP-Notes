# Printing a Global Variable Inside A Function When It Has Already A Local Variable By The Same Name.

```cpp
#include <iostream>

using namespace std;

int c = 45;
// This is a global variable.

int main() {
    int a, b, c;

    cout << "Enter a "<< endl;
    cin >> a;

    cout << "Enter b" << endl;
    cin >> b;
    
    c = a + b;

    cout << "Sum of a & b i.e c = " << c << endl;
    // This line of code will print the Local Variable Value of c.

    cout << "The value of Global c is " << ::c <<endl;
    // '::c' will instruct the program to print the value of Global c.
    // '::' is called Scope Resolution Operator.
    
    return 0;
}
```

# Int, Float, Double & Long Double Literals:

```cpp
#include <iostream>

using namespace std;

int main() {

    cout << "The size of 3 is " << sizeof(3) << endl; 
    // Int ---- 4 bytes

    cout << "The size of 3.14 is " << sizeof(3.14) << endl; 
    // Double --- 8 bytes

    cout << "The size of 3.14f is " << sizeof(3.14f) << endl; 
    // Float ------ 4 Bytes

    cout << "The size of 3.14F is " << sizeof(3.14F) << endl; 
    // Float ------- 4 Bytes

    cout << "The size of 1234567890L is " << sizeof(1234567890L) << endl; 
    // Long ------- 4 Bytes

    cout << "The size of 1234567890l is " << sizeof(1234567890l) << endl;
    // Long ------- 4 Bytes

    cout << "The size of 3.14l is " << sizeof(3.14L) << endl; 
    // Long Double ------- 16 Bytes

    return 0;
}

// Default datyaType of an Integer in C++  = Integer
// Default dataType of a Decimal Number in C++  = Double
// 3.14f or 3.14F ---- Float 
// 1234567890L or 1234567890l ---- Long
// 3.14l or 3.14L ---- Long Double
```

# The Concept Of Reference Variables

```cpp
#include <iostream>

using namespace std;

int main() {

    int x = 300;

    int &y = x;
    // Here y is also pointing to the same value of variable x.
    // Pritam ----> Babu -----> Preet  ==== Same Person.
    // y is called a Reference Variable.

    cout << "The value of x is " << x << endl;
    cout << "The value of y is " << y << endl;

    return 0;
}
```

# Type Casting

```cpp
#include <iostream>

using namespace std;

int main() {

    int a = 45;

    float b = 45.5666;

    cout << "a + b = " << a + b << endl;  // 90.5666
    cout << "a + (int)b = " << a + (int)b << endl;  //90
    cout << "a + int (b) = " << a + int (b) << endl; //90
    cout << "(float)a + b = " << (float)a + b << endl; // 90.5666

    return 0;
} 
```