//
//  main.cpp
//  string_longest_repeating
//
//  Created by Neeraj Kumbhar on 4/20/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

//Length of the longest substring with repeating characters

// longest contingus repeating characters
//abbbc -> bbb
//abbbcbbbbd -> bbb

#include <iostream>
#include <string>


using namespace std;

int PrintReapting(string str)
{
    
    int n = str.length();
    
    if(n==0)
        return 0;
    
    if(n==1)
        printf("%s", str.c_str());
    
    
    int max_len = 0;
    int curr_len = 1;
    char temp;
    for(int i=0; i<n; i++)
    {
        if(str[i] == str[i+1])
            curr_len++;
        else
            if(curr_len > max_len)
            {
                max_len = curr_len;
                temp = str[i-1];
                curr_len = 1;
            }
        
    }
    
//    if(curr_len > max_len)
//        max_len = curr_len;
    
    printf("Substring - ");
    for(int i=0; i<max_len; i++)
    {
        printf("%c", temp);
    }
    printf("\n");
    return max_len;
   
    
}

int main()
{
    string str = "abbaaabbbbbb";

    printf("%d", PrintReapting(str));
    return 0;
    
}




