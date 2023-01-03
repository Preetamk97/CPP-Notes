```cpp
// Creating a Class.
// Private and Public Access Modifiers.
// Defining a method inside the class and outside the class.

#include <iostream>
using namespace std;

class Employee {
    private:
        int a, b, c;
    public:
        int d, e;

        // There are two ways of adding a function/method inside a class.
        // We can define the function either inside the class itself or we can just put a declaration/promise of creating a function/method (for this class) --- outside the class.

        void setData(int a1, int b1, int c1); // Declaration that the `void setData(int a1, int b1, int c1)` named function will be defined outside the class.

        // Defining a method within the class itself.
        void getData(){
            cout << "value of a = " << a << endl;
            cout << "value of b = " << b << endl;
            cout << "value of c = " << c << endl;
            cout << "value of d = " << d << endl;
            cout << "value of e = " << e << endl;
        }
};

// Defining setdata() function of the Employee class.
void Employee :: setData(int a1, int b1, int c1) {
     a = a1;
     b = b1;
     c = c1;
}

int main () {
    // Creating an Employee class object `harry`.
    Employee harry;
    
    // setting public attribute/variable values for the created object harry.
    harry.d = 25;
    harry.e = 46;

    // harry.a = 1;
    // If execute the above line of code, we will get an error.
    // This is because variable/attribute `int a` is declared as `Private` inside the Employee class. 
    // So, we cannot set the value of variable/attribute `int a` + neither can we print/use its value directly (as harry.a) --- inside a function that does not belong to the Employee class (int main() does not belong to Employee class.)
    // This applies to all 3 Private variables of Employee class i.e int a, b, c. All of these are private variables the values of which cannot be set directly (harry.a = 1;) + neither can we print/use its value directly (as harry.a) --- inside any function that does not belong to the class (Employee).

    // The private variables can be set using a function that is defined inside the class.
    // Setting values for private variables a, b, c.
    harry.setData(1, 2, 3);

    // The private variables can only be used inside a function that is defined inside the class.
    // Printing the values of all the private variables (int a, b, c) and public variables (int d, e) through getData() function.
    harry.getData(); 

    return 0;
}
```

```cpp
// Another Example

#include <iostream>
using namespace std;

class Animal {
    private:
        string name, type, sound;
        
    public:
        void setData(string name1, string type1, string sound1){
            name = name1;
            type = type1;
            sound = sound1;
        }

        void getData () {
            cout << "Name is : " << name << endl;
            cout << "Type is : " << type << endl;
            cout << "Sound is : " << sound << endl;
        }
};

int main () {
    
    Animal dog;
    dog.setData("Jon", "Labradore", "Bark");
    dog.getData();
    
    return 0;
}
```