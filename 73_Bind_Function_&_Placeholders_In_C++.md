# Bind Function and Placeholders in C++

- `std::bind` is a function that allows you to create function objects (functors) that "bind" together function parameters and arguments. It's particularly useful in scenarios where you need to create new callable objects with specific arguments.

- `std::bind` is part of the C++ Standard Library and is defined in the <functional> header.

Let’s start with a simple example;

```cpp
#include <iostream>
#include <functional>

void func(int x, int y)
{
    std::cout<<"x: "<<x<<" y: "<<y<<"\n";
}

int main()
{
    auto f = std::bind(func, 10, 20);  
    // the std::bind function returns a function object f.

    // If we call the functor returned from the std::bind function with the function call operator, we call the wrapped func() function with parameters 10 and 20
    f();

    return 0;
}
```
## The concept of Placeholders

Now let’s do an example like this: Our func() function should always take the value 10 as the first parameter, and the second parameter should take the value that we passed to the function object.

```cpp
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

    return 0;
}
```

This is a common use case for std::bind where you can partially bind arguments and provide the remaining arguments when you call the resulting function object.

### Multiple Placeholders

Let’s look at different examples and outputs below.

```cpp
// Here the first parameter that we will be supplying to 'f()' will be used for both x and y arguments of 'func(int x, int y)' function.
auto f = std::bind(func, std::placeholders::_1, std::placeholders::_1);

f(5);  // x = 5  y = 5
```

```cpp
// Here, the second argument that we will be supplying to 'f()' will be assigned to x parameter of 'func(int x, int y)' function.
// and the first argument that we will be supplying to 'f()' will be assigned to y parameter of 'func(int x, int y)' function 
auto f = std::bind(func, std::placeholders::_2, std::placeholders::_1);

f(5,3);  // x = 3  y = 5
```

## Binding Member Function of a Class and its Object

`std::bind` is a generic wrapper so we can wrap also a member function of a class.

```cpp
#include <iostream>
#include <functional>

class MyClass
{
public:
    int func(int x)
    {
        std::cout<<"x: "<<x<<"\n";
        return x*x;
    }
};

int main()
{
    MyClass myClassObj;

    auto f = std::bind(&MyClass::func, myClassObj, std::placeholders::_1);

    int retVal = f(55);
    
    std::cout<<retVal<<"\n";

    return 0;
}
```

In this example, std::bind takes three arguments:

- The first argument is the member function that we want to bind, which is `&MyClass::func`. We use the address of operator `&` to specify the member function.
- The second argument is the object on which the member function should be called, which is `myClassObj`. This binds the member function to `myClassObj`.
- The third argument is a placeholder `std::placeholders::_1` , indicating that when you call f() with an argument, that argument will be passed as the first argument to the member function.

## Binding a Lambda Function

```cpp
#include <iostream>
#include <functional>

int main()
{
    auto f = std::bind( [](int x, int y){
                        return x*y;
                       },
                       std::placeholders::_1,std::placeholders::_2 );

    int retVal = f(9,7);

    std::cout<<retVal<<"\n";

    return 0;
}
```
