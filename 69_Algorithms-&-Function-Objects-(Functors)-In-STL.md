```cpp
#include <iostream>
#include <functional>  //In order to use Functional Objects (Functors) we need to include this header file.
#include <algorithm> //Header file for using some common algorithms like sort() - used below.
using namespace std;

//In C++, a function object (also known as a functor) is an object that can be called as if it were a function. 

// Driver Code
int main()
{
    int arr[] = {9, 78, 18, 56, 10, 11};

    // Using Sort Algorithm
    //*************************
    sort(arr, arr+5);  //sorts upto 5th element of arr.  //9 10 18 56 78 11
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //9 10 18 56 78 11

    sort(arr, arr+6);  //sorts upto 6th element of arr.  //9 10 11 18 56 78
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //9 10 11 18 56 78


    //Use of Functor - greater<int>( ) - along with sort() : to sort in descending order.
    sort(arr, arr+6, greater<int>());  // 78 56 18 11 10 9
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // 78 56 18 11 10 9

    return 0;
}
```