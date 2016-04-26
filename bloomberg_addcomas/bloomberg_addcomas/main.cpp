//
//  main.cpp
//  bloomberg_addcomas
//
//  Created by Neeraj Kumbhar on 4/11/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//



#include  <iostream>
#include <cstring>
using namespace std;


int mystrlen(const char* a) {
    int count = 0;
    while ( a[count] != '\0' )
            count++;
    return count;
}

char* addComas(const char* a) {
    
    if (!a )
        return NULL;

    int n = mystrlen(a);
    
    if ( n == 0 )
        return "";
    
    
    int extraChars = n / 3;
    
    char* res = new char[n + extraChars];
    int j = n - 1;
    int k = n + extraChars - 1;
    int i = 1;
    while ( j >= 0 ) {
        
        if ( i % 4 == 0 ) {
            res[k] = ',';
            k--;
        }
        else {
            res[k] = a[j];
            k--;
            j--;
        }
        i++;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    
    const char* w = "10000";
    char* res = addComas(w);
    cout << res << endl;
    delete res;
    return 0;
}