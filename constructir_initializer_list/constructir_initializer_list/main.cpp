//
//  main.cpp
//  constructir_initializer_list
//
//  Created by Neeraj Kumbhar on 3/15/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class Fred
{
    const int size;
    static int a;
    static int b;

public:
    Fred(int sz): size(sz)
    {
        
    }
    
    void print()
    {
        cout << size << endl;
    }
    
};


int main()
{
 
    Fred a(1), b(2), c(3);
    a.print();
    b.print();
    c.print();
    
    return 0;
}
