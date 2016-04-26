//
//  main.c
//  realloc
//
//  Created by Neeraj Kumbhar on 3/3/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    
    int *ptr = (int *) malloc(sizeof(int)*2);
    
    *ptr = 10;
    *(ptr +1 ) = 20;
    
    int *ptr_new;
    
    ptr_new = (int *) realloc(ptr, sizeof(int)*3);
    *(ptr_new + 2) = 30;
    
    for(int i =0; i<3; i++)
        printf(" %d ", *(ptr_new + i));
    
    
    return 0;
}
