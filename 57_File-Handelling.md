# Creating a .txt file and writing to it

```cpp
#include <iostream>
#include <fstream>  //Header file <fstream> includes some classes that are useful in working with files in C++.

//The useful classes for working with files in C++ are:
//1. fstreambase 
//2. ifstream  --> derived from fstreambase --> for reading a file.
//3. ofstream  --> derived from fstreambase --> for creating a file and writing to it.

using namespace std;

// Driver Code
int main()
{
    //Creating a txt file and writing text to it.
    //********************************************
    string str = "Harry Bhai!\nYou are a wonderful teacher!";
    ofstream write("Sample.txt");  //Creating an object 'write' of 'ofstream' class and giving it the name of the file that we want to create i.e (Sample.txt) as a string argument.
    write<<str;  //Adding our string to the file using 'write' object.
    //This creates a file 'Sample.txt' - which contains our desired string 'str' value - in the same folder that contains our play.cpp file.

    return 0;
}
```

# Reading a .txt file

```cpp
#include <iostream>
#include <fstream>

using namespace std;

// Driver Code
int main()
{
    //Reading a text file.
    //*********************
    string str2; //Creating a string variable for storing the file contents that will be read.
    ifstream read("Sample.txt");  //Reading operation
    //read>>str2;  //This stores everything brfore a space in text.
    getline(read, str2);  //The compiler reads one new line (without any line break) at a time from Sample.txt & stores inside str2.
    cout<<str2<<endl;
    //If there are more than one new lines in Sample.txt - then, for reading each new line, run the same 2 lines of code again.
    getline(read, str2);  
    cout<<str2<<endl;

    return 0;
}
```

## Note: We cannot do both Writing & Reading operations in the same program. 