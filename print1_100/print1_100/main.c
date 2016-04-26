//
//  main.c
//  print1_100
//
//  Created by Neeraj Kumbhar on 3/8/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>

struct ABC{
    int a;
    float b;
};

int main(int argc, const char * argv[]) {
    
    for(int i=1; i<100; i++)
    {
        if(i % 15 ==0)
            printf("\nGizz");
        else if (i%5 ==0)
            printf("\nBuzz");
        else if (i%3 == 0)
            printf("\nFizz");
        else
            printf("\n%d", i);
    }
    
//    for(int i=1; i<100; i++)
//    {
//        
//        switch (i)
//        {
//            case 'i%15==0':
//                printf("\nGizz");
//            default:
//                printf("\n%d", i);
//        }
//    }
    
    
//    struct ABC *ptr=(struct ABC *)0;
//    ptr++;
//    printf("Size of structure is: %d",*ptr);
    
    
    
    return 0;
}
