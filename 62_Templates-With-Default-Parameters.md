```cpp
#include <iostream>
using namespace std;

template <class T1=int, class T2=char>  //Template with default parameters
class Pritam {
    T1 a;
    T2 b;
    public:
        Pritam(T1 a, T2 b){
            this->a = a;
            this->b = b;
        }
        void display(void){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
        }
};

// Driver Code
int main()
{
    Pritam <> o1(25,'X');  //While creating an instance, if we do not specify any dataType for parameters T1 & T2, the compiler will act as per the given default template parameters (T1=int, T2=char) and create the object accordingly.
    o1.display();
    cout<<endl;

    Pritam <float, string> o2(3.14, "Mechanical Engineer");  //However, if we specify the dataTypes for the template, the compiler acts accordingly and creates the instance as per.
    o2.display();
    
    return 0;
}
```