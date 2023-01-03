```cpp
#include <iostream>
using namespace std;

class CWH {
    protected:
        string title;  
        float rating;
    public:
        CWH(string title, float rating){
            this->title = title;
            this->rating = rating;
        }
        virtual void display(void)=0; //Do-Nothing Function OR Pure Virtual Function.

        /*
        Pure Virtual Function:
        *********************
        A Pure Virtual Function is a special type of virtual function that imposes a strict rule - that every Derived class must have its own definition of this function - not abiding by which will throw an error.

        virtual void display(void){}  //Code of previous lesson program

        virtual void display(void)=0; //Current code

        In the previous lesson program, even if we do not provide any new/overriden definition of 'display()' method inside derived classes CWHVideos and CWHArticles --  it will compile perfectly without any errors and 'tuts[0]->display()' & 'tuts[1]->display()' will invoke the 'display(){}' method of the base CWH class on both the objects -- inspite of using 'vitual' keyword for 'display()' method of base CWH class.

        But in the current program, since we have made 'display()' function of base class CWH - A Pure Virtual Function - therefore, we must provide its definition in both the derived classes i.e in CWHVideos & CWHArticles -- otherwise compiler will throw an error.

        Abstract Base Class:
        *******************
        - A base class which contains atleast one Pure Virtual Function is called an Abstract Base Class.
        - An Abstract Base Class is created with the sole purpose of creating more Derived classes from it. And, if and when we create a Derived class from the Abstract Base Class, we must always provide the definitions for all the Pure Virtual Functions mentioned within the Abstract Base class.
        - We cannot create objects from an Abstract Base Class.
        - Here, class CWH is an example of an Abstract Base Class.
        */
        
};

class CWHVideos : public CWH {
    float videoLength; 
    public:
        CWHVideos(string title, float rating, float videoLength) : CWH(title, rating) {
            this->videoLength = videoLength;
        }
        void display(void){  // If we comment out this function definition, compiler will give error
            cout<<"Title of this video is "<<title<<endl;
            cout<<"Rating of this video is "<<rating<<endl;
            cout<<"Length of this video is "<<videoLength<<endl;
        }
};

class CWHArticles : public CWH {
    int wordCount;
    public:
        CWHArticles(string title, float rating, int wordCount) : CWH(title, rating) {
            this->wordCount = wordCount;
        }
        void display(void){  // If we comment out this function definition, compiler will give error
            cout<<"Title of this article is "<<title<<endl;
            cout<<"Rating of this article is "<<rating<<endl;
            cout<<"WordCount of this article is "<<wordCount<<endl;
        }
};

// Driver Code
int main()
{
    CWHVideos cpptut1video("C++ Tutorial 1 Video", 4.8f, 13.56);
    cpptut1video.display();

    CWHArticles cpptut1article("C++ Tutorial 1 Article", 4.64f, 200);
    cpptut1article.display();

    CWH *tuts[2];
    tuts[0]= &cpptut1video;
    tuts[1]= &cpptut1article;

    tuts[0]->display();  
    tuts[1]->display();  

    return 0;
}
```