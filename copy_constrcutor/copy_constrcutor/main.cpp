//
//  main.cpp
//  copy_constrcutor
//
//  Created by Neeraj Kumbhar on 3/1/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class String
//{
//    char *s;
//    int size;
//    
//public:
//    String(const char *str = NULL);
//    
//    ~String()
//    {
//        cout <<"Destructor is called" << endl;
//        delete [] s;
//    }
//    
//    String(const String&);
//};
//
//String:: String(const char *str)
//{
//    size = strlen(str);
//    cout <<"Constructor is called" << endl;
//    cout<< "Size = " << size << endl;
//    s = new char[size];
//    strcpy(s, str);
//}
//
//
//String::String(const String& old_str)
//{
//    size = old_str.size;
//    s = new char[size+1];
//    strcpy(s, old_str.s);
//    
//    cout <<"Copy constructor is called" << endl;
//    cout << s << endl;
//}
//
//
//int main(int argc, const char * argv[]) {
//    
//    
//    String str1("neeraj");
//    
//    String str2 = str1;
//    return 0;
//}

#include<iostream>

using namespace std;

class Test
{
private:
    ~Test() {}
    friend void destruct(Test *);
    
};

void destruct(Test *ptr)
{
    cout << "Destructor function is called!";
    delete ptr;
}


int main()
{
    
    Test *t = new Test;
    destruct(t);
   
}