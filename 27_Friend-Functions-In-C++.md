```cpp
#include <iostream>
using namespace std;

class Complex {
    int a, b;
    public:
        void setNum(int x, int y) {
            a = x;
            b = y;
        }
        void printNum(void) {
            cout << "Your number is "<<a<<" + i"<<b<<endl;
        }

        // Friend Function: An external function which can use/access the private variables of any object belonging to the class.
        // Friend Function is not a member function of the class. So, we cannot directly use it on the objects of the class (i.e. Object.sumComplex(o1,o2)).
        friend Complex sumComplex(Complex o1, Complex o2);
        // In the above code, complex is the return type of the method.

};

// Friend Function: A foreign function which has got permissions/access to use the private data variables of a class.
Complex sumComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.setNum((o1.a + o2.a), (o1.b + o2.b));    // Accessing the private member variables (a,b) of objects o1, and o2.
    return o3;
}

// Driver Code:
int main () {
    Complex c1, c2, c3;

    c1.setNum(1,4);
    c2.setNum(5,8);

    c1.printNum();
    c2.printNum();

    c3 = sumComplex(c1, c2);
    c3.printNum();

    // c3.sumComplex(c1, c2)    
    // This code will give error.
    // sumComplex() is not a member function of the Complex class.

    return 0;
}

// Propertise of Friend Functions:
//*********************************
//1. Not a part of the class. Not in the scope of the class.
//2. c3.sumComplex() ===> Invalid Code.
//3. c3 = sumComplex(c1, c2)  ===> Valid Code.
//4. Can be invoked without the help of any object.
//5. Usually contains objects as arguments.
//6. Can be declared inside public or private area of the class  ===> It doesn'nt make a difference.
```