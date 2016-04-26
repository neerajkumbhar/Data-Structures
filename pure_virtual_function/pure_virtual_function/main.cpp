#include<iostream>

using namespace std;

class Base
{
    int x;
public:
     void show()
    {
        cout << "\nejllo";
    };
     //void show2() = 0;
     //void show3() = 0;
    
};

/*class Derived : public Base
{
public:
     void show()
    {
        cout << "\nejllo";
    }
  */

/*
class Derived2 : public Base
{
public:
    void show()
    {
        cout << "hello";
    }
}; */


int main(void)
{
  //  Derived d;
   // d.show();
    
    Base b;
    
    Base *b2 = new Base();
    b2->show();
    b.show();
    
    Base b3 = b;
    
    
    
    
    int i = 10;
    int *ptr = &i;
   int **ptr1 = &ptr;
    
     cout << "\n ptr = " << ptr << endl;
       cout << "\n *ptr = " << *ptr << endl;
    
    
    
       cout << "\n ptr1 = " << ptr1 << endl;
       cout << "\n *ptr1 = " << *ptr1 << endl;
           cout << "\n **ptr1 = " << **ptr1 << endl;
    
       cout << "\n &ptr = " << &ptr << endl;
    
    

    return 0;
}

/*
 include<iostream>
 using namespace std;

 class Base
 {
    protected:
        int x;
    public:
        virtual void fun() = 0;
        Base(int i) 
        { 
            x = i;
        }
 };
 
 class Derived: public Base
    {
        int y;
        public:
        Derived(int i, int j):Base(i) 
        { 
            y = j; 
        }
        void fun() 
        { 
            cout << "x = " << x << ", y = " << y;
        }
    };
 
int main(void)
 {
    Derived d(4, 5);
    d.fun();
    return 0;
 }

*/