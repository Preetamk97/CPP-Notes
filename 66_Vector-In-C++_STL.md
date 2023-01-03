```cpp
#include <iostream>
#include <vector> //Including the header file <vector> is necessary for using the std::vector class template.
#include <array>  // Including the header file <array> is necessary for using the std::array class template.

// std::array is a class template provided by the Standard Template Library (STL) that provides a fixed-size array-like container for holding a sequence of elements. std::array has several features that make it more flexible and convenient to use than a traditional array data type:

// 1. It has a defined size() function that returns the number of elements in the array.
// 2. It has begin() and end() functions.
// 3. It has iterators, so you can use it with algorithms and other STL containers.

// std::vector is a sequence container class template in the Standard Template Library (STL) that provides a dynamic array-like container for holding a sequence of elements. std::vector has the following features:

// 1. It has a defined size() function that returns the number of elements in the vector.
// 2. It has begin() and end() functions that return iterators pointing to the first and one past the last element of the vector, respectively.
// 3. It has iterators, so you can use it with algorithms and other STL containers.
// 4. It can grow and shrink dynamically as elements are added or removed (using push_back() & pop_back), so you do not need to specify the size of a std::vector when it is created. This feature is NOT available for std::array

template <class T> // Function Template for displaying the data of a vector object.
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++) // Using size() method of the vector
    {
        /* code */
        cout << v[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Different ways of creating a vector object.
    //******************************************

    // Default constructor: creates an empty vector with no elements
    vector<int> v1;

    // Empty vector vec1 for holding 4-character elements [ vec1.size()=4 ] 
    vector<char> vec1(4);

    // Initializer list constructor: creates a vector with the specified elements
    vector<int> v2{1, 2, 3};
    display<int>(v2); // 1 2 3

    // Size and value constructor: creates a vector with the specified size and initializes all elements to the specified value
    vector<int> v3(10, 0); // Creates a vector of 10 integers, all initialized to 0
    display<int>(v3); // 0 0 0 0 0 0 0 0 0 0

    // Range constructor: creates a vector with the elements in the specified range
    array<float, 3> a{1.0, 2.5, 3.14};
    vector<float> v4(a.begin(), a.end()); // Creates a vector with elements {1.0, 2.5, 3.14}
    display<float>(v4); // 1 2.5 3.14

    // Copy constructor: creates a vector as a copy of another vector
    vector<int> v5{1, 2, 3, 4, 5};
    vector<int> v6(v5); // Creates a copy of v5
    display<int>(v6); // 1 2 3 4 5

    // Move constructor: creates a vector by moving the elements from another vector
    vector<int> v7{1, 2, 3, 4, 5, 6, 7};
    vector<int> v8(move(v7)); // Creates a vector by moving the elements from v1
    display<int>(v7);
    display<int>(v8);  // 1 2 3 4 5 6 7

    /*
    Difference between an array and a vector
    ******************************************

    In C++, an array is a built-in data type that holds a fixed-size sequence of elements of the same type. Arrays are defined using the square brackets [], and their size must be specified when they are created. For example:

    int a[5];  // Defines an array of 5 integers
    double b[10];  // Defines an array of 10 doubles

    One benefit of using vectors over arrays, is that vectors can be dynamically modified i.e. we can insert as many elements we want in a vector, without having to put some size parameter like in an array. In an array of 10 elements, we cannot add an 11th element, but in a vector we do not have to care about any size limitation.

    Vectors provide certain methods to be used to access and utilise the elements of a vector, first one being, the push_back method. To access all the methods and member functions in detail, you can visit this site , std::vector - C++ Reference. This will be very handy and useful to you.
    */


    // push_back() method:
    // *******************
    // Adding elements to a vector
    // We can add as many elements as we want to the v2 vector using the .push_back() method without having to care for any size limitation like in array.

    // vector<int> v2{1, 2, 3};
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    display<int>(v2); // 1 2 3 1 2 3

    // size() method:
    // **************
    cout << v2.size() << endl; // 6

    // pop_back():
    //**********
    //  Deletes the last element of the vector.
    v2.pop_back();
    display<int>(v2); // 1 2 3 1 2

    //Using an iterator & insert() method
    //**********************************
    vector<int> :: iterator iter = v2.begin();  //Create an iterator for a vector of <int> dataType named 'iter' and point it at the first element of the vector v2.
    cout<<*iter<<endl; // 1
    v2.insert(iter+1, 566); //Insert number 566 at the 2nd place of vector v2.
    display<int>(v2); // 1 566 2 3 1 2

    // .at() method:  
    //**************
    // v.at(i) can be used instead of v[i]. They will work the same.
    cout<<v2[1]<<endl; // 566
    cout<<v2.at(1)<<endl; // 566

    return 0;
}
```