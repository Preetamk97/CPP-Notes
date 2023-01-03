# Difference between Vector and List:

A **std::vector** is implemented as a contiguous block of memory, with each element stored one after the other. This allows fast random access to the elements using the index operator []. The std::vector also has a capacity, which is the amount of memory that has been allocated to store its elements. When the capacity is exceeded, the std::vector needs to allocate more memory, which can be a time-consuming operation.

![](Img_Files\chapter67\vector.png)

A **std::list** is implemented as a doubly linked list, with each element stored in a separate node. Each node contains a pointer to the previous and next nodes in the list, as well as the element itself. The std::list does not have a capacity, as it does not store its elements in a contiguous block of memory. Instead, it allocates a new node for each element that is added to the list. This makes std::list less efficient when it comes to accessing elements, but it is more efficient when it comes to inserting and removing elements, as it does not need to shift elements around.

![](Img_Files\chapter67/Singly-linked-list.png)


In C++, `std::list` and `std::vector` are both sequence containers, which means that they are used to store collections of elements in a specific order. However, there are several key differences between std::list and std::vector:

**Size and capacity**: std::vector has a fixed size/capacity (which is the amount of memory that has been allocated to store its elements), which means that once it is created, its size cannot be changed. In contrast, std::list has a dynamic size, which means that its size can change as elements are added or removed. When the capacity is exceeded, std::vector needs to allocate more memory, which can be a time-consuming operation. std::list does not have a capacity, as it does not store its elements in a contiguous block of memory.

**Accessing elements**: std::vector provides fast random access to its elements using the index operator []. This means that you can access any element in a std::vector in constant time (O(1)) by its index. In contrast, std::list does not provide random access to its elements. Instead, you can only access its elements by iterating through the list sequentially, which has a linear time complexity (O(n)).

**Inserting and removing elements**: std::vector is not optimized for inserting and removing elements from the middle of the container, as this requires shifting the elements around to make room for the new element or fill the gap left by the removed element. In contrast, std::list is optimized for inserting and removing elements, as it does not need to shift elements around.

**Memory usage**: std::vector uses more memory than std::list, as it stores its elements in a contiguous block of memory and needs to allocate additional memory when its capacity is exceeded. std::list uses less memory, as it stores its elements as a linked list, which requires only a small amount of additional memory per element to store the pointers to the next and previous elements.

**Performance**: std::vector is generally faster than std::list when it comes to accessing elements and performing operations that do not involve inserting or removing elements. However, std::list is generally faster than std::vector when it comes to inserting and removing elements, especially when these operations are performed frequently.

In summary, std::list and std::vector are both useful containers, but they have different strengths and are suitable for different types of tasks. std::vector is best suited for cases where you need fast random access to the elements and do not need to frequently insert or remove elements, while std::list is best suited for cases where you need to frequently insert or remove elements but do not need fast random access to the elements.

# Lesson Code:

```cpp
#include <iostream>
#include <list> //Necessary import for using class template `std::list` of C++ STL.
using namespace std;

void display(list<int> lst)
{
    // Creating an iterator for list<int> class.
    list<int>::iterator iter;
    iter = lst.begin(); // Pointing the iterator 'iter' upon the first element of lst.

    // Iterating through the list using iterator 'iter'.
    for (iter = lst.begin(); iter != lst.end(); iter++)
    {
        /* code */
        cout << *iter << " ";

        // lst :  10          20       30        40         50           _
        //         ^           ^        ^        ^           ^           ^
        //         |           |        |        |           |           |
        // iter=lst.begin()   iter+1    iter+2   iter+3     iter+4  iter+5 = lst.end()
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Way1:
    list<int> list1; // List of length 0.

    // Adding elements to the list.
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_back(40);
    list1.push_back(50);

    // //Creating an iterator for list<int> class.
    // list<int> :: iterator iter;
    // iter = list1.begin();  //Pointing the iterator 'iter' upon the first element of list1.

    // //Printing the items of list1 using the iterartor
    // cout<<*iter << " ";  //iter = 0  //10
    // iter++;
    // cout<<*iter << " ";  //iter = 1  //20
    // iter++;
    // cout<<*iter << " ";  //iter = 2  //30
    // iter++;
    // cout<<*iter << " ";  //iter = 3  //40
    // iter++;
    // cout<<*iter << " ";  //iter = 4  //50
    // cout<<endl;

    display(list1); // 10 20 30 40 50

    // Removing elements from the back of the list
    list1.pop_back();
    list1.pop_back();
    display(list1); // 10 20 30

    // Removing elements from the front of the list
    list1.pop_front();
    display(list1); // 20 30

    // Way 2:
    list<int> list2(4); // Empty list of length 4.
    list<int>::iterator iter2;
    iter2 = list2.begin();

    // Adding element to list2 using iterator.
    *iter2 = 100;
    iter2++;
    *iter2 = 200;
    iter2++;
    *iter2 = 200;
    iter2++;
    *iter2 = 400;

    display(list2); // 100 200 200 400

    // Removing elements of a list in between.
    list2.remove(200); //This will remove all occrurences of 200 from the list2.\
    display(list2);  //100 400

    // Way 3:
    list<int> list3{5, 7, 19, 12, 6, 8};
    display(list3); // 5 7 19 12 6 8

    // Use of sort() method:
    list3.sort();
    display(list3); // 5 6 7 8 12 19

    // Merging of 2 lists.
    list<int> list4{23, 15, 45, 73, 36};
    list3.merge(list4);
    display(list3); // 5 6 7 8 12 19 23 15 45 73 36

    // Reversing a list.
    list3.reverse();
    display(list3); // 36 73 45 15 23 19 12 8 7 6 5

    // Random Accces of an element in a list.
    // list does not support random access using [] operator like vectors and arrays.
    // So, we do it using iterator.
    list<int>::iterator iter3 = list3.begin();
    // Access the third element in the list3 (index 2)
    advance(iter3, 2);      // Iterator Jumps 2 steps
    cout << *iter3 << endl; // 45

    // Swaping of 2 lists.
    list<int> a1{1, 2, 3, 4, 5}, a2{6, 7, 8};
    cout << "Before swapping :" << endl;
    cout << "a1 : ";
    display(a1);
    cout << "a2 : ";
    display(a2);
    a1.swap(a2);
    cout << "After swapping :" << endl;
    cout << "a1 : ";
    display(a1);
    cout << "a2 : ";
    display(a2);
    /*
    Before swapping :
    a1 : 1 2 3 4 5
    a2 : 6 7 8
    After swapping :
    a1 : 6 7 8
    a2 : 1 2 3 4 5
    */

    return 0;
}
```