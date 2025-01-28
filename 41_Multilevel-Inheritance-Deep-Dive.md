```cpp
#include <iostream>
using namespace std;

class Student
{
    protected: // Can be accessed by member functions of this class and Derived classes.
        int roll_no;  

    public: // Can be accessed by any function outside the class.
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

//****************************************//****************************************//

class Exam : public Student
{
    protected: // Can be accessed by member functions of this class and Derived classes.
        //  int roll_no;
        float maths;
        float physics;

    public: // Can be accessed by any function outside the class.
        //     void setRollNo(int);
        //     void getRollNo(void);
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

//****************************************//****************************************//

class Result : public Exam
{
    // protected: // Can be accessed by member functions of this class and Derived classes.
        // //  int roll_no;
        // float maths;
        // float physics;

    public: // Can be accessed by any function outside the class.
        //     //     void setRollNo(int);
        //     //     void getRollNo(void);
        //     void setMarks(float, float);
        //     void getMarks(void);
        void display()
        {
            getRollNo();
            getMarks();
            cout << "The percentage obtained is " << (maths + physics) / 2 << endl; // {(maths+physics)/200}*100
        }
};

//****************************************//****************************************//

// Driver Code
int main()
{
    Result harry;
    harry.setRollNo(36);
    harry.setMarks(71.0, 78.0);
    harry.display();
    return 0;
}
```