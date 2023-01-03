***Multiple Inheritance = 2 Baap ka 1 Bachha***

# Syntax of Multiple Inheritance

```cpp
class {{derived-class-name}} : {{visibility-mode}} {{base-class-1}}, {{visibility-mode}} {{base-class-2}}
{
    //class-body
}
```

# Example Program:

```cpp
#include <iostream>
using namespace std;

class Base1 {
    protected:
        int base1int;
    public:
        void set_base1_int(int a){
            base1int = a;
        }
};

class Base2 {
    protected:
        int base2int;
    public:
        void set_base2_int(int a){
            base2int = a;
        }
};

//Multiple Inheritance
class Derived : public Base1, public Base2 {
    // Inherited from Base1 class:
        //base1int ---> protected
        //set_base1_int(int a) ---> public
    // Inherited from Base2 class:
        //base2int ---> protected   
        //set_base2_int(int a) ---> public
    public:
        void show(){
            cout << "The value of int base1int is "<<base1int<<endl;
            cout << "The value of int base2int is "<<base2int << endl;
            cout <<"base1int + base2int = "<< base1int + base2int << endl;
        }
};
// Driver Code
int main()
{
    Derived harry;
    harry.set_base1_int(60);
    harry.set_base2_int(40);
    harry.show();
    return 0;
}
```