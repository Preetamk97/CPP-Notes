```cpp
#include <iostream>
using namespace std;

class Complex {
    int a, b;
    public:
        // Parametrized Constructor Declaration
        Complex(int x, int y) {
            a = x;
            b = y;
        }

        // Constructor Overloading
        Complex(int x) {
            a = x;
            b = 0;
        }

        // Constructor Overloading
        Complex() {
            a = 0;
            b = 0;
        }

        void display(void) {
            cout << "'The value of complex number is "<<a<<" + i"<<b<<endl;
        }
};
// Driver Code:
int main()
{   
    Complex num1(2,5);
    num1.display();

    Complex num2 = Complex (5);
    num2.display();

    Complex num3;  //Parameterless Constructor
    num3.display();

    // The value of complex number is 2 + i5
    // The value of complex number is 5 + i0
    // The value of complex number is 0 + i0

    return 0;
}
```