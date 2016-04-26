//
//  main.cpp
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
    
public:
    SimpleMap()
    {
        x = 0;
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



//int main(int argc, const char * argv[]) {
//    
//    SimpleMap s1;
//    s1.SetMap(45);
//    cout << "s1 get : " << s1.getMap() << endl;
//    
//    SimpleMap s2;
//    s2.SetMap(28);
//    cout << "s2 get : " << s2.getMap() << endl;
//    
//    return 0;
//}
