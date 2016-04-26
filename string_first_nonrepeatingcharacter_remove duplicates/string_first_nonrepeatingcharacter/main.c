//
//  main.c
//  string_first_nonrepeatingcharacter
//
//  Created by Neeraj Kumbhar on 4/4/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define bool int
#define NO_OF_CHARS 256

void firstnonrepeating(char *str)
{
    int count[256] = {0};
    int index = -1;
    int len = strlen(str);
    
    for(int i=0; i<len; i++)
        count[str[i]]++;
    
    for(int j=0;j<len; j++)
    {
        if(count[str[j]] == 1)
        {
            index = j;
            break;
        }
    }
    
    if(index == -1)
        printf("All are repeating!");
    else
        printf("%c is the first non repeating character! ", str[index]);
        printf("\n");
    
}


void removeduplicates(char *str)
{
    bool visited[NO_OF_CHARS] = {0};
    int i = 0, j=0;
    char temp;
    
    while(*(str + i))
    {
        temp = *(str + i);
        if(visited[temp]==0)
        {
            visited[temp] = 1;
            *(str + j) = *(str + i);
            j++;
        }
        i++;
    }
    
    *(str + j) = '\0';
    
    printf("\nString after removing duplicates: %s \n\n", str);
    
}

int main(int argc, const char * argv[]) {
    
    char str[] = "neeraj";
    firstnonrepeating(str);
    removeduplicates(str);
    return 0;
}
