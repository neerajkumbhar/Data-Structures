//
//  main.c
//  Array_oddOccurance
//
//  Created by Neeraj Kumbhar on 3/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

int getOddOccurrence(int ar[], int ar_size)
{
    int i;
    int res = 0;
    for (i=0; i < ar_size; i++)
    {
        res = res ^ ar[i];
    }
    return res;
}

/* Diver function to test above function */
int main()
{
//    int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int ar[] = {1,1,2,2,2,3,3,4,4,5,5};
    int n = sizeof(ar)/sizeof(ar[0]);
    printf("%d\n", getOddOccurrence(ar, n));
    return 0;
}