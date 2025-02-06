#include <iostream>
#include <functional>

void func(int x, int y)
{
    std::cout<<"x: "<<x<<" y: "<<y<<"\n";
}

int main()
{
    auto f = std::bind(func, 10, std::placeholders::_1);

    f(5);  // the call f(5) effectively invokes func(10, 5).

    // Here, the second argument that we will be supplying to 'f()' will be assigned to x parameter of 'func(int x, int y)' function.
    // and the first argument that we will be supplying to 'f()' will be assigned to y parameter of 'func(int x, int y)' function 
    auto f1 = std::bind(func, std::placeholders::_2, std::placeholders::_1);

    f1(5,3);  // x = 3  y = 5

    return 0;
}