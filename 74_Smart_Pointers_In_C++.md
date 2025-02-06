# Smart Pointers in C++

## The Problems with Normal Pointers

A **pointer** in C++ is a variable that holds the memory address of another variable.  To use a pointer you must point it to a memory location (using the `new` keyword or the `&` operator). However, the problem with normal (raw) pointers is that **you must manually free the memory location that the pointer is pointing to using the `delete` keyword**. **If you forget to do this**, the **memory location** that the pointer was pointing to **remains occupied for the entire duration of the program even if the pointer pointing to that memory location gets destroyed**. This is called a **memory leak** and over the time, this can lead to **memory exhaustion**.

```cpp
// C++ program to demonstrate the problem of using Normal Pointers
#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;
};

void fun()
{
    // Creating a nameless Rectangle class object in the heap memory using `new` keyword 
    // Creating a Rectangle class pointer variable `p` and pointing it towards the nameless Rectangle class object
    Rectangle* p = new Rectangle();
}

int main()
{
    // Infinite Loop
    while (1) {
        fun();
    }
}
```

### Output

```
Memory limit exceeded
```

### Explanation of the code: 

The function `fun` creates a pointer that is pointing to a Rectangle class object. Every Rectangle class object contains two integers - length and breadth. When the function `fun` ends, pointer `p` will be destroyed as it is a local variable. But, the memory location that this pointer was pointing to won’t be deallocated because we forgot to use the `delete p` code at the end of the function. That means everytime the function `fun` runs, it will steal a bit of memory every time and hold it for the entire duration for which the program is in execution.

In function `main`, `fun` is called in an infinite loop. That means it’ll keep creating Rectangle class pointer variables `p` and everytime point them towards a new nameless Rectangle class object. But, as soon as the function ends, it won’t free the memory occupied by the previous nameless Rectangle class object as we didn’t deallocate it manually using the `delete` keyword. Now, as long as the program is running, the memory that’s wasted can’t be used again, because we have lost the pointer pointing to the memory location, and we don't know where the block of memory is. This is a classic example of a **memory leak**. And since `While` loop runs infinitely, this will soon lead to the exhaustion of the entire heap memory.

## Smart Pointers

**Smart pointers** were introduced to address these issues. Smart Pointers are wrapper classes whose **objects** are used to **manage the memory of a dynamically allocated variable**. **When a smart pointer object goes out of scope, it automatically frees the memory it is pointing to, eliminating the need for manual memory management.**

## Types of Smart Pointers in C++

There are three standard smart pointers classes defined inside the `<memory>` header file of C++ Standard Library:

- `std::unique_ptr<T>` : A unique pointer object does not share ownership, and will free the resource at the end of the scope.
- `std::shared_ptr<T>` : A shared pointer object does share ownership, and will only free the resource when there are no other owners counted and it has reached the end of the scope.  It maintains a **Reference Counter** using the `use_count()` method.
- `std::weak_ptr<T>` : A weak pointer  object is created/used alongside a shared pointer object. It is similar to a shared_ptr object except when you create a weak_ptr object to a shared_ptr object, the reference count will not increase. Long story short, a weak_ptr does not own the memory and does not affect the reference count. The memory is freed when all shared_ptr owners are destroyed, even if weak_ptr objects are still referencing it.

## Unique Pointer

```cpp
//  C++ program to demonstrate the working of unique_ptr 
#include <iostream>
#include <memory>  // Necessary Header File for using Smart Pointer classes.

int main() {

    std::unique_ptr<int> u1(new int(1));
    std::unique_ptr<int> u2 = std::make_unique<int>(10);

    // std::unique_ptr<int> u4 = u2; // will give error
    std::unique_ptr<int> u3 = std::move(u1);
    // After this line, both the address and ownership of the int(1) object, are transfered from unique pointer object u1 to u3  and u1 becomes a nullptr.

    if(u1) {
        // will not be printed as u1 is null
        std::cout << *u1 << std::endl;
    }
    if(u2) {
        std::cout << *u2 << std::endl;
    }
    if(u3) {
        std::cout << *u3 << std::endl;
    }

    return 0;

    // No need to manually delete ptrs
    // The ptrs gets destroyed on reaching end of scope, no memory leaks
} 
```

## Shared pointer

```cpp
// C++ program to demonstrate the working of shared_ptr
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedInt = std::make_shared<int>(12);

    std::cout << *sharedInt << std::endl; // 12

    std::shared_ptr<int> sharedInt2 = sharedInt;

    std::cout << *sharedInt2 << std::endl; // 12

    *sharedInt2 = 100;

    std::cout << *sharedInt << std::endl; // 100
    
    // This'll print 2 as Reference Counter is 2
    std::cout << sharedInt.use_count() << std::endl;
    std::cout << sharedInt2.use_count() << std::endl;

    return 0;
}
```

## Weak Pointer

```cpp
#include <iostream>
#include <memory>

int main() {

    std::shared_ptr<int> sharedInt = std::make_shared<int>(42);
    std::weak_ptr<int> weakInt = sharedInt;

    std::cout << "Owners: " << sharedInt.use_count() << std::endl;
    // This'll print 1 as the weak pointer is not counted as an owner.
    // The memory gets released once the pointer sharedInt goes out of scope.

    if (auto shared = weakInt.lock()) {
        // The lock() method of std::weak_ptr attempts to create a std::shared_ptr that shares ownership of the managed object.
        // If the managed object still exists (i.e., it has not been destroyed), lock() returns a std::shared_ptr to the object.
        // If the managed object has been destroyed, lock() returns an empty std::shared_ptr.
        std::cout << "Value: " << *shared << std::endl;
    } else {
        std::cout << "Not available" << std::endl;
    }

    // freeing the shared pointer
    // since there is no other shared pointer that holds the ownership of the integer object `int(42)`, the object gets destroyed and the memory location held by the object is freed.
    // sharedInt.reset() decrements the reference count to 0, triggering deallocation.
    sharedInt.reset();

    if (auto shared = weakInt.lock()) {
        // Since the managed object `int(42)` has been destroyed, lock() returns an empty std::shared_ptr.
        std::cout << "Value: " << *shared << std::endl;
    } else {
        std::cout << "Not available" << std::endl;
    }

    return 0;
}
```