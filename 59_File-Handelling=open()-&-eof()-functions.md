```cpp
#include <iostream>
#include <fstream>

using namespace std;

// Driver Code
int main()
{
    //Creating a File - Method 1 : Using ofstream class constructor.
    //**************************************************************
    // ofstream write("Sample.txt");

    //Creating a File - Method 2 : Using open() method of ofstream class.
    //********************************************************************
    ofstream write; //Creating the write object of ofstream class.
    write.open("Sample.txt");  //Use of open()
    write<<"Hello World!\n";
    write<<"My name is Pritam.\n";
    write<<"Nice to meet you all!\n";
    write<<"Yoroshiku ne!";
    write.close();

    //Use of open() method for READ operation.
    ifstream read;
    read.open("Sample.txt");  //open() is also available in ifstream class.
    string str;

    //Reading one new line at a time.
    //*********************************
    // getline(read, str); 
    // cout<<str<<endl;

    //Reading the complete text file to the end in one go.
    //****************************************************
    while(read.eof() == 0){  //eof = end of file  //0 = false  //while(read.eof() == false)
        getline(read, str);
        cout<<str<<endl;
        //This loop will read the complete file in one go.
    }
    
    read.close();

    return 0;
}
```