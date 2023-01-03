```cpp
#include <iostream>
using namespace std;

/*
template <class T1, class T2>
class className {
    // body
}
*/

// class myClass {
//     int a;
//     char b;
//     public:
//         myClass(int a, char b){
//             this->a = a;
//             this->b = b;
//         }
//         void display(void){
//             cout<<a<<endl;
//             cout<<b<<endl;
//         }
// }

template <class T1, class T2>
class myClass {
    T1 a;
    T2 b;
    public:
        myClass(T1 a, T2 b){
            this->a = a;
            this->b = b;
        }
        void display(void){
            cout<<a<<endl;
            cout<<b<<endl;
        }
};

// Driver Code
int main()
{
    myClass <double, string> o1(4.589, "Harry"); 
    o1.display();
    // 4.589
    // Harry

    myClass <float, char> o2(9.999, '@');
    o2.display();
    // 9.999
    // @

    return 0;
}
```