//
//  main.cpp
//  virtualFunctions
//
//  Created by Neeraj Kumbhar on 24/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class base
{
public:
    virtual void show()
    {
        cout << "Show Base" << endl;
    } 
    
};

class derived : public base
{
public:
    void show()
    {
        cout << "Show Derived" << endl;
    }
    
};





int main(int argc, const char * argv[]) {
    
    base B;
    base *bptr;
    bptr = &B;
    
    bptr -> show() ;
    
    cout << endl;
    
   derived D;
    bptr = &D;
    
   
    bptr -> show();
    
    
 
 /*   derived D;
    derived *dptr;
    dptr = &D;

  
    dptr -> show(); */
    
    
    
    
    
    return 0;
}
