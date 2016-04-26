//
//  main.c
//  string_longest_substring
//
//  Created by Neeraj Kumbhar on 4/4/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256

int main(int argc, const char * argv[]) {
    
    int *visited = (int *)malloc(sizeof(int)*NO_OF_CHARS);
    int i;
    for (i = 0; i < NO_OF_CHARS;  i++)
        visited[i] = 0;
    
    
    
    char str[] = "aaaabbbbcccc";
    
    visited[str[0]] = 0;
    
    for(int i=0; i<strlen(str); i++)
        visited[str[i]]++;
    
    
    
    
//    int prev_index =  visited[str[1]];
//    printf("\n\n puer index : %d %c\n\n", prev_index, str[1]);
//    visited[str[1]] = 1;
    
    for(int j=0; j<NO_OF_CHARS; j++)
        printf(" %d ", visited[j]);
    
//    int prev_index2 =  visited[str[2]];
//    printf("\n\n puer index : %d %c", prev_index2, str[2]);
    
    
    return 0;
}
