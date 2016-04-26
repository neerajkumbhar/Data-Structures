//
//  main.cpp
//  static_constructor
//
//  Created by Neeraj Kumbhar on 3/15/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class A
{
public:
    static int a;
    A()
    {
        cout<< a++ << endl;
    }
};

int A::a = 1;

int main()
{

    A obj[100];
    

    return 0;

}


