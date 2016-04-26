//
//  main.c
//  power_of_2
//
//  Created by Neeraj Kumbhar on 4/13/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int num = 10;
    
    if(!(num & (num - 1)) && num)
        {
            printf("Power of 2\n");
        }
    else
    {
            printf("Not a Power of 2\n");
    }
    return 0;
}
