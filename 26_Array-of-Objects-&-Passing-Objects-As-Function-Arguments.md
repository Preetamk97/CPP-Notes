# Array of Objects.

```cpp
#include <iostream>
using namespace std;

class Employee {
    int id;
    int salary;

    public:
        void setId() {
            cout << "Enter employee id: " << endl;
            cin >> id;
            salary = 1200;
        }
        void getId() {
            cout << "Id of the employee is: " << id << endl;
        }
};

int main () {
    // Employee pritam, rohit, pradhugyna, malakar;

    // pritam.setId();
    // pritam.getId();
    // rohit.setId();
    // rohit.getId();
    // pradhugyna.setId();
    // pradhugyna.getId();
    // malakar.setId();
    // malakar.getId();

    // We can also create an array of nameless Employee class objects.
    // Creating an array 'fb' of 4 nameless Employee class objects.
    Employee fb[4];

    for (int i = 0; i < 4; i++)
    {
        /* code */
        fb[i].setId();
        fb[i].getId();
        // This will run setId() & getId() functions on every nameless object of 'Employee fb[4]' array.
    }
    
    //The main thing to note here is that the objects can also be created individually but it is more convenient to use an array if too many objects are to be created.
    return 0;
}
```

# Passing Objects as Function Arguments.

```cpp
#include <iostream>
using namespace std;

class Complex {
    int a;
    int b;

    public:
        void setData(int x, int y) {
            a = x;
            b = y;
        }
        void setDataBySum(Complex o1, Complex o2) {
            a = o1.a + o2.a;
            b = o1.b + o2.b;
        }
        // setDataBySum() method takes Objects of class Complex as arguments. But we can take objects of any class as arguments inside a method of a class.
        
        void printNumber() {
            cout << "The value of complex number is " << a << " + i" << b << endl;
        }
};

// Driver Code:
int main () {
    Complex c1, c2, c3;

    c1.setData(2,3);
    c1.printNumber();

    c2.setData(5,6);
    c2.printNumber();

    c3.setDataBySum(c1, c2);
    c3.printNumber();

    return 0;
}
```