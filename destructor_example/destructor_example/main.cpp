//
//  main.cpp
//  destructor_example
//
//  Created by Neeraj Kumbhar on 3/2/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//


#include <iostream>
using namespace std;

int i;

class A
{
public:
    ~A()
    {
        std::cout << "destructor" << std::endl;
        i=10;
    }
};

int foo()
{
    i=3;
    A ob;
    return i;
}

int main()
{
    cout << "i = " << foo() << endl;
    return 0;
}

//value of i is copied to return value
//destructor is called
//before destructor could change the value of i to 10, the current value of i gets copied & hence the output is i = 3
// return by reference int& foor() {} will return 10
// return by value = 3