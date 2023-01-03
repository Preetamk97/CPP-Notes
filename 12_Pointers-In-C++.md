```cpp
#include <iostream>
using namespace std;

// What is a Pointer?
// Pointer is a dataType (like string/integer/double) which holds/stores the address of other dataTypes.

int main () {

    int a = 3;
    int* b = &a; 
    // int(integer type)*(data address holding pointer) b(variable name) = &(address of) a(variable name)

    // & (Ampersand) ---> Address of Operartor. 
    // * ---> Dereference Operator

    cout << "&a : The address of int variable a is : " << &a << endl;
    cout << "b : The value stored inside Pointer b -  address of int variable a : " << b << endl;
    // Both outputs will be same.

    cout << "*b : The value of the variable at the address stored inside pointer b is : " << *b << endl; 
    // *b - Value of the variable (int a = 3) which is available at the address stored inside Pointer b - int a = 3.

    
    // We can also create pointers to store the address of another pointer.
    // Pointer To Pointer Variable.
    int** c = &b; 
    // c is storing the address of another pointer b.

    cout << "c : Address of pointer b - stored in pointer c is : " << c << endl;
    cout << "&b : Address of pointer b - stored in pointer c is : " << &b << endl;


    cout << "*c: Value stored inside the variable, available at the address stored inside Pointer c - Value of Pointer b - Address of int a : " << *c << endl;
    cout << "&a :address of int variable a - The value stored inside Pointer b: " << &a << endl;
    // Both outputs will be same.
    // *c = b

    // *b - Value of the variable (int a = 3) which is available at the address stored inside Pointer b - int a = 3.
    // *b = **c = int a = 3.
    cout << "**c : Value of **c is : " << **c << endl;
    cout << "a : Value of int a is : " << a << endl; 
     
    return 0;
}
```