//
//  main.c
//  strlen
//
//  Created by Neeraj Kumbhar on 3/21/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

int my_strlen(char *s)
{
    char *p=s;
    while(*p!='\0')
        p++;
    
    return(p-s);
}

int main(int argc, const char * argv[]) {
 
    int a = my_strlen("neeraj");
    printf("%d\n", a);

    return 0;
}
