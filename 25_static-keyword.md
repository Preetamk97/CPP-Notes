# Commented Code:

```cpp
#include <iostream>
using namespace std;

class Employee {
    static int count;  
    // When a static data member is created, there is only a single copy of the data member which is shared between all the objects of the class.
    // At any instant, the value of 'static int count' variable will be same for every object within the Employee class.
    // static member variables are NOT ININTIALIZED INSIDE THE CLASS but outside of it.
    // Default value of a static member variable is 0.
    
    int id;
    // If the data members are not static then every object has an individual copy of the data member and it is not shared.

    public:
        void setData(){
            cout << "Enter id: " << endl;
            cin >> id;
            count++;    
            // The value of the counter will be incremented by one every time this function will run.
            // At any instant, the value of 'static int count' variable will be same for every object within the Employee class.
        }
        void getData() {
            cout << "Id of this employee is : " << id << endl;
            cout << "Count of this employee is " << count << endl;
        }

        // static function
        static void getCount() {
            // cout << id; // Cannot access non static member variable inside a static function.
            cout << "The value of count is " << count << endl;

            // We can oly access static variables inside a static function.
        }
        // When a static method is created, they become independent of any object and are directly associated with the class (). That means, we can call a static function directly using the name of the class itself 
        // ==> Employee ::getCount() 
        // In C++, static methods can only access static data members and other static methods of the class. 
        // “getCount” function is static, so if we try to access any data members or member functions which are not static the compiler will throw an error.
};

// Important Step: Whenever, we create a static member variable (using 'static' keyword) inside a class, we need to explicitly mention about it outside the class.
int Employee :: count;  
// Default value of a static member variable is 0.

// We can also give an initial value (initialization) to our `static int count` variable from here. See the code below.
// int Employee :: count = 1000; 

int main()
{   
    // Creating objects of Employee class.
    Employee harry, rohit, pritam;
    
    // harry.count = 1;   // Cannot do this as count is private member.
    // harry.id = 1;    // Cannot do this as id is private member.

    harry.setData();    // count will be 1
    harry.getData();    // count will be 1
    Employee ::getCount(); // Calling a static function using class name.

    rohit.setData();    // count will be 2
    rohit.getData();    // count will be 2
    Employee ::getCount();

    pritam.setData();  // count will be 3
    pritam.getData();  // count will be 3
    rohit.getData();   // count will be 3
    Employee ::getCount();

    return 0;
}
```