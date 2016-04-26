//
//  main.c
//  extern_example
//
//  Created by Neeraj Kumbhar on 2/16/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
extern int var;

int main(int argc, const char * argv[]) {
    
    var = 10;
//  int var = 10;
    printf("\n\nHello, World!\n");
    return 0;
}
