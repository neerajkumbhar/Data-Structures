//
//  main.cpp
//  test6
//
//  Created by Neeraj Kumbhar on 12/01/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>

using namespace std;

class length
{
    int feet;
    float inches;
public:
    length()
    {
        feet = 5;
        inches = 6.0;
     //   cout << feet << endl;
      //  cout << inches << endl;
        
    }
    
    length(int f, float i)
    {
        feet = f;
        inches = i;
       // cout << feet << endl;
        //cout << inches << endl;
    }
    
    // 1 feet = 12 inches
    length add(length l)
    {
        l.feet = l.feet + this->feet;
        l.inches = l.inches + this->inches;
        if(l.inches > 12)
        {
            l.inches = l.inches - 12;
            l.feet++;
        }
        return l;
    }
    
    int getFeet()
    {
        return feet;
    }
    
    float getInches()
    {
        return inches;
    }
    
    
};



int main(int argc, const char * argv[]) {
   
    length l1;
    length l2(2, 3.2);
    
    l1 = l1.add(l2);
    
    cout << "Feet: " << l1.getFeet() << endl;
    cout << "Inches: " << l1.getInches() << endl;
    
    

    return 0;
}
