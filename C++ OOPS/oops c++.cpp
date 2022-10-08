#include <bits/stdc++.h>
using namespace std;
//include external file
#include "headerfile.cpp"

//Namespaces in C++ are used to organize too many classes so that it can be easy to handle the application
//the functions may have same name in different namespaces
//Namespaces help us to avoid conflict/collision between variable/function names

namespace First {
    double pi=3.14;
    void sayHello() {
        cout<<"Hello First Namespace"<<endl;
    }
}
namespace Second  {
       void sayHello() {
           cout<<"Hello Second Namespace"<<endl;
       }
}

//structure------------------------------------------------------
 struct Rectangle    {
     //struct is by default public
     private:
   int width, height;
   public:
  Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
  void areaOfRectangle() {
    cout<<"Area of Rectangle is: "<<(width*height); }
 };
 //classes and objects-----------------------------------------------
 //inheritance,polymorphism,abstraction,encapsulation
 //abstraction through private and public members, header files

 class stud
    {
        //public data members
        public:
        int age;
        string name;
        //static member, belongs to the type not instance,only one copy all objects share
        static string college;
        //constructor must be public
        //default constructor- no arguments
        stud()
        {
            cout<<"constructor called"<<endl;
        }
        //parameterized constructor
        stud(int age,string name)
        {
            this->age=age;
            this->name=name;
        }
        //copy constructor
        stud(stud &s1)
        {
            age=s1.age;
            name=s1.name;
        }
        //member functions
        void setdata(int a,string s)
        {
            age=a;
            name=s;
        }
        void getdata()
        {
            cout<<age<<" "<<name<<" "<<college<<endl;
        }
        void inside()
        {
            cout<<"inside stud"<<endl;
        }
        ~stud()//no parameters and public
        {
            cout<<"destructor called"<<endl;
        }
        //operator overloading
        bool operator == (stud &s1)
        {
            if(name==s1.name && age==s1.age)
                return true;
            return false;
        }

        //friend function
        // The function definition does not use either the keyword friend or scope resolution operator.
        //It cannot be called using the object as it is not in the scope of that class.
        //It can be invoked like a normal function without using the object
        //can be friendly to two different classes and hence can access their private members
        //A friend class can access both private and protected members of the class in which it has been declared as friend
        //friend class B;
        friend void updateage(stud &s1);

    };
    //friend function definition(no scope resolution operator)
    void updateage(stud &s1)
    {
        s1.age+=10;
    }
    //inheritance types-single ,multiple,multilevel,hierarchical,hybrid
    class btech: public stud//for multiple inheritance write class A: public B,public C
    {
          public:
        int year;

        btech(int age,string name,int year)
        {
            this->age=age;
            this->name=name;
            this->year=year;
        }
         void getdata()
        {
            cout<<age<<" "<<name<<" "<<year<<endl;
        }
         void inside()
        {
            cout<<"inside btech"<<endl;
        }

    };

 string stud:: college="iitp";



 //C++ Enums can be thought of as classes that have fixed set of constants.
 enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
 //***************************************************************************************************

 //Polymorphism -compile time, run time
