//
//  main.c
//  fibonacci
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

int fib(int n)
{
    int f[n+1];
    f[1] = f[2] = 1;
    printf("\nF[1] = %d ",  f[1]);
    printf("\nF[2] = %d ",  f[2]);
    
    for(int i=3; i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
        printf("\nF[%d] = %d", i, f[i]);
    }
    
    printf("\n");
    return f[n];
    
    
}

int checkPerfectSquare(int n)
{
    for(int  i = 0; i< n/2; i++)
    {
        if( i * i == n)
            return 1;
    }
    return 0;
}


char *myfunc()
{
    char *temp = "neeraj";
    return temp;
}

int main(int argc, const char * argv[]) {
    
    int n = 10;
    int a = fib(10);
    
    int x = checkPerfectSquare(100);
    if(x == 1)
         printf("\nPrefect Square\n\n");
    else
        printf("\nNot a Prefect Square\n\n");
    
    
    printf("\nReturned string: %s\n", myfunc());
    
    return 0;
}
