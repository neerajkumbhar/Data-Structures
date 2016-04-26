//
//  main.c
//  string_permute_2
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

#define N 3

void permute(char list[], int k, int m)
{
    char temp;
    int i;
    
        if(k==m)
        {
            for(i=0; i<N; i++)
                printf("%c", list[i]);
            
            printf("\n");
        }
        else
        {
            for(i=k; i<m ; i++)
            {
                temp = list[i];
                list[i] = list[m-1];
                list[m-1] = temp;
                
                permute(list, k, m-1);
                
                temp = list[m-1];
                list[m-1] = list[i];
                list[i] = temp;
            }
        }
    
}


int main(int argc, const char * argv[]) {
   
    char list[3] = {'a','b','c'};
    
    permute(list, 0, N);
    return 0;
}
