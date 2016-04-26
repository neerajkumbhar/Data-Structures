//
//  main.c
//  permutation
//
//  Created by Neeraj Kumbhar on 06/03/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

static int cnt;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int i, int n)
{
    int j;
    if (i == n)
    {
        cnt++;
        printf("%s\n", a);
    }
    
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a+i), (a+j));
            permute(a, i+1, n);
            swap((a+i), (a+j)); //backtrack
        }
    }
}



int main(int argc, const char * argv[]) {
    cnt = 0;
    char a[] = "ABC";
    permute(a, 0, 2);
    printf("\nThere are %d permutations possible ", cnt);
   // getchar();
    return 0;
}




