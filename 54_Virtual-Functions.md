```cpp
#include <iostream>
using namespace std;

class Base
{
public:
    int base_var = 1;
    void virtual display(void)  //Virtual Function.
    {
        cout << "The value of base_var is " << base_var << endl;
    }
};

class Derived : public Base
{
public:
    int derived_var = 2;
    void display(void)
    {
        cout << "The value of base_var is " << base_var << endl;
        cout << "The value of derived_var is " << derived_var << endl;
    }
};

// Driver Code
int main()
{
    Base *base_ptr;  //Creating a Base class pointer

    Derived derived_obj;  //Creating a Derived class object.

    base_ptr = &derived_obj;  //Storing the address of the Derived class object inside Base class pointer base_ptr.

    base_ptr->display();
    //According to the last lesson/tutorial, the above line of code will/should apply Base class function display() on derived_obj
    //But, to override this default behaviour, we write 'virtual' keyword in the display() function definition of the Base class.
    //When we use 'virtual' keyword in the display() function definition of the Base class ---> this means that, whenever we call the display() function on derived_obj -- using base_ptr -- the compiler will invoke the   display() function of Derived class (instead of the Base class display() -- which is the normal/default behaviour otherwise).
    //Output:
    //********
    // The value of base_var is 1
    // The value of derived_var is 2

    return 0;
}
```