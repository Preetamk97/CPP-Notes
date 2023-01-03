# A Simple Program To Calculate Dot Product Of Two 3D Vectors:

```cpp
#include <iostream>
using namespace std;

class vector {
    public:
        int *arr;   //int *arr = new int[size]
        int size;
        vector(int m){
            size = m;
            arr = new int[size];
        }
        int dotProduct(vector v){   //Calculating dot product of two 3D vectors
            int product = 0;
            for (int i = 0; i < size; i++)
            {
                /* code */
                product += this->arr[i] * v.arr[i];
            }
            return product;
        }
};

// Driver Code
int main()
{
    vector v1(3);
    v1.arr[0]=5;
    v1.arr[1]=10;
    v1.arr[2]=15;  //v1 = 5i + 10j + 15k

    vector v2(3);
    v2.arr[0]=2;
    v2.arr[1]=4;
    v2.arr[2]=8;  //v2 = 2i + 4j + 8k

    int product = v1.dotProduct(v2);
    cout<<product<<endl;

    return 0;
}
```

# Same Program Using C++ Template:

```cpp
#include <iostream>
using namespace std;

template <class T>  //T can be any dataType.
class vector {
    public:
        T *arr;   //T *arr = new T[size]
        int size;
        vector(int m){
            size = m;
            arr = new T[size];
        }
        T dotProduct(vector v){   //Calculating dot product of two 3D vectors
            T product = 0;
            for (int i = 0; i < size; i++)
            {
                /* code */
                product += this->arr[i] * v.arr[i];
            }
            return product;
        }
};

// Driver Code
int main()
{
    vector <int> v1(3);  //When we create an instance of the class, we must specify the dataType to be used in place of T.  //This is going to create an 'int' type array of size 3.
    v1.arr[0]=5;
    v1.arr[1]=10;
    v1.arr[2]=15;  //v1 = 5i + 10j + 15k

    vector <int> v2(3);
    v2.arr[0]=2;
    v2.arr[1]=4;
    v2.arr[2]=8;  //v2 = 2i + 4j + 8k

    int product1 = v1.dotProduct(v2); 
    cout<<product1<<endl;

    //Now the advantage of using C++ Templates is that we can use the same class code with any dataType in place of T.
    //Demo:
    vector <float> v3(3);  //This is going to create a 'float' type array of size 3.
    v3.arr[0]=0.1;
    v3.arr[1]=5.64;
    v3.arr[2]=2.23;  //v3 = 0.1i + 5.64j + 2.23k

    vector <float> v4(3);
    v4.arr[0]=6.63;
    v4.arr[1]=8.79;
    v4.arr[2]=1.8;  //v4 = 6.63i + 8.79j + 1.8k

    float product2 = v3.dotProduct(v4);
    cout<<product2<<endl;

    return 0;
}
```