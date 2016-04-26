//
//  main.cpp
//  Virtual_Desctuctor
//
//  Created by Neeraj Kumbhar on 11/22/15.
//  Copyright © 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class base
{
public:
    
    base()
    {
        cout << "Base class constructor \n";
    }
    
    virtual ~base()
    {
        cout << "Base class destructor \n";
    }
    
};

class derived: public base
{
    
    int *p;
public:
    
    derived()
    {
        p = new int;
        cout << "Derived Class constructor\n";
    }
    
    ~derived()
    {
        delete p;
        cout << "Derived Class destructor\n";
    }
    
};

int main()
{
    base *b = new derived;
    delete b;
    return 0;
    
}

// when you DON'T declare the base class destructor as virtual :
//    and you delete the base class object
//        only the base class destructir will be called! derived class destructor will never be called!


//To let the derived class destructor be called before base class destructor
//    you have to define the base class destructor as virtual

