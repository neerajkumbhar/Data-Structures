//
//  main.cpp
//  strategy_pattern
//
//  Created by Neeraj Kumbhar on 3/7/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>


using namespace std;
class Number
{
public:
    virtual int increase(int)=0;
    virtual int decrease(int)=0;

};


class arithmatic: public Number
{
public:
    int increase(int x)
    {
        x = x + 1;
        return x;
    }
    
    int decrease(int y)
    {
        y = y - 1;
        return y;
    }
};


class my_operator: public Number
{
public:
    int increase(int x)
    {
        x++;
        return x;
    }
    
    int decrease(int y)
    {
        y--;
        return y;
    }
    
};




int main(int argc, const char * argv[]) {
    
    arithmatic a;
    cout << "arithmatic : " << a.increase(20) << endl;
    
    
    my_operator b;
    cout << "my_operator : " << b.increase(20) << endl;
    
    
    
    
    // example 1: sorting. use any sorting in the backend (apis) the user will just use the sort function 
    // example 2:
    /*
    File file = getFile();
    Cipher c = CipherFactory.getCipher( file.size() );
    c.performAction();
    
    
    
    // implementations:
    interface  Cipher  {
        public void performAction();
    }
    
    class InMemoryCipherStrategy implements Cipher {
        public void performAction() {
            // load in byte[] ....
        }
    }
    
    class SwaptToDiskCipher implements Cipher {
        public void performAction() {
            // swapt partial results to file.
        }
        
    }
    */

    
   
    return 0;
}
