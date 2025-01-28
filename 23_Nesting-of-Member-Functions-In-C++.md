```cpp
// OOPS Recap:
// *****************************************************************************************

// C++, was initially called 'C With Classes', by Bjarne Stroustrup (Creator of C++).

// Class was an extension of `structure` in C.

// Structures had limitations:
//     - Members are public.
//     - cannot add methods.

// Classes = Structures + more.

// Classes can have methods and propertise (attributes).

// Classes can make few members as private and few as public.

// Structures in C++ are typedef'ed -- by default -- i.e writting the keyword `typedef` before `struct` keyword is not neccessary to give a name to the structure.

// You can declare objects alongwith the class declaration. See the below code snippet.
/*
class Employee {
    // class definition
} harry, rohan, pritam;
*/

// harry.salary = 8 makes no sense if salary variable is private inside the class definition.

//*******************************************************************************************

// Nesting of Member Functions:
//-----------------------------

#include <iostream>
#include <string> // Necessary import for creating string type variables.
using namespace std;

class Binary
{
    // Every member in a class is by default 'Private' otherwise specified 'public' explicitly.
    // So the string variable member 'num' declared below is private by default and hence cannot be accesed inside `int main()` function directly (object.num).
    string num;
    void chk_bin();     // Method to check if the entered number is binary or not.
                        // Cannot access directly inside driver code (like Object.chk_bin()).
public:
    void read();            // Method to take a number from the user.   
    void ones_compliment(); // Method to convert the 0's to 1's and 1's to 0's.
    void display();         // Method to print/display the 'num' variable.
};

void Binary ::read()
{
    cout << "Enter your number: " << endl;
    cin >> num;
}

void Binary ::chk_bin()
{
    for (int i = 0; i < num.length(); i++)
    {
        /* code */
        if (num.at(i) != '0' && num.at(i) != '1')
        {
            cout << "The entered number is not a binary." << endl;
            exit(0); // exit out of the entire program.
        }
    }
}

void Binary ::ones_compliment()
{
    chk_bin();  // Nesting of a Member Function.
    
    for (int i = 0; i < num.length(); i++)
    {
        if (num.at(i) == '0')
        {
            num.at(i) = '1';
        }
        else
        {
            num.at(i) = '0';
        }
    }
}

void Binary ::display()
{
    for (int i = 0; i < num.length(); i++)
    {
        cout << num.at(i);
        // endl is not added intentionally.
    }
    cout << endl;
}

// Driver Code:
int main()
{

    Binary b; // Created object 'b' from Binary class.
    b.read();

    // b.chk_bin();  // chk_bin() is private. Cannot access it like this.

    b.ones_compliment();  // chk_bin() is nested inside ones_compliment().

    // cout << b.num << endl;
    // above line of code will work only if the member 'num' was not made public inside the class Binary. 
    // Alternative way - Using display() method.
    b.display();

    return 0;
}
```