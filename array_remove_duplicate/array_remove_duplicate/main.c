//
//  main.c
//  array_remove_duplicate
//
//  Created by Neeraj Kumbhar on 4/4/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

void printRepeating(int arr[], int size)
{
    int *count = (int *)calloc(sizeof(int), (size - 2));
    int i;
    int new_array[size];
    int j = 0;
    printf("Repeating elements are ");
    for(i = 0; i < size; i++)
    {
        if(count[arr[i]] == 1)
            printf(" %d ", arr[i]); // prints repeating elements
        else
        {
            new_array[j] = arr[i];
            count[arr[i]]++;
            j++;
        }
    }
    
    printf("\nNew array");
    for(int i=0; i<j; i++)
    {
        printf(" %d ", new_array[i]);
    }
}

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1, 4, 2};
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    printRepeating(arr, arr_size);
    getchar();
    return 0;
}
