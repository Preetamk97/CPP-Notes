# C++ String c_str() Function

The **c_str()** function in C++ is a method of **std::string** class that converts a string to an array of characters and terminates this array with a null character at the end.  It is present in the "cstring" header of the C++ library, so to use the c_str() function, we must include the "cstring" header. The function does not accept any parameters. It returns a pointer to this array of characters.

## Syntax of String c_str() in C++

```cpp
str.c_str();    // str is a string
```

## Example Porgram: 

```cpp
// C++ code for illustration of
// std::string::c_str() function
#include <bits/stdc++.h>
#include <string>
 
int main()
{
    // declare a example string
    std::string s1 = "Aditya";
 
    // print the characters of the string
    for (int i = 0; i < s1.length(); i++) {
        cout << "The " << i + 1 << "th character of string " << s1
            << " is " << s1.c_str()[i] << endl;
    }
}
```