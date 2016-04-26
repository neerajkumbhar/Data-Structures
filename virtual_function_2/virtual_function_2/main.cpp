#include<iostream>

using namespace std;

/*
class A {
public:
    virtual void fun()
    { cout<<"\n A::fun() called ";}
};

class B: public A {
public:
    void fun()
    { cout<<"\n B::fun() called "; }
};

class C: public B {
public:
    void fun()
    { cout<<"\n C::fun() called "; }
};

int main()
{
    C c; // An object of class C
    A *a = &c;
    a -> fun();
    
   // does not depened on type of pointer ( base/derived)
   // rather depends on type of object it is pointed to
   //  in this case it is pointed to c: so it will call c -> fun()
    
    
     B *b = &c; // A pointer of type B* pointing to c
     b->fun();  // this line prints "C::fun() called"
    getchar();
    return 0;
} */

class Base
{
public:
     virtual void print()
    {
        cout << "Base class print function \n";
    }
    void invoke()
    {
        cout << "Base class invoke function \n";
        this -> print();
    }
};

class Derived: public Base
{
public:
    void print()
    {
        cout << "Derived class print function \n" ;
    }
    void invoke()
    {
        cout << "Derived class invoke function \n";
        this -> print();
    }
};

int main()
{
    Base *b = new Derived;
    b -> invoke();   // here only the print funtion is made  virtual: so when you call invoke, it normal call and
                    // base funtion will be called. But then it called print() which is made virtual in the base class.
                    // do run-time poly morph is achived here and derived class funtion is called.
    return 0;
}