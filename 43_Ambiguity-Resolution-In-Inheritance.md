# Example 1:

## The Ambiguity Problem:

```cpp
#include <iostream>
using namespace std;

class Base1 {
    public:
        void greet(void){
            cout << "How are you?" << endl;
        }
};

class Base2 {
    public:
        void greet(void){
            cout << "Kaise ho ?" << endl;
        }
};

class Derived : public Base1, public Base2 {
    // Inherited from Base1 class:
        //void greet(void) ---> public
    // Inherited from Base2 class:  
        //void greet(void) ---> public
};

// Driver Code
int main()
{
    Base1 base1;
    base1.greet(); //How are you?
    Base2 base2;
    base2.greet(); //Kaise ho ?

    Derived harry;
    harry.greet();  // Now, our Derived class object 'harry' has access to the greet() functions of both 'Base1' class and 'Base2' classes (same name). So, the compiler cannot decide as to which greet() function is it asked to run. This is the Ambiguity Problem of Inheritance.

    // Thus, upon running the program, the above line of code will throw an error.

    return 0;
}
```

## The Solution:

```cpp
#include <iostream>
using namespace std;

class Base1 {
    public:
        void greet(void){
            cout << "How are you?" << endl;
        }
};

class Base2 {
    public:
        void greet(void){
            cout << "Kaise ho ?" << endl;
        }
};

class Derived : public Base1, public Base2 {
    // Inherited from Base1 class:
        //void greet(void) ---> public
    // Inherited from Base2 class:  
        //void greet(void) ---> public
    public:
        void greet(void){
            Base2 :: greet();
        }
        // Here, we are instructing our compiler that, whenever we apply/call for the greet() function, upon an object of the Derived class ---> to always apply the greet() function of the Base2 class.
        // This is the Resolution of the Ambiguity Problem of Inheritance. 
};

// Driver Code
int main()
{
    Base1 base1;
    base1.greet(); //How are you?
    Base2 base2;
    base2.greet(); //Kaise ho ?

    Derived harry;
    harry.greet();  //Now, this line will not throw errors.  // Kaise ho ?

    return 0;
}
```

---

# Example 2:

```cpp
#include <iostream>
using namespace std;

class Base1 {
    public:
        void say(void){
            cout << "Hello World" << endl;
        }
};

class Base2 : public Base1 {  //class Base2 inheriting from class Base1
    // Inherited from Base1 class:
        //  void say(void) ---> public mode
    public:
        void say(void){
            cout << "The world is so beautiful today" << endl;
        }
        // In this case, since class Base2 has inherited the say() method from class Base1, therefore, defining a new say() method inside class Base2 will be simply overridde the original say() method of Base1 class.
};

class Derived : public Base2 {
    // Inherited from Base2 class:
        //  void say(void){
        //     cout << "The world is so beautiful today" << endl;
        // }
};

// Driver Code
int main()
{
    Base1 base1;
    base1.say(); //Hello World
    Base2 base2;
    base2.say(); ////The world is so beautiful today

    Derived harry;
    harry.say();  //In this case, say() method of Base2 class will get applied.
    //The world is so beautiful today

    return 0;
}
```