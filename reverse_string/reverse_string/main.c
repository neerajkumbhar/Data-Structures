//
//  main.c
//  reverse_string
//
//  Created by Neeraj Kumbhar on 4/21/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void reverse(char *str, int n)
{
    for(int i=0, j=n-1; i<=j; i++, j--)
    {
        str[i] ^= str[j];
        str[i] ^= (str[j] ^= str[i]);
        

    }
    
    for(int i=0; i<n; i++)
            printf("%c", str[i]);
}

int main(int argc, const char * argv[]) {
   
    char str[5] = "cat";
    reverse(str, 5);
    return 0;
}
