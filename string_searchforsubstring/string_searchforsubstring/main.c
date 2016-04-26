//
//  main.c
//  string_searchforsubstring
//
//  Created by Neeraj Kumbhar on 4/16/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>


int mystrstr(const char *str, const char *target)
{
    char *p1 = str;
    while(*p1)
    {
        char *p1beign = p1;
        char *p2 = (char *)target;
        
        while (*p1 && *p2 && *p1 == *p2) {
            printf("%c", *p1);
            p1++;
            p2++;
            
        }
        
        if(!*p2)
            return 1;
        
        printf("\n.");
        p1 = p1beign + 1;
       
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    
    char *mystring = "neeraj";
    char *findme= "raj";
    
    int a = mystrstr(mystring, findme);
    if(a == 1)
        printf("\nPresent\n");
    else
        printf("\nNot present\n");
    return 0;
}
