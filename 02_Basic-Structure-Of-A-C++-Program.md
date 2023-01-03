# Learning Objectives:

- History of C++  
- Why use C++
- Basic Structure of a C++ Program.
---

# History of C++: 

C++ was developed by **Bjarne Stroustrup** at **Bell Laboratories** over a period starting in **1979**. Since C++ is an attempt to add object-oriented features (plus other improvements) to C, earlier it was called as ***“C with Objects”***. As the language developed, Stroustrup named it as C++ in 1983.

---

# Why use C++:

1.  With C++, we can create fast programs.
1.  C++ gives us more control over our system resources (hardware components).
1.  C++ gives us control of our system's memory managememnt.
1.  High Performance.

---

# Basic Structure of a C++ Program

In our previous lecture, we had written and executed a small C++ program. Today we are going to discuss that program in more detail.

```cpp
#include <iostream>
/*
1.  "#include<iostream>" - this whole text is called a header file.
In this line of code include is a keyword used to add libraries in our program. "iostream" is the name of a library, added to our program. The iostream library helps us to get input data and show output data. The iostream library also has many more uses; it is not only limited to input and output but for now, we will not go into more detail on this.  

2.  It doesn't matter how many lines you have left empty in a C++ program, the compiler will ignore those lines and only check the ones with the code.
*/

// using namespace std;

int main(){
/* 
In this line of code, "int" is a return type which is called integer and "main()" is a function, the brackets "()" denotes that it is a function. The curly brace "{" indicates that it is an opening of a function, and the curly brace "}" indicates that it is the closing of a function. Here I will give you an example to better understand the functionality of "int main()." Imagine that you own a coffee shop, and you have some employees who work for you. Let's name (Anna, Blake, Charlie) as the three employees. The function of Anna is to take orders, the function of Blake is to make coffee, and Charlie's function is to deliver coffee. Now when Anna gets a coffee order, she will call Blake to make the coffee, and when the coffee is ready, Blake will call Charlie to deliver the coffee. In this scenario, we can say that Anna is the primary function from which all the other tasks will start, and coffee is our return value (Something charlie finally gives to Blake). In this line of code, "main" is a reserved keyword, and we cannot change it to some other keyword.
*/

    // cout << "Hello World";

    std :: cout << "Hello World";
    /* 
    In this line of code "std" is a namespace, "::" is the scope resolution operator and "cout<<" is a function which is used to output data, "hello world" is our output string and ";" is used to end a statement (terminator). The code "std::cout" tells the compiler that the "cout" identifier (Identifier is a collective name used for functions, class, variables) resides in the std namespace.
    */

    /*
    You can write as many statements as you want in a single line, but I recommend you write one statement per line to keep the code neat and clean.
    */

    return 0;
    /* 
    In this line of code, the return keyword will return 0 as an integer to our main function "int main()" as we have discussed before. Returning 0 as a value to the main function means successful termination of the program.
    */
}
```