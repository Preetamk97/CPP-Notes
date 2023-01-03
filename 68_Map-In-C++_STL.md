```cpp
#include <iostream>
#include <map> //Necessary import for using class template `std::map` of C++ STL.
using namespace std;

// `std::map` is an associative-container type class template provided by C++ STL.

// Driver Code
int main()
{
    map<string, int> marksMap;

    //Storing data in marksMap.
    marksMap["Pritam"] = 100;
    marksMap["Harry"] = 96;
    marksMap["Shubham"] = 45;

    // Creating a iterator and pointing it to the 1st entry of marksMap.
    map<string,int> :: iterator iter;
    //Printing the marksMap data to console.
    for (iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        /* code */
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }

    /*OUTPUT::
    Harry 96
    Pritam 100
    Shubham 45
    */

    //Since the key "Harry" is lexicographically smaller than the key "Pritam", it appears before "Pritam" in the map. 

    //.insert Method
    //**************
    marksMap.insert({{"Saniya", 87}, {"Mohan", 78}});
    for (iter=marksMap.begin(); iter!=marksMap.end(); iter++)
    {
        /* code */
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }
    /*
    Harry 96
    Mohan 78
    Pritam 100
    Saniya 87
    Shubham 45
    */

   //.size() Method
   //**************
   cout<<"The size is "<<marksMap.size()<<endl;  //5

   //.empty() = checks if the map is empty or not = 0 is false/not empty, 1 is true/empty
   cout<<"marksMap.empty() = "<<marksMap.empty()<<endl;  // 0 = false/not empty

    return 0;
}
```