# Example 1: Adding an external functionas friend function of a class.

```cpp
// More on Friend Functions

#include <iostream>
using namespace std;

// Forward Declaration for class Y.
class Y;

class X {
    int xData;
    // Adding an external function 'int add(X o1, Y o2);' as friend function of class X.
    friend int add(X o1, Y o2);

    public:
        void setData(int value){
            xData = value;
        }
};

class Y {
    int yData;
    // Adding an external function 'int add(X o1, Y o2);' as friend function of class Y.
    friend int add(X o1, Y o2);

    public:
        void setData(int value){
            yData = value;
        }
};

int add (X o1, Y o2) {
    int sum = (o1.xData + o2.yData);
    return sum;
}

// Driver Code:
int main()
{
    X x;
    x.setData(5);

    Y y;
    y.setData(10);

    int sum = add(x,y);
    cout << sum << endl;  //15

    return 0;
}
```

# Example 2: Adding an external functionas friend function of a class.

```cpp
// More on Friend Functions

#include <iostream>
using namespace std;

// Class Declaration
class C2;

class C1 {
    int num1;
    // Friend Function
    friend void swapNum(C1 &o1, C2 &o2);

    public:
        void setNum1(int a){
            num1 = a;
        }
        void display1(void) {
            cout << "num1 is : " << num1 << endl;
        }
};

class C2 {
    int num2;
    // Friend Function
    friend void swapNum(C1 &o1, C2 &o2);

    public:
        void setNum2(int a){
            num2 = a;
        }
        void display2(void) {
            cout << "num2 is : " << num2 << endl;
        }
};

void swapNum(C1 &o1, C2 &o2) {    // Call by Reference  // Exact o1,o2  - Not copy o1,o2
    int temp = o1.num1;
    o1.num1 = o2.num2;
    o2.num2 = temp;
}

// Driver Code:
int main()
{
    C1 o1;
    C2 o2;

    o1.setNum1(5);
    o2.setNum2(6);

    o1.display1();
    o2.display2();

    swapNum(o1,o2);

    o1.display1();
    o2.display2();

    return 0;
}
```

