//
//  main.cpp
//  static_funtions_examples
//
//  Created by Neeraj Kumbhar on 2/29/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//    
//    int x;
//    
//public:
//    A()
//    {
//        cout<<"\nA's constructor" << endl;
//    }
//};
//
//
//class B
//{
//    static A a;
//    
//public:
//    B()
//    {
//        cout<<"\nB's constructor" << endl;
//    }
//    
//     static A getA()
//     {
//         return a;
//     }
//    
//};
//
//A B::a;
//
//int main(int argc, const char * argv[]) {
//
//    B b1;
//    
//    b1.getA();
//    
//    //B *b = new B;
//
//    
//
//}

//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//    int x;
//    int y;
//public:
//    Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//    static void fun1()
//    {
//        cout << "\nInside fun1()";
//    }
//    
//    static void fun2()
//    {
//        cout << "\nInside fun2()";
//        fun1();
//    }
//};
//
//int main()
//{
//    Test obj;
//    obj.fun2();
//    return 0;
//}




#include<iostream>
using namespace std;

class Test
{
    
private:
    int x;
    int y;
    
public:
    Test(int x = 0, int y = 0)
        {   this->x = x;
            this->y = y;
        }

    void setX(int a)
        {
            x = a;
        }
    
    void setY(int b)
        {
            y = b;
        }

    void destroy()
        {
            delete this; // you have to use new for this. 
        }
    
    void print()
        {
            cout << "x = " << x << " y = " << y << endl;
        }
};

int main()
{
    Test *obj = new Test;
    obj->destroy();
    obj->print();
    return 0;
}