//compile time- function overloading,operator overloading(called early binding or static linkage )
//function overload may be ambiguous due to type casting,pass by reference or by using default arguments
//run time- virtual functions(this polymorph. is also called late binding or dynamic linkage)
//If derived class defines same function as defined in its base class, it is known as function overriding in C++.
//It is used to achieve runtime polymorphism.
//

 class comp
 {
    double x,y;
    int cnt=0;
    public:
    comp()
    {
        x=0;
        y=0;
    }
    comp(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    comp operator +(comp &);//prototypes for operator overload
    void operator ++();

    void getdata()
    {
        cout<<x<<" "<<y<<" "<<cnt<<endl;
    }
    //abstract class-> have at least one virtual function
    virtual void display()//if-> virtual void display()=0; then called pure virtual function->object cannot be created
    {
        cout<<"Inside comp"<<endl;
    }

 };
 //operator overloading
 comp comp::operator +(comp &c )//return type,class name :: operator op(arguments->no. of operands-1)
 {
     comp res;
     res.x=x+c.x;
     res.y=y+c.y;
     return res;
 }
//unary operator overloading example
 void comp:: operator ++()
 {
     cnt++;
 }

 class D:public comp
 {
   public:
   void display()
   {
       cout<<"Inside D"<<endl;
   }

 };
 //------------------------------------------------------------------
//exception handling
 void except()
 {
     while(1)
     {
     int x,y;
     cin>>x>>y;
     try
     {
         if(y==0)
            throw "division by zero error";
        int z=x/y;
        cout<<z<<endl;
        break;
     }
     catch(const char* e)//control goes to catch from throw as e
     {
         cout<<"exception occured "<<e<<endl;
         cout<<"re enter the nos"<<endl;
     }
     }
 }
 //------------------------------------------------------------------------------------------------------------
 // Template->generic programming, code re-usability
 //A template allows us to create a family of classes or family of functions to handle different data types.
 //Template function
 //We can overload the generic function means that the overloaded template functions can differ in the parameter list.
 template<class T> T add(T &a,T &b)//multiple parameters->template<class X,class Y> void func(X &a,Y &b)
{
    T result = a+b;
    return result;
}

//Class template
template<class T,int siz>//can also have non template arguments and multiple arguments
class vect
{
  int idx=0;
  int arr[siz];
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
//file handling---------------------------------------------------------------------------------
void readfile()
{
 //fstream file("sample.txt");
 fstream file;
 file.open("sample.txt",ios::in| ios::app);
 //char word[20];
 string word;
 if(!file.is_open())
 {
     cout<<"error"<<endl;
     return;
 }
 int cnt=0;
 //file<<"leave me alone";
 while(!file.eof())
 {
    file>>word;//for word by word(space separated )
    //getline(file,word);//by default newline is delimiter so line by line read
    cnt++;
    cout<<word<<" ";
 }
 cout<<endl<<cnt<<endl;

 file.seekg(4,ios::beg);//move the get pointer to the 4th pos from beginning
 char ch;
 int cntchar=0;
 while(file.get(ch))
 {
     cntchar++;
     cout<<ch;
 }
 // cout<<file.tellg()<<endl;///tellg returns the current pos of get pointer(while reading)
 cout<<endl<<cntchar<<endl;
 file.close();
}
//Stringstream class-----------------------------------------------------------------------------

void sstream()
{
    stringstream sso;
    int x=34;
    sso<<x;
    string xs;
    sso>>xs;
    cout<<xs+xs<<endl;
    stringstream sso2;
    string xs2="12.34";
    sso2<<xs2;
    double x2;
    sso2>>x2;
    cout<<x2<<endl;

}
//---------------------------------------------------------------------------------------------



int main()
{
  cout<<sum(1,2);
   // A a1(2,3);
   // a1.display();

    //sstream();

    //readfile();

  //string s1;
 // getline(cin,s1,'.');//
  //char s2[10];
  //cin.getline(s2,10);

  //  vect<int,5>v;
    //v.push(5);
   // v.push(4);
   // v.push(3);
  //  v.display();

   //double a=10.5,b=0.9;
 // cout<<add(a,b);

  // except();

   // using namespace First;
   // First::sayHello();
   // Second::sayHello();
   // sayHello();
   //cout<<pi<<endl;

   // comp *ptr;
   // D d1;
  //  ptr=&d1;
    //base class(containing virtual function) pointer pointing to derived class
   // ptr->display();//inside D (if virtual not used them output->inside comp)

 //  comp c1(2,3);
   //comp c2(4,-1);
  // comp res=c1+c2;
  // res.getdata();//6 2 0
  // ++res;
  // res.getdata();// 6 2 1

  //  btech b1(10,"binod",2);
   // b1.getdata();//derived class function overrides base class
  //  b1.stud::getdata();//use class resolution to access bases class function
   // first.showinside();

    /*stud s1;
    int age;
    string name;
    cout<<"enter age and name"<<endl;
    cin>>age>>name;
    s1.setdata(age,name);
  //  s1.getdata();
    stud s2=s1;
    s2.name="harry";
 //   cout<<s1.name<<endl;
    s2.getdata();
    s1.getdata();

    if(s2==s1)
        cout<<"same"<<endl;
    else
        cout<<"different"<<endl;*/

   // stud s1(20,"Ram");
  //  btech s2(19,"binod",2);
  //  s2.getdata();
 // struct Rectangle r1(10,20);
 // r1.areaOfRectangle();

   // week day;
  //  day = Friday;
  //  cout << "Day: " << day<<endl;

  //stud s1(10,"tom");
  //s1.getdata();
 // updateage(s1);
  //s1.getdata();

    return 0;
}
