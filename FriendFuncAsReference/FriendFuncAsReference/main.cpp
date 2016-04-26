//
//  main.cpp
//  FriendFuncAsReference
//
//  Created by Neeraj Kumbhar on 12/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class class2;
class class1
{
    int value1;
    public:
    void getdata(int a)
                {
                    value1 = a;
                }
        void display()
                {
                    cout << "value1:" << value1 << endl;
                }
        friend void exchange(class1 &, class2 &);
    
};

class class2
{
    int value2;
public:
    void getdata(int a) { value2 = a;}
    void display()
        {
            cout << "value2: " << value2 << endl;
        }
        friend void exchange(class1 &, class2 &);
};


void exchange(class1 & x, class2 & y)
{
    int temp = x.value1;
    x.value1 = y.value2;
    y.value2 = temp;
}


int main(int argc, const char * argv[])
{
    class1 c1;
    class2 c2;
    
    c1.getdata(100);
    c2.getdata(200);

    c1.display();
    c2.display();
    
    exchange(c1, c2);
    
    c1.display();
    c2.display();
    
    
    
    
    
    
    return 0;
}
