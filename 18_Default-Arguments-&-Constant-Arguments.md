# Default Arguments

```cpp
#include <iostream>
using namespace std;

// Making a function to calculate simple interest on different types of loans.
int simpleInterest(int principal, int time, int rate = 5) {
    return ((principal * rate * time)/100);
}
// In the above function definition, the argument `int rate = 5` is a Default Argument.
// An argument which assumes a default value if no value for it is passed while calling the function inside `int main()` function (ex - simpleInterest(2000,2)) --- is called a Default Argument.
// In this case, while calling the function simpleInterest() if no value is passed for the `int rate` argument (ex - simpleInterest(2000,2)) then the function will assume the value for rate = 5 on itself and return the calculation accordingly.

// Defaut Arguments should always mentioned/passed at the last. ex - simpleInterest(int principal, int time, int rate = 5)

int main() {

    // Let Interest rate for student loan = Default rate = 5%.
    cout << "S.I on Student Loan for Principal = 2000 and Time = 2 Years and Rate = 5% is : " << simpleInterest(2000,2) << endl;
    // In this case, since while calling the function simpleInterest(), no value is passed for the `int rate` argument (ex - simpleInterest(2000,2)) then the function will assume the value for rate = 5 on itself and return the calculation accordingly.
    // 200

    // Let Interest rate for Car loan = rate = 10%.
    cout << "S.I on Car Loan for Principal = 2000 and Time = 2 Years and Rate = 10% is : " << simpleInterest(2000,2,10) << endl;
    // Here, since we are providing a value of rate = 10 from our side, therefore the function will take this value and not the default value of rate = 5 that we set while defining the function.
    //400

    return 0;
}
```

# Constant Argument:

Constant arguments are used when you don’t want your values to be changed or modified by the function. An example of constant arguments is shown in Code Snippet below.

```cpp
int strlen(const char *p){

}
```
As shown in Code Snippet 4, we created a `strlen` function which takes a constant argument `*p`. As the argument is constant so its value won’t be modified.