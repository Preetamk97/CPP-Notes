# Learning Objectives:

- History of C++  
- Why use C++
- Basic Structure of a C++ Program.
---

# History of C++: 

**Bjarne Stroustrup** is the **creator** of the **C++ programming language**. He began working on C++ in 1979 at AT&T Bell Labs. Stroustrup was inspired by the **Simula** programming language, which he used to write a simulator for his Ph.D. thesis at Cambridge University. He created C++ to combine the procedural programming features of C with the object-oriented features of Simula. The initial version was called ***C with Classes***. As the language developed, Stroustrup named it as C++ in 1983.

---

# Why use C++:

1.  With C++, we can create fast programs.
1.  C++ gives us more control over our system resources (hardware components).
1.  C++ gives us control of our system's memory managememnt.
1.  High performance programming language with very high speeds of program excecution.

---

# Basic Structure of a C++ Program

In our previous lecture, we had written and executed a small C++ program. Today we are going to discuss that program in more detail.

```cpp
#include <iostream>
/*
1. "<iostream>" - is called a library header file.
    The iostream header file and many similar C++ library header files used in C++ programming can be found at the location (C:\msys64\mingw64\include\c++\12.1.0) inside the msys2 compiler installation folder.

2. 'include' is a keyword used to add header files into our C++ program.

3. "iostream" is the name of the header file, added to our program. The iostream libraryn header file helps us to get input data (through its object cin) and show output data (through its object cout). The iostream library also has many more uses; it is not only limited to input and output but for now, we will not go into more detail on this.  

4.  It doesn't matter how many lines you have left empty in a C++ program, the compiler will ignore those lines and only check the ones with the code.
*/

// using namespace std;

int main(){
/* 
In this line of code, "int" is a return type which is an integer and "main()" is a function, the brackets "()" denotes that it is a function. The curly brace "{" indicates that it is an opening of a function, and the curly brace "}" indicates that it is the closing of a function. Here I will give you an example to better understand the functionality of "int main()." Imagine that you own a coffee shop, and you have some employees who work for you. Let's name (Anna, Blake, Charlie) as the three employees. The function of Anna is to take orders, the function of Blake is to make coffee, and Charlie's function is to deliver coffee. Now when Anna gets a coffee order, she will call Blake to make the coffee, and when the coffee is ready, Blake will call Charlie to deliver the coffee. In this scenario, we can say that Anna is the primary function from which all the other tasks will start, and coffee is our return value (Something charlie finally gives to Blake). In this line of code, "main" is a reserved keyword, and we cannot change it to some other keyword.
*/

    // cout << "Hello World";

    std :: cout << "Hello World";
    /* 
    In this line of code "std" is a C++ standard library namespace, "::" is the scope resolution operator and "cout" is an object that is part of the C++ standard library namespace (std), '<<' is the output operator (also known as the insertion operator). Together "cout <<" sends the string "Hello World" to the standard output stream (usually the console). ";" is used to end a statement (terminator). The part "std::cout" tells the compiler that the "cout" identifier (Identifier is a collective name used for functions, classes, variables and objects) is part of the std namespace.
    */
   
    return 0;
    /* 
    In this line of code, the return keyword will return 0 as an integer to our main function "int main()" as we have discussed before. Returning 0 as a value to the main function means successful termination of the program.
    */
}
```