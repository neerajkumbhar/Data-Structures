#include <stdio.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>
#include <stdarg.h>

int errexit(const char *format, ...)
{
    va_list	args;
    
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(1);
}

void *handleTCP(void *);
void *handleUDP(void *);

#define LOCAL_SERVER_PORT 1500
#define TCP_PORT 4000
#define UDP_PORT 5000

int main(int argc, char *argv[])
{
    int sockfdT, sockfdU, newsockfd, portno, clilenT,clilenU, n;
    struct in_addr h_addr;
    struct sockaddr_in serv_addrT, serv_addrU, cli_addrT;
    
    
    if (argc < 1)
    {
        errexit("Insufficent arguments %s\n", strerror(errno));
    }
    
    if((sockfdT = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        errexit("Create Socket failed! %s\n", strerror(errno));
    }
    
    if((sockfdU = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        errexit("Create socket failed!: %s\n", strerror(errno));
    }
    
    
    bzero((char *) &serv_addrT, sizeof(serv_addrT));
    serv_addrT.sin_family = AF_INET;
    serv_addrT.sin_addr.s_addr = INADDR_ANY;
    serv_addrT.sin_port = htons(TCP_PORT);
    
    if (bind(sockfdT, (struct sockaddr *) &serv_addrT, sizeof(serv_addrT)) < 0)
    {
        errexit("Bind Call failed! %s\n", strerror(errno));
    }
    
    bzero((char *) &serv_addrU, sizeof(serv_addrU));
    serv_addrU.sin_family = AF_INET;
    serv_addrU.sin_addr.s_addr = INADDR_ANY;
    serv_addrU.sin_port = htons(UDP_PORT);
    
    if (bind(sockfdU, (struct sockaddr *) &serv_addrU, sizeof(serv_addrU)) < 0)
    {
        errexit("Bind call failed: %s\n", strerror(errno));
    }
    
    
    listen(sockfdT,5);
    
    fd_set rfds;  /* read file descriptor set */
    fd_set afds;  /* active file descriptor set */
    int nfds = getdtablesize();
    FD_ZERO(&afds);
    
    
    
    
    while(1)
    {
        FD_SET(sockfdT, &afds);
        FD_SET(sockfdU, &afds);
        memcpy(&rfds, &afds, sizeof(rfds));
        
        //   struct timeval tval;
        //   tval = (void *)NULL;
        //   memset(&tval, NULL, sizeof(tval));
        
        int a = select(nfds, &rfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
        // printf("%d", a);
        //  errexit("Error in select.");
        
        
        
        if(FD_ISSET(sockfdT, &rfds))
        {
            int ssock;              // msock is ready
            clilenT = sizeof(cli_addrT);
            newsockfd = accept(sockfdT, (struct sockaddr *)&cli_addrT, &clilenT);
            if (newsockfd < 0)
            {
                errexit("Accept call failed: %s\n", strerror(errno));
            }
            
            printf("\n===============================================");
            printf("\nCONNECTED TO TCP CLIENT..\n");
            printf("\nIP of the client: %s", inet_ntoa(cli_addrT.sin_addr));
            printf("\nPort of the client: %d", ntohs(cli_addrT.sin_port));
            
            pthread_t id1;
            if( pthread_create(&id1, NULL, handleTCP, &newsockfd) < 0)
                errexit("pthread_create(prstats): %s\n", strerror(errno));
            
            pthread_join(id1, NULL);
            close(newsockfd);
        }
        
        if(FD_ISSET(sockfdU, &rfds))
        {
            
            //no accept call here. So directly creating threads
            pthread_t id2;
            if(pthread_create(&id2, NULL, handleUDP, sockfdU) < 0)
            {
                errexit("pthread_create(prstats): %s\n", strerror(errno));
            }
            pthread_join(id2, NULL);
            
        }
    }
    
    return 0;
}

void *handleTCP(void *sock_ptr)
{
    
    int n;
    char buffer[1024];
    bzero(buffer,1024);
    int *newsockfd = (int *)sock_ptr;
    
    // ------------------------------------------
    n = read(newsockfd,buffer,1024);
    if(n<0)
        errexit("\nError in read");
    printf("\nString recieved from client: %s",buffer);
    n = write(newsockfd,buffer,strlen(buffer));
    if(n<0)
        errexit("\nError in write: %s\n", strerror(errno));
    
    // -----------------------------------------
    struct timeval timeread;
    memset(&timeread, 0, sizeof(timeread));
    n = read (newsockfd, &timeread, sizeof(timeread));
    if(n<0)
    {
        errexit("Error in read: %s\n", strerror(errno));
    }
    printf("\nTime revieved from client:");
    printf("\n%ld seconds", timeread.tv_sec);
    printf("\n%d microseconds \n", timeread.tv_usec);
    
    // -----------------------------------------
    struct timeval timeecho;
    memset(&timeecho, 0, sizeof(timeecho));
    gettimeofday (&timeecho, NULL);
    n = write(newsockfd,&timeecho, sizeof(timeecho));
    if(n<0)
    {
        errexit("Error in write: %s\n", strerror(errno));
    }
    
    close(newsockfd);
    pthread_exit(NULL);
}


//void *handleUDP(int sockfdU)
void *handleUDP(void *sock_ptr)

{
    int clilenU;
    struct sockaddr_in cli_addrU;
    char buffer[1024];
    
    clilenU = sizeof(cli_addrU);
    bzero(buffer,1024);
    int n;
    int *sockfdU = (int *)sock_ptr;
    
    n = recvfrom(sockfdU, buffer, 1024, 0 , (struct sockaddr *)&cli_addrU,(socklen_t *) &clilenU);
    if(n<0)
    {
        errexit("\nError in recving");
    }
    printf("\n===============================================");
    printf("\nCONNECTED TO UDP CLIENT..\n");
    printf("\nIp of client: %s", inet_ntoa(cli_addrU.sin_addr));
    printf("\nPort of client: %d", ntohs(cli_addrU.sin_port));
    
    printf("\nString recieved from client: %s",buffer);
    n = sendto(sockfdU, buffer, sizeof(buffer),0,(struct sockaddr *)&cli_addrU, sizeof(cli_addrU));
    if(n<0)
        errexit("\nError in seding");
    
    // --------------------------------------------------------------
    struct timeval timec;
    n = recvfrom(sockfdU, &timec, sizeof(timec), 0 , (struct sockaddr *)&cli_addrU,(socklen_t *) &clilenU);
    if(n<0)
        errexit("\ncannot receive data");
    
    printf("\nTime revieved from client:");
    printf("\n%ld seconds", timec.tv_sec);
    printf("\n%d microseconds \n", timec.tv_usec);
    
    struct timeval timeecho;
    memset(&timeecho, 0, sizeof(timeecho));
    gettimeofday (&timeecho, NULL);
    n = sendto(sockfdU, &timeecho, sizeof(timeecho),0,(struct sockaddr *)&cli_addrU, sizeof(cli_addrU));
    if(n<0)
        errexit("\ncannot send data");
    
    close(sockfdU);
    pthread_exit(NULL);
}

