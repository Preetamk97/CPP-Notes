# C++ Lambda
C++ Lambda expression allows us to define anonymous function objects (functors) which can either be used inline or passed as an argument.

Lambda expression was introduced in C++11 for creating anonymous functors in a more convenient and concise way.

## Creating a Lambda Expression in C++:

A basic lambda expression can look something like this:

```cpp
auto greet = []() {
  // lambda function body
};
```
Here,

- `[]` is called the lambda introducer which denotes the start of the lambda expression
- `()` is called the parameter list which is similar to the () operator of a normal function

The above code is equivalent to:

```cpp
void greet() {
  // function body
}
```

Now, just like the normal functions, we can simply invoke the lambda expression using:

```cpp
greet();
```
## Example: C++ Lambda Function:

```cpp
#include <iostream>
using namespace std;

int main() {

  // create a lambda function that prints "Hello World!"
  auto greet = []() {
    cout << "Hello World!";
  };

  // Note: We have used the auto keyword to automatically deduce the return type for lambda expression.

  // call lambda function
  greet();

  return 0;
}
```

## C++ Lambda Function With Parameters:

Just like a regular function, lambda expressions can also take parameters. For example,

```cpp
#include <iostream>
using namespace std;

int main() {

  // lambda function that takes two integer
  //  parameters and displays their sum
  auto add = [] (int a, int b) {
   cout << "Sum = " << a + b;
  };

  /*
    This is equivalent to:

    void add(int a, int b) {
    cout << "Sum = " << a + b; 
    }
  */

  // call the lambda function
  add(100, 78);

  return 0;
}
```

## C++ Lambda Function With Return Type

Generally,** there is a single return statement**, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify it explicitly. 

```cpp
auto add = [] (int a, int b) {
  // always returns an 'int'
  return a + b;
};
```
In the above case, we have not explicitly defined the return type for the lambda function. This is because there is a single return statement which always returns an integer value.

But for multiple return statements of different types, we have to explicitly define the type. For example,

```cpp
auto operation = []  (int a, int b,  string op) -> double {
  if (op == "sum") {
    // returns integer value
    return a + b;
  } 
  else {
    // returns double value
    return (a + b) / 2.0;
  }
};
```
Notice the code `-> double` above. This explicitly defines the return type as `double`, since there are multiple statements which return different types of data. So no matter what type of value is returned by the various return statements, they are all explicitly converted to `double` type. Even if the lambda returns an integer value, it is explicitly converted to double type.

## C++ Lambda Function Capture Clause:

By default, lambda functions cannot access variables of the enclosing function. In order to access those variables, we use the capture clause.

We can capture the variables in two ways:

### Capture by Value:

This is similar to calling a function by value. Here, the actual value is copied when the lambda is created.

<div class="alert alert-block alert-info">
<b>Note:</b> Here, we can only read the variable inside the lambda body but cannot modify it.
</div>

A basic lambda expression with capture by value looks as follows:

```cpp
int num_main = 100;

// get access to num_main from the enclosing function
auto my_lambda = [num_main] () {
  cout << num_main;
};

// If we remove num_main from the capture clause, we will get an error since num_main cannot be accessed from the lambda body.
```

### Capture by Reference:

This is similar to calling a function by reference i.e. the lambda has access to the variable address.

<div class="alert alert-block alert-info">
<b>Note:</b> Here, we can read the variable as well as modify it inside the lambda body.
</div>

A basic lambda expression with capture by reference looks as follows:

```cpp
int num_main = 100;

// access the address of num_main variable
auto my_lambda = [&num_main] () {
  num_main = 900;
};

// Notice the use of the & operator in [&num_main]. This indicates that we are capturing the address of the num_main variable.
```

### Example 3: C++ Lambda Capture by Value

```cpp
#include<iostream>
using namespace std;

int main() {

  int initial_sum = 100;

  // capture initial_sum by value
  auto add_to_sum = [initial_sum] (int num) {
    // here inital_sum = 100 from local scope
    return initial_sum + num;
  };

  int final_sum = add_to_sum(78);
  cout << "100 + 78 = " << final_sum;

  return 0;
}
```

Note: Suppose we want to capture multiple variables by value. For example,

```cpp
auto my_lambda = [a, b, c, d, e] (){
  // lambda body
}
```
As you can see, this can be a very tedious task. To make our work easier, we can simply use implicit capture by value. For example,

```cpp
auto my_lambda = [=] (){
  // lambda body
}
```
Here, [=] says all the variables of the enclosing function are captured by value.

### Example 4: C++ Lambda Capture by Reference

```cpp
#include <iostream>
using namespace std;

int main() {

  int num = 0;

  cout << "Initially, num = " << num << endl;
  
  // [&num] captures num by reference
  auto increment_by_one = [&num] () {
    cout << "Incrementing num by 1.\n";
    num++;
  };

  // invoke lambda function
  increment_by_one();

  cout << "Now, num = " << num << endl;

  return 0;
}
```
**Note**: To capture all variables of the enclosing function, we can simply use implicit capture by reference. For example,

```cpp
auto my_lambda = [&] (){
  // lambda body
}
```
Here, [&] indicates that all the variables are captured by reference.

## Example: C++ Lambda Function as Argument in STL Algorithm

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  // initialize vector of integers
  vector<int> nums = {1, 2, 3, 4, 5, 8, 10, 12};

  // Here, The lambda expression takes the integer num and returns true if num is even.
  int even_count = count_if(nums.begin(), nums.end(), [](int num) {
    return num % 2 == 0;
  });  
  

  cout << "There are " << even_count << " even numbers.";

  return 0;
}
```

