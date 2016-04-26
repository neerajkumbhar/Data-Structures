//
//  main.cpp
//  string_longest_withoutreapeating
// maximum occuring character

//  Created by Neeraj Kumbhar on 4/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.


#include <iostream>
#include <string>

using namespace std;

void longestwithoutrepeating(string str)
{
    
    int n  = str.length();
    int max_len = 0;
    int curr_len = 0;
    int prev_index;
    
    int *visited = (int *)malloc(sizeof(int)*256);
    for(int i=0; i<256; i++)
        visited[i] = -1;
    
    visited[str[0]] = 0;

    for(int i =1; i<n; i++)
    {
        prev_index = visited[str[i]];
        if(prev_index == -1 || i - curr_len > prev_index) // meaning occuring for the first time
        {
            curr_len++;
        }
        else
        {
            if(curr_len > max_len)
            {
                max_len = curr_len;
                curr_len = i - prev_index;
            }
        }
        
        visited[str[i]] = i;
        if(curr_len > max_len)
            max_len = curr_len;
    }
    
    cout << max_len;
    
}


char maximum_occuring_character(string str)
{
    char result = ' ';
    int len = str.length();
    
    int *visited = (int *)malloc(sizeof(int)*256);
    for(int i=0; i<256; i++)
        visited[i] = 0;
    
    for(int i = 0; i<len; i++)
    {
        visited[str[i]]++;
    }
    
    int max = -1;
    for(int j = 0; j <len; j++)
    {
        if(visited[str[j]]  > max)
        {
            result = str[j];
            max = visited[str[j]];
        }
    }
    
    cout << "\nOccurance count : " << max;
    return result;
}

int main()
{
    
    string str = "geekkkks";
    longestwithoutrepeating(str);
    printf("\nOccurance character = %c", maximum_occuring_character(str));
    printf("\n");
    
    
    int *s1;
    printf("Size %d", sizeof(s1));
    
    
    return 0;
}