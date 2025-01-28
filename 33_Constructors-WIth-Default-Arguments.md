```cpp
#include <iostream>
using namespace std;

class Simple {
    int a, b, c;

    public:
        Simple(int x = 200, int y = 400, int z = 600){
            // int x = 200, int y = 400, int z = 600 are called Default Arguments of the Contructor.
            a = x;
            b = y;
            c = z;
        }
        void print(void) {
            cout << "a = "<<a <<"  |  b = "<<b<<"  |  c = "<<c<<endl;
        }
};
// Driver Code:
int main()
{   
    Simple o1(5, 6, 7); 
    o1.print(); 
    // a = 5  |  b = 6  |  c = 7
    // If we provide values for all of the constructor arguments, then the constructor prioritizes them over the default provided contructor arguments and overides them.

    Simple o2(5, 6);
    o2.print();
    // a = 5  |  b = 6  |  c = 600
    // Now if we do not provide the value for a constructor argument, then the constructor will use the default provided value for that argument.

    Simple o3(5);
    o3.print();
    // a = 5  |  b = 400  |  c = 600

    Simple o4;
    o4.print();
    // a = 200  |  b = 400  |  c = 600
    // If we do not provide values for any of the constructor arguments, then the constructor will use the default argument values, for all the arguments.

    return 0;
}
```