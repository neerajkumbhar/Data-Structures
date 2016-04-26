//
//  main.c
//  integer_to_roman
//
//  Created by Neeraj Kumbhar on 4/19/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct {
    int value;
    char romanDgts[3];
} romanTable[] =    {{1000, "M"},
    {900,   "CM"},
    {500,   "D"},
    {400,   "CD"},
    {100,   "C"},
    {90,    "XC"},
    {50,    "L"},
    {40,    "XL"},
    {10,    "X"},
    {9,     "IX"},
    {5,     "V"},
    {4,     "IV"},
    {1,     "I"}};

char *intToRoman(int n)
{
    char *romanNumerals;
    int i = 0;
    
    romanNumerals = (char *)malloc(sizeof(char) * 10);
    
    while (n) {
        while (n < romanTable[i].value)
            i++;
        while(n >= romanTable[i].value) {
            strcat(romanNumerals, romanTable[i].romanDgts);
            n -= romanTable[i].value;
        }
    }
    
    return romanNumerals;
}

int main(int argc, char const *argv[])
{
    int number;
    char *result;
    
    printf("Input a decimal number: ");
    scanf("%d", &number);
    
    if(number < 0  || number > 3999) {
        printf("Input must be within the range from 1 to 3999.\n");
        return -1;
    }
    
    result = intToRoman(number);
    puts(result);
    
    free(result);
    
    return 0;
}