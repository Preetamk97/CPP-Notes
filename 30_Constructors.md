```cpp
// Constructors
// Constructor is a special member function with the same name as of the class.
// It is used to initialize the objects of its class.
// It is automatically invoked whenever an object is created.

#include <iostream>
using namespace std;

class Complex {
    int a, b;

public:
    // Default/Non-Parametrized Constructor declaration. 
    Complex(void); 

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// Default Constructor/Non-Parametrized Constructor
//*************************************************
// No return datatype.  
// Same name as class.
// Gets invoked at the very instant when an object is created. 
// Constructor Definition
Complex :: Complex(void){
    a = 10;
    b = 20;
    // cout << "Hello World";
}

// Driver Code:
int main()
{
    Complex o1, o2, o3;

    o1.printNumber(); // Your number is 10 + 20i
    o2.printNumber(); // Your number is 10 + 20i
    o3.printNumber(); // Your number is 10 + 20i

    return 0;
}

/* Note:
*********
1. Constructor should be declared under the public section of the class.
2. Constructor has the same name as class.
3. ***Constructors do not have return datatype.
4. Gets invoked at the very instant when an object is created. 
5. Constructor can take void as parameter -- Default/Non-Parametrized Constructor.
6. Constructors which take some parameter -----  Parameterized Constructor.
*/
```