//
//  main.c
//  primenos
//
//  Created by Neeraj Kumbhar on 3/12/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>


//int main(int argc, const char * argv[]) {
//
//    int n, flag;
//    printf("Enter a number");
//    scanf("%d", &n);
//    
//    for(int i=2; i<n ; i++)
//    {
//        if(n%i == 0)
//        {
//            flag = 1; // not a prime
//            break;
//         
//        }
//    }
//    
//    if(flag ==0)
//         printf("\nPrime no\n");
//    else
//         printf("\nNOT A PRIME\n");
//    return 0;
//}


/// prime nos in a range
int main(int argc, const char * argv[]) {
    
    int n1, n2, flag;
    printf("Enter 2 ranges");
    scanf("%d %d", &n1, &n2);
    
    for(int i = n1+1 ; i<n2; i++)
    {
        flag = 0;
        for(int j=2; j<=i/2; ++j)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }
        }
        
        if(flag==0)
            printf(" %d ", i);
        
    }
    
    return 0;
}


