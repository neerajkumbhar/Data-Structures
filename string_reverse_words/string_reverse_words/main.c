//
//  main.c
//  string_reverse_words
//
//  Created by Neeraj Kumbhar on 4/3/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h> 

void rev(char *l,char *r)
{
    char t;
    while(l<r)
    {
        t = *l;
        *l++ = *r;
        *r-- = t;
    }
}

int main(int argc, char *argv[])
{
    char buf[] = "Always try hard in life";
    
    char *end, *x, *y;
    
    for(end=buf; *end; end++);
    rev(buf,end-1);
    
//    printf("\nReversed buffer is:%s", buf);
//    printf("\n\n");
    
    x = buf -1;
    y = buf;
    
    while(x++ < end)
    {
        if(*x == '\0' || *x == ' ')
        {
            rev(y, x-1);
            y = x+1;
        }
    }
    
    
    
    printf("\nReversed buffer is:%s", buf);
    printf("\n\n");
}
