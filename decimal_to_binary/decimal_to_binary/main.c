//
//  main.c
//  decimal_to_binary
//
//  Created by Neeraj Kumbhar on 3/23/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void generateBits(int num)
{
    
    int temp;
    if(num)
    {
        temp = num % 2;
        generateBits(num = num >> 1);
        printf("\nnum = %d  ", num);
        printf("temp = %d ", temp);
    }

}

int main(int argc, const char * argv[]) {
    
    int num = 8;
    generateBits(num);
    
    return 0;
}
