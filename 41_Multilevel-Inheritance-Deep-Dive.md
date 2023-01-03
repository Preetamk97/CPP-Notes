```cpp
#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_no;

public:
    void setRollNo(int);
    void getRollNo(void);
};

void Student ::setRollNo(int r)
{
    roll_no = r;
}

void Student ::getRollNo(void)
{
    cout << "The roll number is " << roll_no << endl;
}
//********************************************************************************************
//********************************************************************************************
class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void setMarks(float, float);
    void getMarks(void);
};

void Exam ::setMarks(float m, float p)
{
    maths = m;
    physics = p;
}

void Exam ::getMarks(void)
{
    cout << "The marks obtained in maths are " << maths << endl;
    cout << "The marks obtained in physics are " << physics << endl;
}
//********************************************************************************************
//********************************************************************************************
class Result : public Exam
{
public:
    void display()
    {
        getRollNo();
        getMarks();
        cout << "The percentage obtained is " << (maths + physics) / 2 << endl; // {(maths+physics)/200}*100
    }
};
//********************************************************************************************

// Driver Code
int main()
{
    /*
    If we are inheriting B from A and C from B [A--->B--->C]:
        1.  A is the base class of B and B is the base class of C.
        2.  A--->B--->C is called Path of Inheritance.
    */
    Result harry;
    harry.setRollNo(36);
    harry.setMarks(71.0, 78.0);
    harry.display();
    return 0;
}
```