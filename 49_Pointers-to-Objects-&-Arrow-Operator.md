```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imaginary;
    public:
        void setData(int a, int b){
            real = a;
            imaginary = b;
        }
        void getData(void){
            cout<<"The real value is "<<real<<endl;
            cout<<"The imaginary value is "<<imaginary<<endl;
        }
};

// Driver Code
int main()
{
    Complex c1;

    //Creating a pointer for Complex object c1
    Complex *ptr = &c1;

    //doing the above two steps in single line of code using new operator.
    //Complex *ptr = new Complex;

    // c1.setData(4,50);
    // (*ptr).setData(4,50);  //Accessing the object at the address that is strored inside pointer ptr.
    ptr->setData(4,50); // Doing the same work using Arrow Operator - Only works for Object Pointers.

    // c1.getData();
    // (*ptr).getData();  //Accessing the object at the address that is strored inside pointer ptr.
    ptr->getData(); // Doing the same work using Arrow Operator - Only works for Object Pointers.

    cout<<"**************************************************************"<<endl;

    //Dynamically Creating an Array of Complex Objects and storing its address inside a Pointer.
    Complex *ptr1 = new Complex[4];
    ptr1->setData(1,4);  //This sets the data for 1st Complex object of the Complex array.
    ptr1->getData();  //This gets the data for 1st Complex object of the Complex array.
    (ptr1+1)->setData(5,6); //This sets the data for 2nd Complex object of the Complex array.
    (ptr1+1)->getData(); //This gets the data for 2nd Complex object of the Complex array.
    (ptr1+2)->setData(8,9); //This sets the data for 3rd Complex object of the Complex array.
    (ptr1+2)->getData(); //This gets the data for 3rd Complex object of the Complex array.
    (ptr1+3)->setData(11,12); //This sets the data for 4th Complex object of the Complex array.
    (ptr1+3)->getData(); //This gets the data for 4th Complex object of the Complex array.
    
    return 0;
}
```