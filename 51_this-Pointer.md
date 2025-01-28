```cpp
#include <iostream>
using namespace std;

class A
{
    int a;

    public:
        A setData(int a)
        {
            this->a = a; //'this' keyword is a pointer, which points to the object which is invoking the member function.

            return *this;  //this pointer can also be used to return the object upon which this function is invoked.
        }

        void getData(void)
        {
            cout << "The value of a is " << a << endl;
        }
};

// Driver Code
int main()
{
    A obj;

    // obj.setData(4)
    // obj.getData(); // The value of a is 4

    obj.setData(4).getData();  //This code works on using 'return *this;' inside setData(int a).

    return 0;
}
```