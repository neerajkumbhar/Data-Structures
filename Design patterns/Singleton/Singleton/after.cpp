//
//  after.cpp
//  Singleton
//
//  Created by Neeraj Kumbhar on 3/7/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class SimpleMap
{
    int x;
    static SimpleMap *p;
    SimpleMap()
    {
        x = 0;
    }
    
    
    
public:
    
    static SimpleMap* getInstance()
    {
        if(!p)
        {
            p= new SimpleMap;
            cout << "inside if";
        }
        return p;
    }
    
    void SetMap(int a)
    {
        x = a;
    }
    
    int getMap()
    {
        return  x;
    }
};

SimpleMap *SimpleMap::p = 0;


int main(int argc, const char * argv[]) {
    

    
    SimpleMap *s = SimpleMap::getInstance();
    s->SetMap(0);
    cout << "Static mapGet: " << s->getMap() << endl;
    
    s->SetMap(40);
    cout << "Static mapGet: " << s->getMap() << endl;
    
    
    
    SimpleMap *s2 = SimpleMap::getInstance();
    s2->SetMap(30);
    cout << "Static mapGet 2: " << s2->getMap() << endl;

    
    
//    SimpleMap s1;
//    s1.SetMap(45);
//    cout << "s1 get : " << s1.getMap() << endl;
//    
//    SimpleMap s2;
//    s2.SetMap(28);
//    cout << "s2 get : " << s2.getMap() << endl;
    
    return 0;
}



