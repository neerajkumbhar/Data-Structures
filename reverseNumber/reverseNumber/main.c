//
//  main.c
//  reverseNumber
//
//  Created by Neeraj Kumbhar on 3/30/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void reverse(int num){
    
    if(num == 0)
        return;
    
    int x = num % 10;
    printf("%d", x);
    num = num / 10;
    reverse(num);
    
}

void printArray(int arr[], int size)
{
    printf("\nReversed Array is:");
    for(int i=0; i<size; i++)
        printf(" %d", arr[i]);
    
    printf("\n");
}

void reverseArray(int arr[], int size)
{
    int temp;
    for(int i=0; i<size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}


int main(int argc, const char * argv[]) {
    int a = 1234567;
    printf("\nReversed Number is:");
    reverse(a);
    printf("\n");
    
    int arr[7]={1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    reverseArray(arr, size);
    printArray(arr, size);
    
    
    

    return 0;
}
