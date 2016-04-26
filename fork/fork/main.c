//
//  main.c
//  fork
//
//  Created by Neeraj Kumbhar on 10/02/15.
//  Copyright (c) 2015 Neeraj Kumbhar. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int cnt;

int increment()
{
    return ++cnt;
}

int main(int argc, const char * argv[])
{
    int i;
    while(i<3)
    {
        fork();
        
        printf("\n child no %d:", i);
        ++cnt;
        printf("\ncnt = %d", cnt);
    }


    
    
    
       /* for (i=0; i<3; i++)
        {
            pid = fork();
            if (pid == -1)
            {
                perror("Error forking");
                return -1;
            }
            else if (pid > 0)
            {
                // parent process
                waitpid(-1, NULL, 0);  // it will wait until the child process is done
            }
            else
            {
                ++cnt;
                printf("\n child no %d: cnt = %d", i , cnt );
               // exit(0);
                break;
            }
        } */
        // do anything else the parent process needs to do
       return 0;
    

}
