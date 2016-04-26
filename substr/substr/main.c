//
//  main.c
//  substr
//
//  Created by Neeraj Kumbhar on 3/21/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//


#include <stdio.h> 

void mySubstr(char *dest, char *src, int position, int length);

int main()
{
    char subStr[100];
    char str[]="My Name Is Sweet";
    
    mySubstr(subStr, str, 1, 5);
    
    printf("\nstr = [%s]" "\nsubStr = [%s]\n\n", str, subStr);

//    getch();
    return(0);
}


void mySubstr(char *dest, char *src, int position, int length)
{
    while(length > 0)
        {
            *dest = *(src+position);
            dest++;
            src++;
            length--;
        }
}