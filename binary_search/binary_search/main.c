//
//  main.c
//  binary_search
//
//  Created by Neeraj Kumbhar on 3/12/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

int binarysearch(int arr[], int low, int high, int value)
{
    
        if( low > high)
        return -1;
    
        int mid = low + (high - low)/2;
        
        if(arr[mid] > value)
            return binarysearch(arr, low, mid-1, value);
        else if (arr[mid] < value)
            return binarysearch(arr, mid+1, high, value);
        else
            return mid;
    
    
    return -1;
}


//int binarysearch(int arr[], int l, int r, int x)
//{
//    if (l <= r)
//    {
//        int mid = l + (r - l)/2;
//        
//       
//        if (arr[mid] == x)  return mid;
//        
//        if (arr[mid] > x)
//            return binarysearch(arr, l, mid-1, x);
//        
//        return binarysearch(arr, mid+1, r, x);
//    }
//    return -1;
//}

int main(int argc, const char * argv[]) {
   
    int arr[] = {2,4,6,8,13,45,67,89};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int a = binarysearch(arr, 0, size-1, 9);
    
    if(a == -1)
        printf("\nElement NOT present\n");
    else
        printf("\nElement present\n");
    return 0;
}
