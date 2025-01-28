# Example 1:

```cpp
#include <iostream>
using namespace std;

class Complex {
    int a, b;
    public:
        // Parametrized Constructor Declaration
        Complex(int , int);

        void display(void) {
            cout << "'The value of complex number is "<<a<<" + i"<<b<<endl;
        }
};

Complex :: Complex(int x, int y){ // This is a parameterized constructor as it takes 2 parameters
    a = x;
    b = y;
    // cout<<"Hello world";
}

// Driver Code:
int main()
{
    // Implicit Constructor Call
    Complex o1(4,9);
    o1.display();

    // Explicit Constructor Call
    Complex o2 = Complex(5,6);
    o2.display();

    // In both ways, we can invoke our parametrized constructor and create a class object.

    return 0;
}
```

# Example 2:

```cpp
#include <iostream>
#include <cmath>    // Neccessary Header file for doing math operations
using namespace std;

class Point {
    int x, y;
    friend double distance(Point p1, Point p2);

    public:
        Point(int a, int b){  // Constructor Declaration
            x = a;
            y = b;
        }
        
        void displayPoint(){
            cout << "The point is ("<< x <<", "<< y <<")"<<endl;
        }
};

// Method for calculating difference between 2 cartesian points
double distance(Point p1, Point p2){
    int diff1 = p2.x - p1.x;
    int diff2 = p2.y - p1.y;

    return sqrt(pow(diff1,2) + pow(diff2,2));
}

// Driver Code:
int main()
{
    Point p(0, 1);
    p.displayPoint();  // The point is (1, 1)

    Point q(0, 6);
    q.displayPoint();  // The point is (4, 6)

    cout << "THe distance between points p1 and p2 is "<< distance(p,q) << endl;

    return 0;
}
```