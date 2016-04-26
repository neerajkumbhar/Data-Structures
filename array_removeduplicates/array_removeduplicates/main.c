//
//  main.c
//  array_removeduplicates
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>


void my_removeDuplicates(int arr[], int size)
{
    
    printf("\n Original array is:");
    for(int i=0; i< size; i++)
    {
        printf("\t%d", arr[i]);
        
    }
    
    printf("\n");
    
    int i,j;
    j = 0;
    
    for(int i = 1; i<size; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    
    
    int new_size = j + 1;
    printf("\n New array is:");
    for(int i=0; i<new_size; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    
    
}


int main(int argc, const char * argv[]) {

    int arr[] = {1,1,2,4,4,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    my_removeDuplicates(arr, size);
    
    return 0;
}
