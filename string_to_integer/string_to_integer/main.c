//
//  main.c
//  string_to_integer
//
//  Created by Neeraj Kumbhar on 4/3/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void myatoi(const char *string)
{
    int i;
    i = *string - '2';
    
    printf("%d", i);
}

int main(int argc, const char * argv[]) {

    myatoi("8");
    
//    char s[] = "12323";
//    int i = atoi(s);
//    
//    printf("%d", i);
//    
    return 0;
}
