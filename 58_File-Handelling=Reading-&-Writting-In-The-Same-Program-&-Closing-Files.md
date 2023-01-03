```cpp
#include <iostream>
#include <fstream>

using namespace std;

// Driver Code
int main()
{
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    string text = "Hello! Your name is "+name;

    ofstream write("Sample.txt"); 
    write<<text;
    write.close();  //Once we close the write object, we can start a new read/write operation below in the same program. So, closing the write object is important.

    ifstream read("Sample.txt");
    string read_text;
    getline(read, read_text);
    cout<<read_text<<endl;
    read.close();  //Once we close the read object, we can start a new read/write operation below in the same program. So, closing the read object is important.

    return 0;
}
```