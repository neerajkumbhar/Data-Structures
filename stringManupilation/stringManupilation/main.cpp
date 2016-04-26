//
//  main.cpp
//  stringManupilation
//
//  Created by Neeraj Kumbhar on 16/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

class String
{
    char *p;
    int len;
public:
    String()
    {
        len = 0;
        p = 0;
    }
   
    String(char *s)
    {
        len= strlen(s);
        p = new char[len + 1];
        strcpy(p, s);
        std::cout << " String(char *s) Constructor called" << std::endl;
    }
    
    String(String &s)
    {
        len = s.len;
        p = new char[len + 1];
        strcpy(p, s.p);
        std::cout << " copy Constructor called" << std::endl;
    }
  
   
    friend String operator+(String &s, String &t);
    friend void show(String s);
};

String operator+(String &s, String &t)
{
    String temp;
    temp.len = s.len + t.len;
    temp.p = new char[temp.len + 1];
    strcpy(temp.p, s.p);
    strcat(temp.p, t.p);
    return (temp);
}

void show(String s)
{
    std::cout << s.p;
}


int main(int argc, const char * argv[]) {
    
    char *first = "New";
    String s1(first);

    String s2("York");

  //  String s3 = s1;  //this is where copy constructor is called
    
   // String t1, t2, t3;
      String t1 = s1;   //copy constrctor is called: when we accept a reference to its own class: a copy constructor is called
     // t1.show(t1);       // copy constrctor is called
    
    String t2 = s2;
    
    String t3;
    t3 = t1 + t2;
    show(t3);
    
    
    
    
    
    return 0;
    
    
    
}
