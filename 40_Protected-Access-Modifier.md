# Protected Access Modifiers in C++

**Private** members (variables/methods) of a class : can be accessed/used only by a member method of the class itself -- and cannot be used/accessed by any other function which is not a member of the class +  cannot be inherited by a subclass.

**Protected** members (variables/methods) of a class : can be accessed/used by a member methods of the original class + can be inherited by a subclass which inherits the original class ---  but cannot be used by any other outside non-member function or any other class.

# Protected Visibility Mode :

When a subclass inherits a base class under **Protected** visibility mode --- it inherits all the public as well as protected members of the base class as `protected members` of its own.

| 	              |  Public Visibility Mode    |  	Private Visibility Mode  |  	Protected Visibility Mode|
|------------------|----------------------------|-----------------------------|---------------------------------|               
|Private members   |  Not Inherited             | 	    Not Inherited        |      	Not Inherited         |     
|Protected members |  Protected                 |   	Private                  |   Protected                    |
|Public members    |  Public	                   |     Private                 |   Protected         |

```cpp
#include<iostream>
using namespace std;

class Base{
    protected:
        int a; // Can be inherited by subclass
    private:
        int b; // Cannot be inherited by subclass
};

class Derived: protected Base{
   // Inherits 'int a' (which is protected in Base class) as a protected member.
};

int main(){
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since 'int a' is protected and cannot be accessed by any method outside the class directly. The data member “a” can only be accessed by a member function of the “derived” class but not outside the class.
    return 0;
}
```