//
//  main.cpp
//  friend_class
//
//  Created by Neeraj Kumbhar on 11/24/15.
//  Copyright © 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;
class sample;

class test
{
    int i;
    
public:
        test()
    {
        i=9;
    }
    
    friend sample;
    
};

class sample
{
public:
        void fun1(test t1)
    {
        cout << t1.i << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    sample s;
    test t;
    s.fun1(t);
    
    return 0;
}


//#include<iostream>
//using namespace std;
//
//class Derived;
//
//class Base {
//private:
//    virtual void fun() { cout << "Base Fun"; }
//    friend int main();
//};
//
//class Derived: public Base {
//public:
//    void fun() { cout << "Derived Fun"; }
//};
//
//int main()
//{
//    Base *ptr = new Derived;
//    ptr->fun();
//    return 0;
//}