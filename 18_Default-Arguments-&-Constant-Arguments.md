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

// ** Important ** 
//*******************
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

In C++, the `const` keyword in the function parameter list means that the parameter cannot be modified within the function. However, it does not prevent the caller from passing a different value to the function. An example of the concept is shown in Code Snippet below.

```cpp
#include <iostream>
using namespace std;

float circle_area;

int area_of_circle(float radius, const float pi = 3.14){
    // value of 'pi' cannot be modified within this function.
    // pi = 16; // This line of code will give an error
    return pi * radius * radius;
}

int main(){
    circle_area = area_of_circle(2.3, 56); 
    // In this code, pi is declared as const in the function area_of_circle, which means that within the function, pi cannot be modified. 
    //However, when you call area_of_circle(2.3, 56), the value 56 is passed to the function and used as pi.

    cout << circle_area << endl; // Output will be based on pi = 56
}
```