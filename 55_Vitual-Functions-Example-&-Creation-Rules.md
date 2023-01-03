```cpp
//Below program is an use case example of Virtual Functions.

#include <iostream>
using namespace std;

class CWH {  //CodeWithHarry makes both videos and articles. This class is the parent class for both CWH Videos and Articles.
    protected:
        string title;  //common characteristic
        float rating;  //common characteristic
    public:
        CWH(string title, float rating){
            this->title = title;
            this->rating = rating;
        }
        virtual void display(void){}  //Will be defined in derived classes.
};

class CWHVideos : public CWH {
    //string title (protected) -- inherited
    //float rating (protected) -- inherited
    //virtual void display(void){} -- inherited
    float videoLength;    //unique characteristic of a video
    public:
        CWHVideos(string title, float rating, float videoLength) : CWH(title, rating) {
            this->videoLength = videoLength;
        }
        void display(void){  //If we do not provide this function definition, compiler will execute the display() function of CWH class -- in lines 70 & 75 below.
            cout<<"Title of this video is "<<title<<endl;
            cout<<"Rating of this video is "<<rating<<endl;
            cout<<"Length of this video is "<<videoLength<<endl;
        }
};

class CWHArticles : public CWH {
    //string title (protected) -- inherited
    //float rating (protected) -- inherited
    //virtual void display(void){} -- inherited
    int wordCount;  //unique characteristic of an article
    public:
        CWHArticles(string title, float rating, int wordCount) : CWH(title, rating) {
            this->wordCount = wordCount;
        }
        void display(void){  //If we do not provide this function definition, compiler will execute the display() functiun of CWH class -- in lines 70 & 75 below.
            cout<<"Title of this article is "<<title<<endl;
            cout<<"Rating of this article is "<<rating<<endl;
            cout<<"WordCount of this article is "<<wordCount<<endl;
        }
};

// Driver Code
int main()
{
    CWHVideos cpptut1video("C++ Tutorial 1 Video", 4.8f, 13.56);  //Creating CWHVideos object.
    cpptut1video.display();
    // Title of this video is C++ Tutorial 1 Video
    // Rating of this video is 4.8
    // Length of this video is 13.56

    CWHArticles cpptut1article("C++ Tutorial 1 Article", 4.64f, 200);
    cpptut1article.display();
    // Title of this article is C++ Tutorial 1 Article
    // Rating of this article is 4.64
    // WordCount of this article is 200

    CWH *tuts[2];  //Creating a CWH class array 'tuts' for holding 2 pointers.
    tuts[0]= &cpptut1video;
    tuts[1]= &cpptut1article;

    tuts[0]->display();  
    //This will execute the display() of CWHVideos class
    // Title of this video is C++ Tutorial 1 Video
    // Rating of this video is 4.8
    // Length of this video is 13.56
    tuts[1]->display();  
    //This will execute the display() of CWHArticles class.
    // Title of this article is C++ Tutorial 1 Article
    // Rating of this article is 4.64
    // WordCount of this article is 200

    return 0;
}

//Rules for using Virtual Functions:
//***********************************
//1. They cannot be static.
//2. They are only accessed by object pointers.
//3. Virtual functions can be a friend of another class.
//4. A virtual function in a base class might never be used.
//5. If a virtual function (of Base class) is not defined/overrriden in the derived class, then on calling the function from a 'Base class object pointer' --> it will simply run the original virtual function (of the Base class).
```