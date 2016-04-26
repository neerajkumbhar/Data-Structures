//
//  main.c
//  string_trim_whitespaces
//
//  Created by Neeraj Kumbhar on 3/21/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h> 

char *trim(char *s);

void myprint(int n);

void stack(int *local1);

int main(int argc, char *argv[])
{
    char str1[]=" Hello       am Good ";
    printf("\n\nBefore trimming : [%s]", str1);
    printf("\n\nAfter trimming : [%s]", trim(str1));
    myprint(100);
    
    int local1;
    stack(&local1);
}

void stack(int *local1)
{
    int local2;
    printf("\nadd of first local:: %u", local1);
    printf("\nadd of second local:: %u", &local2);
    
    if(local1 < &local2)
    {
        printf("\ngrowing doenwards");
    }
    else
    {
        printf("\ngrowing upwards");
    }
}

void myprint(int n)
{
    if(n>0)
    {
        myprint(n-1);
        printf("%d\n", n);
    }
    return;
}

// The trim() function...

char *trim(char *s)
{
    char *p, *ps;
    
    for (ps = p = s; *s != '\0'; s++)
    {
        if (!isspace(*s))
        {
            *p++ = *s;
        }
    }
    
    *p = '\0';
    return(ps);
}
