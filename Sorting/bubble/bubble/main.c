//
//  main.c
//  bubble
//
//  Created by Neeraj Kumbhar on 08/04/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void swap(int *x, int  *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    
    
}
void bubble(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) //Last i elements are already in place
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    
    
  /*   for (i = 1; i < n; i++)
        for (j = 1; j < n-i; j++) //Last i elements are already in place
            if (arr[j] > arr[j-1])
                swap(&arr[j], &arr[j-1]); */

}

int main(int argc, const char * argv[]) {

    int arr[] = {3,90,5,24,-2};
    bubble(arr,5);
    for(int i = 0;i<5; i++)
    {
        printf("\t %d" , arr[i]);
    }
    return 0;
}
