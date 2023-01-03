```cpp
#include <iostream>
using namespace std;

class Base
{
public:
    int base_var;
    void display(void)
    {
        cout << "The value of base_var is " << base_var << endl;
    }
};

class Derived : public Base
{
public:
    int derived_var;
    void display(void)
    {
        cout << "The value of base_var is " << base_var << endl;
        cout << "The value of derived_var is " << derived_var << endl;
    }
};

// Driver Code
int main()
{
    // Creating a Base class pointer that can store the address of a Base class object.
    Base *base_ptr;

    // Creating a Derived class object
    Derived derived_obj;
    derived_obj.base_var = 34;    // base_var is public and is available to Derived class objects.
    derived_obj.derived_var = 40; // derived_var is public and is available to Derived class objects.

    // Now, in C++, we can store the address of a Derived class object inside a pointer of the Base class.
    // Demo:
    base_ptr = &derived_obj; // This will give no errors and is completely acceptable.

    // Important Twist::
    //*****************
    // But now, when we apply display() function on the derived_obj through the base_ptr ---> this will invoke the display() function of the Base class (and not Derived class).
    // Demo:
    (*base_ptr).display(); // The value of base_var is 34

    // But if we apply display() function directly on the derived_obj itself ---> this will invoke the display() function of the Derived class.
    derived_obj.display(); // The value of base_var is 34
                           // The value of derived_var is 40

    // Also, we cannot access the exclusive data member (derived_var) of the Derived class object (derived_obj) directly using a Base class pointer (base_ptr).
    //  cout<<"The value of (derived_var) of (derived_obj) accessed through (base_ptr) is "<<(base_ptr->derived_var)<<endl;  //This code will throw error.
    // But, we can access any Base class data member of a derived class object through a Base class pointer which stores the address of the Derived class object.
    cout << "The value of (base_var) of (derived_obj) accessed through (base_ptr) is " << (base_ptr->base_var) << endl;
    // The value of (base_var) of (derived_obj) accessed through (base_ptr) is 34

    // Creating a Derived class pointer
    Derived *derived_ptr;

    // Storing the address of previously created Derived class object inside the Derived class pointer.
    derived_ptr = &derived_obj;

    // Invoking display() on derived_obj through derived_ptr:
    derived_ptr->display(); // The value of base_var is 34
                            // The value of derived_var is 40

    // Accessing derived_var through derived_ptr:
    cout << "Accessing derived_var through derived_ptr = " << derived_ptr->derived_var << endl;
    // Accessing derived_var through derived_ptr = 40

    // Accessing base_var through derived_ptr:
    cout << "Accessing base_var through derived_ptr = " << derived_ptr->base_var << endl; // Yes we can do this!
    // Accessing base_var through derived_ptr = 34

    // This program is an example of Runtime Poymorphism.
    return 0;
}
```