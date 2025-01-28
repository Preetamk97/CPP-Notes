```cpp
#include <iostream>
using namespace std;

// Base Class
class Employee {

   public:
      int id;
      float salary;

      Employee(int i, float s){
         id = i;
         salary = s;
      };

      Employee(){}; 
      // When we create an object of the Programmer class (defined below) - before invoking its own constructor 'Programmer(int i, float s){}' - first the compiler will run the default constructor of the base class Employee 'Employee(){};' - from which the class Programmer is derived -- therefore defining a default constructor is important if we are going to create any subclass of the current class in future.
};

//Derived Class Syntax
//---------------------

/*
class {derived-class-name} : {visibility-mode} {base-class-name}
{
   // class code
}
*/

/*
Notes: 
-----
1. There are 3 visibilty modes - public, private, & protected.
2. Default visibility mode - If no visibility mode is specified - is Private.
3. Private Visibility Mode: Public members of the base class becomes - private members of the derived class.
4. Public Visibility Mode: Public members of the base class becomes - public members of the derived class.
5. Private members of the base class can never be inherited by a derived class -- they are private.
*/

// Creating a class Programmer - inheriting from base class Employee 
class Programmer : public Employee {
   public:
      string language = "C++";  // This is an own personal attribute of the Programmer class.
      Programmer(int i, float s) {
         id = i;
         salary = s;
      }
      // When we create an object of the Programmer class - before invoking its own constructor 'Programmer(int i, float s){}' - first the compiler will run the default constructor of the base class Employee 'Employee(){};' - from which the class Programmer is derived -- therefore defining a default constructor in the parent class is important if we are going to create any subclass from it in the future.
};

// Driver Code:
int main()
{  
   Employee pritam(1,1000), harry(2,500);
   cout << pritam.salary << endl; // 1000
   cout << harry.salary << endl; // 500

   Programmer rajesh(3, 1500);
   cout<<rajesh.id<<endl;  // 3
   cout<<rajesh.salary<<endl;  // 1500
   cout<<rajesh.language<<endl;  // C++

   return 0;
}
```