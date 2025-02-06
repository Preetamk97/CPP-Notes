```cpp
#include <iostream>
#include <cmath> //The C++ <cmath> header file conmtains a set of functions to perform mathematical operations such as: sqrt() to calculate the square root, log() to find natural logarithm of a number etc. Refer Google to see what things can be done using 'cmath' functions.
using namespace std;

class SimpleCalculator {
    float a, b;
    public:
        void getDataSimple(){
            cout<<"Enter the value of a :"<<endl;
            cin>>a;
            cout<<"Enter the value of b :"<<endl;
            cin>>b;
        }

        void performOperationsSimple(){
            cout<< "The value of a + b is : "<< a+b << endl;
            cout<< "The value of a - b is : "<< a-b << endl;
            cout<< "The value of a * b is : "<< a*b << endl;
            cout<< "The value of a / b is : "<< a/b << endl;
        }
};

class ScientificCalculator {
    int a, b;
    public:
        void getDataScientific(){
            cout<<"Enter the value of a :"<<endl;
            cin>>a;
            cout<<"Enter the value of b :"<<endl;
            cin>>b;
        }

        void performOperationsScientific(){
            cout<< "The value of sin(a) is : "<< sin(a) << endl;
            cout<< "The value of cos(a)  is : "<< cos(a) << endl;
            cout<< "The value of pow(a,b) is : "<< pow(a,b) << endl;
            cout<< "The value of sqrt(a) is : "<< sqrt(a) << endl;
            cout<< "The value of abs(a) is : " << abs(a) << endl;
        }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator {

};

// Driver Code
int main()
{
    // SimpleCalculator calci;
    // calci.getDataSimple();
    // calci.performOperationsSimple();

    // ScientificCalculator scicalci;
    // scicalci.getDataScientific();
    // scicalci.performOperationsScientific();

    HybridCalculator hybcalc;
    hybcalc.getDataScientific();
    hybcalc.performOperationsScientific();
    hybcalc.getDataSimple();
    hybcalc.performOperationsSimple();

    return 0;
}
```