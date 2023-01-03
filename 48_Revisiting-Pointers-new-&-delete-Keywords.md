```cpp
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    //Revisiting Pointers
    //*******************
    int a = 4;
    int* ptr = &a;
    cout<<"The value of a is "<<*(ptr)<<endl;

    //new keyword
    //************
    // In C++, the new keyword is used to dynamically allocate memory from the heap (also known as the free store).
    int *p = new int(40);  //Here we are performing both (int x=40; & int *p = &x;) lines of code in one line of code. Creating a block for storing an int value in the heap memory --> storing value 40 --> storring the address of this block inside a int-pointer variable p.
    cout<<"The value at address stored inside p is "<<*p<<endl;

    float *q = new float(40.87);  //Storing the address if float(40) inside pointer variable q.
    cout<<"The value at address stored inside q is "<<*q<<endl;

    int *arr = new int[3];  //Creating an array of 3 integers dynamically and storing its address inside pointer variable 'arr'

    //Storing values inside the dynamically created array.
    arr[0]=10;      
    *(arr+1) = 20;  //Code doing the same work as arr[1]=20;
    arr[2]=30;

    //delete operator
    //***************
    //In C++, the delete keyword is used to deallocate memory that has been previously allocated using the `new` operator. It is used to destroy objects that were created on the heap memory (also known as the free store), and to release the memory they occupied so that it can be used by other parts of the program.
    delete arr;  //This deletes the entire dynamically created array 'arr' and frees the memory.
    cout<<"Value of arr[0] is "<<arr[0]<<endl;  //This will give Garbage Value because of -- delete[] arr;
    cout<<"Value of arr[1] is "<<arr[1]<<endl;  //This will give Garbage Value because of -- delete[] arr;
    cout<<"Value of arr[2] is "<<arr[2]<<endl;  //This will give Garbage Value because of -- delete[] arr;

    return 0;
}
```