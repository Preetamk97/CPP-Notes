```cpp
#include <iostream>
using namespace std;

/*
Syntax for Initialization List in Constructor
**********************************************
{{constructor-name}} (parameters-list) : initialization-list {
    //constrstructor-code
}

Example
*******
class Test {
    int a, b;
    public:
        Test (int x, int y) : a(x), b(y) {
            //constrstructor-code
        }
};
*/

class Test {
    int a;
    int b;
    public:
        // Test (int x, int y) : a(x), b(y) {       
        // Test (int x, int y) : a(x), b(x+y) {     
        // Test (int x, int y) : a(x), b(2*y) {     
        // Test (int x, int y) : a(x), b(a + y) {   
        Test (int x, int y) : a(x+y), b(y) {   
            cout<<"constructor called"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
        }
};

// Driver Code
int main()
{
    Test harry(4,5);
    return 0;
}
```