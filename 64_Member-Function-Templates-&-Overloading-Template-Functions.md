# Code 1:

```cpp
#include <iostream>
using namespace std;


template <class T>
class Harry {
    T data;
    public:
        Harry(T a){
            data = a;
        }
        // void display(void){
        //     cout<<data<<endl;
        // }
        void display(void);

};

//Defining the Member Function [display()] of our Templatised Class [Harry] outside the Class.
template <class T>
void Harry <T> :: display(void){
    cout<<data<<endl;
}

// Driver Code
int main()
{
    Harry<int> o1(54);
    o1.display();
    return 0;
}
```


# Code 2:

```cpp
#include <iostream>
using namespace std;

//Overloading of Templatised Functions

void func(int a){
    cout << "I am a simple function "<<a<<endl;
}

template <class T>
void func(T a){
    cout << "I am a templatised function "<<a<<endl;
}

//Both the function names are same - but one is a simple function and the another is the templatised one.

// Driver Code
int main()
{
    func(4);  //Exact match takes the highest priority - func(int a)
    //I am a simple function 4

    func(56.8);  //In this case, templatised function will run.
    // I am a templatised function 56.8

    func("Harry");  //In this case, templatised function will run.
    // I am a templatised function Harry
    
    return 0;
}
```