//
//  main.cpp
//  perfect_square
//
//  Created by Neeraj Kumbhar on 3/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int root;
int number;


int main(int argc, const char * argv[]) {

    int sq1 = sqrt(1);
    int sq2 = sqrt(80);
    
//    cout << sq1 << endl;
//    cout << sq2 << endl;
    
    cout << "Number of square between: " << sq2 - sq1 + 1 << endl;

    
    return 0;
}
