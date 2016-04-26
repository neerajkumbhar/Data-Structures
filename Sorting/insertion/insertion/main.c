//
//  main.c
//  insertion
//
//  Created by Neeraj Kumbhar on 11/02/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//


#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            
            printf("\n ------\n");
            for (int m=0; m < n; m++)
                printf("%d ", arr[m]);
            printf("\n ------\n");
            
        }
        arr[j+1] = key;
        
        
        for (int m=0; m < n; m++)
            printf("%d ", arr[m]);
        printf("\n");
        
    }
}





/* Driver program to test insertion sort */
int main()
{
    int arr[] = {5,4,9,1,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
  //  printArray(arr, n);
    
    return 0;
}

