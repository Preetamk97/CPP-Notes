```cpp
#include <iostream>
using namespace std;

//Function Templates
template <class T1, class T2>
double avgCalculator(T1 a, T2 b){   //We can use any dataType in place of T1 & T2.
    double avg = (a+b)/2.0;
    return avg;
}

// Driver Code
int main()
{
    double avg1 = avgCalculator(6.0,7.0);  //T1=float, T2=float
    cout << "avg1 = "<<avg1<<endl;

    double avg2 = avgCalculator(6,15.0);  //T1=int, T2=float
    cout << "avg2 = "<<avg2<<endl;

    return 0;
}
```