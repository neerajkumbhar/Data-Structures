//
//  main.cpp
//  staticVariablesandFunctions
//
//  Created by Neeraj Kumbhar on 12/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class test
{
    int age;
    char name[30];
    static int count;
    
public:
    static void showcount();
    void set();
    
};

class test2
{
    char* str;
    
    public:
        test2(char * s)
                {
                        str = s;
                    cout << "this is paramaterised constructor:" << endl;
                        cout << "String is : " << str << endl;
                }
        test2()
                {
                        str = "basic";
                    cout << "this is a basic constructor:" << str << endl;
                }
        ~test2()
                {
                        cout << "Destructor is called by default\n" ;
                        delete str;
                }
    
    
    
    
};

int test::count =100;

void test::showcount()
{
    
    cout << "Count is:" << count << endl;
}

void test::set()
{
    age = ++count;
}

int main(int argc, const char * argv[]) {
    
    test o1, o2;
    
    o1.set();
    o1.showcount();
    
    //test::showcount();
    
    o2.set();
    test::showcount();
    
    test o4 = *new test();
    o4.set();
    test::showcount();
    
    
    test o3[4]; //array of objects
   // o3[1].set();
   // o3[1].showcount();
    
    for (int i =0;i < 5; i++)
    {
        o3[i].set();
        o3[i].showcount();
    }
    
    
   
   //test2 t1;
//test2 t2("neeraj");
  // test2 t3 = *new test2("saiesh"); //calls destructor
   test2* t4= new test2("pranav"); //doesnt not call the destructor. you have to explicitely use delete
                                    //you can only delete it when you new it
                                    //Usually an object should not have the responsibility of deleteing anything that it didn't itself new
    
    
    
    
    
    
    

    
    
    
    return 0;
}
