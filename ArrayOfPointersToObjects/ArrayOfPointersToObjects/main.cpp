//
//  main.cpp
//  ArrayOfPointersToObjects
//
//  Created by Neeraj Kumbhar on 24/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>
#include <cstring>


class city
{
    char *name;
    int len;
public:
    city()
    {
        len = 0;
        name = new char[len + 1];
    }
    
    void getname()
    {
        char *s;
        s = new char[30];
        
        std::cout << "enter city" <<  std::endl;
        std::cin >> s;
        
        len = strlen(s);
        name = new char[len + 1];
        strcpy(name, s);
    }

    void putname()
    {
        std::cout << "Name = " << name << std::endl;
    }
};

int main(int argc, const char * argv[]) {
  
    
    city *ptr[10];  //array of 10 pointers
    
    ptr[1] = new city;
    ptr[1] -> getname();
    ptr[1] -> putname();
    
    city *ptr2 = new city[10]; //array of 10 objects
    ptr2 -> getname();
    ptr2 -> putname();
    
    city *ptr3 = ptr2;    //now just assign *ptr2 to a new pointer object
    ptr3 -> getname();
    ptr3 -> putname();
    
    
    
    return 0;
}
