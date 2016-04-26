//
//  main.c
//  hashing_LinearProbing
//
//  Created by Neeraj Kumbhar on 2/25/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>


int hashfunction(int val)
{
    int hash = val % 10;
    return hash;
    
}


int hashtable[10];

int put(int key)
{
   
    if(hashtable[key] == NULL)
    {
        return key;
    }
    else
    {
        key++;
        key = put(key);
    }
    
    return key;
}


void get(int key)
{
    printf("value = %d ", hashtable[key]);
    
}

int main(int argc, const char * argv[]) {
    
    int input_arr[8] = {2,5, 12, 4, 15, 25, 35, 14};
    
    int key;
    
    for(int i=0; i<10; i++)
    {
        hashtable[i] = NULL;
        
    }
    
    for(int i=0; i<8; i++)
    {
        key = hashfunction(input_arr[i]);
        
        key = put(key);
        hashtable[key] = input_arr[i];
        
    }
    
    
    for(int i=0; i<10; i++)
    {
        printf("\n%d  ", hashtable[i]);
    }
    
    
    printf("\n\nEnter the key");
    scanf("%d", &key);
    
    get(key);
    
    return 0;
}
