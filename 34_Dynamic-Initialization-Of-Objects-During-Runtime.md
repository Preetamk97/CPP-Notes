The **dynamic initialization of the object** means that the object is initialized at the **runtime**.  Dynamic initialization of the object using a constructor is beneficial when the data is of different formats. An example program is shown below to demonstrate the concept of dynamic initialization of objects using constructors.

```cpp
#include <iostream>
using namespace std;

class BankDeposit {
    int principal;
    int years;
    float interestRate;
    float returnAmount;

    public:
        BankDeposit(){};   // default constructor of the “BankDeposit” class is declared. 
        // When we have parametrized constructors in our class, we will not be able to create non-parameterized objects of BankDeposit class (like BankDeposit deposit;), unless we also explicitly add a parameterless contructor - to instruct the program what to do when it is called.

        // Constructor Overloading
        // 2ND parameterized constructor of the “BankDeposit” class is declared which takes three parameters “p”, “y”, and “r”. The main thing to note here is that the parameter “r” is of a float data type.
        BankDeposit(int p, int y, float r){  // interestRate can be value like 0.4, 0.8, 0.11 etc.
            principal = p;
            years = y;
            interestRate = r;
            returnAmount = p;

            for (int i = 0; i < years; i++)
            {
                /* code */
                returnAmount = returnAmount + (returnAmount*interestRate/100); // Compound Interest
            }
            
        }

        // Constructor Overloading
        // 3RD parameterized constructor of the “BankDeposit” class is declared which takes three parameters “p”, “y”, and “R”. The main thing to note here is that the parameter “R” is of an integer data type.
        BankDeposit(int p, int y, int R){  // interestRate can be value like 40%, 80%, 11% etc.
            principal = p;
            years = y;
            interestRate = R; // We CAN store an integer inside a float type variable.
            returnAmount = p; // We CAN store an integer inside a float type variable.

            for (int i = 0; i < years; i++)
            {
                /* code */
                returnAmount = returnAmount + (returnAmount*(interestRate/100));   // Compound Interest
            }
        }

        void show(void){
            cout << "Principal : " << principal << endl;
            cout << "Years : " << years << endl;
            cout << "Interest Rate : " << interestRate << endl;
            cout << "Return Value : " << returnAmount << endl;
        }
};

// Driver Code:
int main()
{   
    // Creating BankDeposit class objects.
    BankDeposit deposit1, deposit2, deposit3;

    int p;  // For taking input value for principal
    int y;  // For taking input value for years
    float r; // For taking input value for (float)interestRate 
    int R;  // For taking input value for (int)interestRate 

    cout << "Enter Principal : " << endl;
    cin >> p;
    cout << "Enter Years : " << endl;
    cin >> y;
    cout << "Enter Interest Rate (float) : " << endl;
    cin >> r;
    cout<<endl;

    deposit1 = BankDeposit (p,y,r); // The desicion of using the constructor 'BankDeposit(int p, int y, float r)' is made during runtime - after compilation - based on the user Input.
    deposit1.show();
    cout<<endl;

    cout << "Enter Principal : " << endl;
    cin >> p;
    cout << "Enter Years : " << endl;
    cin >> y;
    cout << "Enter Interest Rate (int) : " << endl;
    cin >> R;
    cout<<endl;

    deposit2 = BankDeposit(p,y,R); // The desicion of using the constructor 'BankDeposit(int p, int y, int R)' is made during runtime - after compilation - based on the user Input.
    deposit2.show();
    cout << endl;

    deposit3.show();  // This will give garbage values for principal, years, interestRate, and returnAmount attributes.

    return 0;
}
```