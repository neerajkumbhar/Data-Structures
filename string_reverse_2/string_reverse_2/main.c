//
//  main.c
//  string_reverse_2
//
//  Created by Neeraj Kumbhar on 4/4/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

void reverse(char *l, char *r)
{
    char *t;
    while(l<r)
    {
        t = *l;
        *l++ = *r;
        *r-- = t;
    
    }
}


void reverseWords(char *s)
{
    char *word_begin = s;
    char *temp = s;
    
    
    while (*temp)
    {
        temp++;
        if(*temp == '\0')
        {
            reverse(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    }
    
  //  O/P: naS esoJ etatS ytisrevinU
  //  when you call this reverse, it reverses the whole string.
    
    //` reverse(s, temp-1);
    
}


void reverseRecursion(char *s)
{
    if(*s)
    {
        reverseRecursion(s+1);
        printf("%c", *s);
    }
}


int main(int argc, const char * argv[]) {
    char s[] = "Hello World";
    reverseWords(s);
   // reverseRecursion(s);
    printf("%s\n\n", s);
    return 0;
}
