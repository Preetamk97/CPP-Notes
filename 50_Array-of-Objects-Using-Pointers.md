```cpp
#include <iostream>
using namespace std;

class ShopItem{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Id of the item is "<<id<<endl;
            cout<<"Price of the item is "<<price<<endl;
        }
};

// Driver Code
int main()
{
    int size = 3;
    ShopItem *ptr = new ShopItem[size];  //1. Alllocating a 'memory block collection' for holding an array of 3 Shop class objects.
                                         //2. Storing the address of the first memory block (or address of the first object of the array) inside the Shop class pointer variable *ptr. (1, 2, 3)
                                         //                                                                 ^

    ShopItem *ptrTemp = ptr;    //'ptr' pointer currently stores the memory address of the very first object of the ShopItem array. 
                                //In the for loop below, we are going to increment the value of this pointer variable 'ptr' -- in each iteration -- ptr++; -- so that it points to the next object in the ShopItem array (for next iteration).
                                //Now, before doing any change/tempering with the value of 'ptr' - inside for loop,  by doing the step `ShopItem *ptrTemp = ptr;` -- we are saving/storing the memory address of the first object of the ShopItem array (i.e the current value of the ptr pointer) inside pointer ptrTemp so that we can use use it later on (inside the next for loop).
    
    int p;  //This variables will be used to store user input for item id.
    float q;  //This variables will be used to store user input for item price.

    for (int i = 0; i < size; i++)  //3 Objects --> 3 Itertations
    {
        /* code */
        cout<<"Enter the id for item no "<<i+1<<" : ";
        cin>>p;
        cout<<"Enter the price for item no "<<i+1<<" : ";
        cin>>q;
        // (*ptr).setData(p,q);  //Dereferencing the pointer variable 'ptr'.
        ptr->setData(p,q);  //Dereferencing the pointer variable 'ptr'--- using Arrow operator.
        ptr++;  //Moving the pointer to the next object of the array.

        //1st Iteration:
        //1  2  3
        //^
        //|  
        //ptr
        //ptr++

        //2nd Iteration:
        //1  2  3
        //   ^
        //   |  
        //   ptr
        //ptr++

        //3rd Iteration:
        //1  2  3
        //      ^
        //      |  
        //      ptr
        //ptr++

        //4th Iteration:
        //1  2  3  (Garbage Value)
        //         ^
        //         |  
        //         ptr
    }
    
    for (int i = 0; i < size; i++)  //3 Objects --> 3 Itertations
    {
        /* code */
        cout<<"Item no "<<i+1<<" :"<<endl;
        ptrTemp->getData();
        ptrTemp++;

        //1st Iteration:
        //1  2  3
        //^
        //|  
        //ptrTemp
        //ptrTemp++

        //2nd Iteration:
        //1  2  3
        //   ^
        //   |  
        //   ptrTemp
        //ptrTemp++

        //3rd Iteration:
        //1  2  3
        //      ^
        //      |  
        //      ptrTemp
        //ptrTemp++

        //4th Iteration:
        //1  2  3  (Garbage Value)
        //         ^
        //         |  
        //         ptrTemp
    }
    
    return 0;
}
```