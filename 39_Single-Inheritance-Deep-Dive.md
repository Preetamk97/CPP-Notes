```cpp
#include <iostream>
using namespace std;

class Base {
   int data1; // private by default --- cannot be inherited.
   public:
      int data2;
      void setData();
      int getData1();
      int getData2();
};

void Base :: setData(void){   // This function is public -- has access to both private variable data1 & public variabble data2 of Base class.
   data1 = 10;
   data2 = 20;
}

int Base :: getData1(void){
   return data1;
}

int Base :: getData2(void){
   return data2;
}

class Derived : public Base {   //class is derived publically
   int data3;  // private
   public:
      void process();
      void display();
};

void Derived :: process (void){
   data3 = data2 * getData1();
   // process() method has access to private variable 'data3' of the Derived class.
   // Derived class has inherited the public variable 'data2' of Base class as a public member -- this gives access of data2 variable to process() method also.
   // Although 'data1' is a private variable of the Base class -- which cannot be inherited by the Derived class otherwise -- but data1 can be accessed by the public 'getData1()' method of Base class itself -- which has been inherited by the Derived class as a public method. This gives access of 'getData1()' method to the process() method -- which also belongs to the Derived class.
}

void Derived :: display(void) {
   cout << "The value of data1 is "<< getData1()<<endl;
   // 'Derived :: display(void)' method has access to 'getData1()' method of Base class-- 'getData1()' method has access to 'data1' private variable of Base class.
   cout<< "The value of data2 is "<< data2 << endl;
   // 'data2' is a public variable of Base class which is inherited as a public variable of Derived class.
   cout << "The value of data3 is "<< data3 << endl;
   // 'data3' is a private variable of Derived class -- which is accessible by the 'Derived :: display(void){}' method.
}

// Driver Code:
int main()
{
   Derived der;
   der.setData(); // data1 = 10, data2 = 20
   der.process(); // data3 = data2 * getData1() = 10 * 20  = 200

   der.display(); //The value of data1 is 10
                  //The value of data2 is 20
                  //he value of data3 is 200
   return 0;
}
```


```cpp
#include <iostream>
using namespace std;

class Base {
   int data1;
   public:
      int data2;
      void setData();
      int getData1();
      int getData2();
};

void Base :: setData(void){
   data1 = 10;
   data2 = 20;
}

int Base :: getData1(void){
   return data1;
}

int Base :: getData2(void){
   return data2;
}

class Derived : private Base {   // Inheriting Base class public members as private members of Derived class.
   int data3;
   public:
      void process();  // Can use data2, setData(), getData1(), getData2()
      void display();  // Can use data2, setData(), getData1(), getData2()
};

void Derived :: process (void){
   setData(); // setData() (originally public method of Base class) is inherited as a private member of Derived class -- can be used inside process() method directly.
   // This will set the value of data1 (private) & data2 (public).
   data3 = data2 * getData1();
}

void Derived :: display(void) {
   cout << "The value of data1 is "<< getData1()<<endl;
   cout<< "The value of data2 is "<< data2 << endl;
   cout << "The value of data3 is "<< data3 << endl;
}

// Driver Code:
int main()
{  
   Derived der;

   // der.setData();  // Since setData() (originally public method of Base class) is inherited as a private member of Derived class --- therefore cannot be used outside the Derived class -- i.e inside 'int main()' method directly.
   // Instead we can call setData() method inside process() method itself.

   der.process(); // process() is a public member of Derived class -- can be used directly inside 'int main()'
   der.display();  // display() is a public member of Derived class -- can be used directly inside 'int main()'

   return 0;
}
```