//
//  main.cpp
//  dynamicConstructors
//
//  Created by Neeraj Kumbhar on 14/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>
#include <string>


class String
{
    char *name;
    int length;
    
public:
    String()
    {
        length = 0;
        name = new char[length + 1];
        // std::cout<<"call came to me also";
    }
    
    String(String &s)
    {
        std::cout << "copy constructor is called";
    }
    
    String(char *s)
    {
        length = strlen(s);
        name = new char[length + 1];
        strcpy(name, s);
    }
    void display(void);
    void join(String &a, String &b);
    
};

void String::display()
{
    std::cout << "name: " << name << std::endl;
    
}

void String::join(String &a, String &b)
{
    length = a.length + b.length;
    delete name;
    name = new char[length + 1];
    
    strcpy(name, a.name);
    strcat(name, b.name);
    
}


int main(int argc, const char * argv[]) {
    
    char *first = "Neeraj";
    String name1(first);
    name1.display();
    
    String name2("Kumbhar");
    name2.display();
    
    String s1;
   s1.join(name1, name2);
    s1.display();
    
    String name3("Datt");
    String s2;
    s2.join(s1,name3);
    s2.display();
    
    
    

    return 0;
}
