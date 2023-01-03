```cpp
// A Simple Program to Dermostrate Function Overloading

#include <iostream>
using namespace std;

int sum (int a, int b) {
    return (a + b);
}
// Function Overloading
int sum (int a, int b, int c) {
    return (a + b + c);
}

// Volume of a Cylinder.
float volume(float radius, float height) {
    return (3.14 * radius * radius * height);
}

// Volume of a Cuboid.
// Function Overloading
float volume (float length, float width, float height) {
    return (length * width * height);
}

// Driver Code:
int main() {

    cout << sum (4, 5) << endl;
    cout << sum(4, 5, 6) << endl;

    // Cylinder
    cout << volume(4.5, 7.16) << endl;
    // Cuboid
    cout << volume(7, 16, 2.5) << endl;

    return 0;
}
```