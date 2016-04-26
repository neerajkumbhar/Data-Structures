//
//  main.c
//  numbers_gap
//
//  Created by Neeraj Kumbhar on 4/19/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.


#include <stdio.h>

void FindGaps(int arr[], int size) {
    
   
    if(size == 0)
        printf("\n0-99");

    if(arr[0]!=0)
        printf("0 - %d , ", arr[0]-1);

    
    for(int i = 0; i<size-1; i++)
    {
        if(arr[i]+1 == arr[i+1]-1)
            printf("%d ,", arr[i] + 1);
        
        else if (arr[i] < arr[i+1])
            printf("%d - %d ,", arr[i]+1, arr[i+1] -1);
    }
    
    if(arr[size-1]!=99)
        printf("%d - 99", arr[size-1]);
    
   
    
    

    
           
}
           
int main(int argc, const char * argv[]) {
    
    
    int arr[4] = {8, 50, 52, 75};
    int size = sizeof(arr)/sizeof(arr[0]);
    FindGaps(arr, size);
    
    
    
    return 0;
}
