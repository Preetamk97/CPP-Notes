# Friend Functions belonging to a different Class in C++:

```cpp
// In this program, we have made two classes Calculator & Complex. Two methods of Calculator class (sumReal() & sumcomplex()) use Complex class objects (o1 & o2) as arguments and accesses their private member variables (o1.a/o2.a & o1.b/o2.b). So, we will declare the methods (sumReal() & sumcomplex()) as friend functions inside the Complex class.

#include <iostream>
using namespace std;

// Forward Class Declaration
class Complex;
// Since, in the next following step, we are going to make a Calculator class and inside that we are going to make some methods (sumReal() & sumcomplex()) which are going to use Complex class objects (o1 & o2) as arguments, therefore, we need to declare beforehand -- that there is a class Complex, which will be defined in future. This is the importance of Forward Class Declaration step.

class Calculator
{
public:
    int sum(int x, int y)
    {
        return (x + y);
    }

    int sumReal(Complex o1, Complex o2);
    // This function/method is using Complex class objects o1 & o2 (which is yet to be defined) as arguments.
    int sumComplex(Complex o1, Complex o2);
    // This function/method is also using Complex class objects (which is yet to be defined) as arguments.
};

// Now before defining how we are going to use the Complex class objects o1 and o2, inside the functions sumReal() and sumComplex(), we must first define the Complex class. That is the logical order of explaining the program.

class Complex
{
    int a, b;
     
    // Declaring indivisual member methods of Calculator class as Friend functions of the current class.
    //------------------------------------------------------------------------------------------
    friend int Calculator ::sumReal(Complex o1, Complex o2);
    // It says that --  there is a 'int Calculator ::sumReal(Complex o1, Complex o2);' function that belongs to the Calculator class and which will be defined in the future --- is declared as a friend function of this class.
    // Since, sumReal() is declared as a Friend function inside the Complex class, so, it can access the private member variables (a,b) of the Complex class objects o1 and o2.
    friend int Calculator ::sumComplex(Complex o1, Complex o2);
    // It says that --  there is a 'int Calculator ::sumComplex(Complex o1, Complex o2);' function that belongs to the Calculator class and which will be defined in the future --- is declared as a friend function of this class.
    // Since, sumComplex() is declared as a Friend function inside the Complex class, so, it can access the private member variables (a,b) of the Complex class objects o1 and o2.

public:
    void setNum(int x, int y)
    {
        a = x;
        b = y;
    }
    void printNum(void)
    {
        cout << "Your number is " << a << " + i" << b << endl;
    }
};

// Defining friend function sumReal() outside both the classes Calculator and Complex.
int Calculator::sumReal(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

// Defining friend function sumComplex() outside both the classes Calculator and Complex.
int Calculator::sumComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

// Driver Code:
int main()
{
    Complex o1, o2;
    o1.setNum(1, 4);
    o2.setNum(5, 8);

    Calculator calcReal;
    int resultReal = calcReal.sumReal(o1, o2);
    cout << "Sum of real part of o1 andc o2 is " << resultReal << endl;
    
    Calculator calcComplex;
    int resultComplex = calcComplex.sumComplex(o1, o2);
    cout << "Sum of complex part of o1 andc o2 is " << resultComplex << endl;

    return 0;
}
```

----

# Friend Classes in C++:

```cpp
#include <iostream>
using namespace std;

// Forward Class Declaration
class Complex;

class Calculator
{
public:
    int sum(int x, int y)
    {
        return (x + y);
    }

    int sumReal(Complex o1, Complex o2);
    // This function/method is using Complex class objects o1 & o2 (which is yet to be defined) as arguments.
    int sumComplex(Complex o1, Complex o2);
    // This function/method is using Complex class objects o1 & o2 (which is yet to be defined) as arguments.
};

class Complex
{
    int a, b;

    // friend int Calculator ::sumReal(Complex o1, Complex o2);
    // friend int Calculator ::sumComplex(Complex o1, Complex o2);
    
    // Declaring the entire Calculator class as friend.
    friend class Calculator;
    // Here, instead of declaring each method of Calculator class as a friend function indivisually, we declared the whole Calculator class as friend --- so that, any member function of Calculator class will be able to access the private member variables of Complex class objects without any restriction.


public:
    void setNum(int x, int y)
    {
        a = x;
        b = y;
    }
    void printNum(void)
    {
        cout << "Your number is " << a << " + i" << b << endl;
    }
};

// Defining friend function sumReal() outside both the classes Calculator and Complex.
int Calculator::sumReal(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

// Defining friend function sumComplex() outside both the classes Calculator and Complex.
int Calculator::sumComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

// Driver Code:
int main()
{
    Complex o1, o2;
    o1.setNum(1, 4);
    o2.setNum(5, 8);

    Calculator calcReal;
    int resultReal = calcReal.sumReal(o1, o2);
    cout << "Sum of real part of o1 andc o2 is " << resultReal << endl;
    
    Calculator calcComplex;
    int resultComplex = calcComplex.sumComplex(o1, o2);
    cout << "Sum of complex part of o1 andc o2 is " << resultComplex << endl;

    return 0;
}
```