//
//  main.c
//  Arrays_sumof2
//
//  Created by Neeraj Kumbhar on 3/9/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define MAX 100000

void printPairs(int arr[], int arr_size, int sum)
{
    int i, temp;
    bool binMap[100000] = {0}; /*initialize hash map as 0*/
    
    for (i = 0; i < arr_size; i++)
    {
        temp = sum - arr[i];
        if (temp >= 0 && binMap[temp] == 1)
            printf("Pair with given sum %d is (%d, %d) \n",
                   sum, arr[i], temp);
        binMap[arr[i]] = 1;
    }
}

/* Driver program to test above function */
int main()
{
    int A[] = {2,5,9,6,4,10};
    int n = 10;
    int arr_size = sizeof(A)/sizeof(A[0]);
    
    printPairs(A, arr_size, n);
    
    getchar();
    return 0;
}