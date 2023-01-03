A **copy constructor** is a type of constructor that creates a copy of another object. If no copy constructor is written in the program compiler will supply its own copy constructor. An example program to demonstrate the concept of a Copy constructor in C++ is shown below.

```cpp
#include <iostream>
using namespace std;

class Number {
    int a;

    public:
        Number(){}; // Default Constructor

        Number(int num){
            a = num;
        }

        // copy constructor
        // takes a reference object (of its own class) as a parameter and assigns values to the data members “a”.
        Number(Number &obj){
            // Note that we must supply only a reference variable '&obj' as parameter and not just 'obj'.
            // Because if it's not by reference, it's by value. To do that you make a copy, and to do that you call the copy constructor. But to do that, we need to make a new value, so we call the copy constructor again, and so on...
            // You would have infinite recursion because "to make a copy, you need to make a copy".
            cout << "copy constructor called !!!" << endl;
            a = obj.a;
        }
        // When no copy constructor is found, compiler supplies its own default copy constructor.

        void display(void) {
            cout << "The number of this object is " << a << endl;
        }
};

// Driver Code:
int main()
{  
    Number x, y, z(45), z2;

    x.display();  // Garbage Value // The number of this object is 0
    y.display();  // Garbage Value // The number of this object is 8
    z.display();  // The number of this object is 45.

    Number z1(z); // Copy constructor invoked
    z1.display();

    z2 = z; // Copy constructor not invoked // because the object “z2” is already created.
    z2.display();

    Number z3 = z; // Copy constructor invoked // because the object “z3” is being created.
    z3.display();

    return 0;
}
```