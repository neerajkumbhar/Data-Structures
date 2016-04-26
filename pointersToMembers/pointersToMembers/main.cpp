//
//  main.cpp
//  pointersToMembers
//
//  Created by Neeraj Kumbhar on 12/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class M
{
    int x;
    int y;
    
    public:
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    friend int sum(M);
};

int sum(M m)
{
    //px and py are pointers to x and y
    
    int M::*px = &M::x;
    int M::*py = &M::y;
    
    
    //pointer to object
    M *pm = &m;
    
  //  int s = m.*px + m.*py;
 //int s = m.*px + pm ->*py;
 int s = pm ->*px + pm ->*py;
    return s;
    
    
}

int main(int argc, const char * argv[]) {
    
    M n;
    
    //pointer to member function = pf
    void (M :: *pf)(int,int) = &M :: set;
    (n.*pf)(10,20);
    cout << "Sum:" << sum(n) << endl;
    
    
    M *op = &n;  //op is the pointer to object n
    (op->*pf)(20,30);
    cout << "Sum:" << sum(n) << endl;
    
    
    
    return 0;
}
