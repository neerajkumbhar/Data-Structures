//
//  main.cpp
//  pointersToOjects
//
//  Created by Neeraj Kumbhar on 24/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class item
{
    int code;
    int price;
public:
    item()
    {
        
    }
    void get(int a, int b)
    {
        code = a;
        price = b;
    }
    void display()
    {
        cout << "code" << code;
        cout << "price" << price;
        
    }
};


int main(int argc, const char * argv[]) {
    
    
  //  item x;
  //  item *ptr = &x;
    
      item *ptr = new item[10]; //array of 10 objects
  /*  item *ptr2 = new item;
    
    ptr2 -> get(5,6);
    ptr2 -> display(); */
    
    
    ptr -> get(3, 4);
    ptr -> display();
    
    
    return 0;
}
