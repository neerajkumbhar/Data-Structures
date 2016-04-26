//
//  main.cpp
//  virtual_func_example
//
//  Created by Neeraj Kumbhar on 3/3/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//


#include<iostream>
using namespace std;

class Base
{
public:
    virtual void show() { cout<<" In Base \n"; }
};

class Derived: public Base
{
public:
    void show() { cout<<"In Derived \n"; }
};


class Derived2: public Base
{
public:
    void show() { cout<<"In Derived 222 \n"; }
};


class Derived3: public Base
{
private:
    int x = 10;
   void privateshow()
    {
        cout << x;
    }
public:
    void show()
    {
        x++;
        cout<<"In Derived 333 \n";
        cout << "New value of x: " << x << endl;
    }
};



int main(void)
{
    Base *bp = new Derived;
    bp->show();  // RUN-TIME POLYMORPHISM
    
    
    bp = new Derived2;
    bp->show();
    
    bp = new Derived3;
    bp->show();
    

    Derived3 d;
    d.show();

    
    
    
    
    return 0;
}


