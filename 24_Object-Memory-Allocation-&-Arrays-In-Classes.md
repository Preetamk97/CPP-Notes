# Object Memory Allocation in C++:

The way memory is allocated to variables and functions of the class is different even though they both are from the same class.

The memory is only allocated to the variables of the class when the object is created. The memory is not allocated to the variables when the class is declared. Member variables can have different values for different objects, so every object has an individual copy of all the variables of the class. But the memory is allocated to the function only once when the class is declared. So the objects don’t have individual copies of functions only one copy is shared among each object.

---

# Using Arrays in Classes

## Code with comments.

```cpp
// An example program to demonstrate use of arrays inside a class.

#include <iostream>
#include <string> // Necessary import for creating string type variables.
using namespace std;

class Shop  
{

    // All Members/Attributes of a class by default are private until made explicitly public.

    string itemName[100]; // Attribute 1: An array 'itemName' to hold 100 string values.
    int itemPrice[100];   // Attribute 2: An array 'itemPrice' to hold 100 int values
    int counter;    // Sl.No of the Item added.

public:
    void initCounter(void) { counter = 0; }  // function to inialize the counter variable of the object.
    void getItem(void); // fucntion for displaying the complete list of items added.
    void setItem(void); // function for adding values to the 'itemName' and 'itemPrice' array of the object.
};

void Shop ::setItem()
{
    counter++; // counter gets incrmented by 1.

    cout << "Enter Item No." << counter << " Name: ";
    cin >> itemName[counter];
    cout << "Enter Item No." << counter << " Price: ";
    cin >> itemPrice[counter];
}

void Shop ::getItem()
{
    for (int i = 1; i <= counter; i++)
    {
        /* code */
        cout << endl;
        cout << "Item Name: " << itemName[i] << endl;
        cout << "Item Price: " << itemPrice[i] << endl;
        cout << endl;
    }
}

// Driver Code:
int main()
{
    Shop MunnaStore; // Creating object 'MunnaStore' of Shop class.

    MunnaStore.initCounter(); // Initializing counter = 0 for the object.

    // Calling setItem() 3 times. So, we can add 1 value to each 'itemName' and 'itemPrice' array -- back to back 3 times. Add whatever food item you want to your mini store!
    MunnaStore.setItem();
    MunnaStore.setItem();
    MunnaStore.setItem();

    // Displaying the list of items.
    MunnaStore.getItem();

    return 0;
}
```