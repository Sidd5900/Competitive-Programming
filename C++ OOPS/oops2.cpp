#include <iostream>
#include <string>
#include <fstream>
#define WINDOWS 1
#define MAC 2
#define LINUX 3
#define OS LINUX

#include "PersonExt.h"
using namespace std;


// virtuql functions : child class overrides the method of parent class
class Person{
    public:
    virtual void introduce() {
        cout<<"hi from person"<<endl;
    }
};

class Student : public Person {
public:
    void introduce() {
        cout<<"hi from student"<<endl;
    }

};

class Person2 {
public:
    virtual void introduce() = 0;   // pure virtual function
};

void Person2 :: introduce() {
    cout<<"hello from person2"<<endl;
}

class Student2 : public Person2 {
public:
    void introduce(){
        cout<<"hi from student2"<<endl;
        Person2::introduce();
    }
};

void whoami(Person &p) {
    p.introduce();
}


// copy constructor : initialize object using another object
class Person3 {
public:
    string* name;
    int age;
    Person3(string iname, int iage) {
        name= new string(iname);
        age=iage;
    }
    Person3(const Person3 &p3) {
        name = new string(*p3.name);
        age = p3.age;
    }

};

//template class
template<class T,int siz>//can also have non template arguments and multiple arguments
class vect
{
  int idx=0;
  T arr[siz];
  public:
  void push(T x)
  {
    arr[idx]=x;
    idx++;
  }
  void display()
  {
      for(int i=0;i<idx;i++)
        cout<<arr[i]<<" ";
  }
};

//namespace

namespace {
    int x=50;
    void greet();
namespace one{
    void display(){
        cout<<x<<endl;
    }
namespace two{
    int y=20;
}
namespace three{
    int z=0;
}

inline namespace four{
    int f=-1;
}
}   // namespace one
}   // namespace

namespace{
    void greet(){
        cout<<"unnamed namespace within a file are linked but are independent across different files"<<endl;
    }
}

int main()
{
    /*
    Person p1;
    Student s1;
    whoami(p1); // hi from person
    whoami(s1); // hi from student
    // Person2 p2;  // gives error as Person2 is an abstract class (contains one or more pure virtual functions)
    Student2 s2;    // class derived from abstract class must override the pure virtual functions otherwise error
    s2.introduce();
    */

    /*
    Person3 p3("ram", 24);
    Person3 p3copy=p3;
    *p3.name="rohan";
    cout<<*p3copy.name<<" "<<p3copy.age<<endl;  // ram 24
    */

    /*
    Binary files reading and writing
    fstream file;
    file.open("sample.bin", ios::binary | ios::in | ios::out | ios::trunc);
    if(!file.is_open())
    {
        cout<<"error while opening the file"<<endl;
    }
    else
    {
        Person3 p3("anil", 24);
        file.write((char*) &p3, sizeof(Person3));
        file.seekg(0);
        Person3 p3read("noname", 0);
        file.read((char*) &p3read, sizeof(Person3));
        cout<<*p3read.name<<" "<<p3read.age<<endl;  // anil 24

    }
    */

    /*
    // Conditional compilation Macros
    #if OS == WINDOWS
    cout<<"windows user"<<endl;
    #elif OS == MAC
    cout<<"mac user"<<endl;
    #else
    cout<<"Linux user"<<endl;
    #endif // OS

    #ifdef WINDOWS
    cout<<"WINDOWS macro is defined"<<endl;
    #else
    cout<<"WINDOWS macro is not defined"<<endl;
    #endif // WINDOWS

    #undef WINDOWS
    #ifndef WINDOWS
    cout<<"WINDOWS macro is not defined"<<endl;
    #endif
    */

    /*
    vect<double, 2> v;
    v.push(2.5);
    v.push(1.98);
    v.display();
    */

    /*
    // namespaces
    cout<<x<<endl;  //50
    x=100;
    one::display(); //100
    cout<<one::two::y<<endl;    //20
    using namespace ::one::two;
    y=30;
    cout<<y<<endl;  //30
    greet();
    namespace onethree = one::three;    //namespace alias
    cout<< onethree::z<<endl;
    cout<<one::f<<endl; // inline namespace : outer namespace has access to inner members directly
    */

    PersonExt pext;
    pext.greet();




    return 0;
}
