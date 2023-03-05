#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// gcc -o solution solution.c
// ./solution 1234 (port-1234)
// with another terminal run: nc 127.0.0.1 1234
// Working

struct sockaddr_in server_address;

int compare_char(const void *a1, const void *a2)
{
    return *(char *) a2 - *(char *) a1;
}

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
   
    int server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );
    if (server_sockfd == -1) 
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    
    inet_aton("127.0.0.1", &server_address.sin_addr);
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_family = AF_INET;

    if (bind(server_sockfd, (struct sockaddr *) &server_address,sizeof(server_address)) == -1)
    {
        printf("ERROR on binding\n");
        exit(0);
    } 

    int listen_id = listen(server_sockfd, 5);
    if(listen_id == -1)
    {
        printf("ERROR on listening\n");
        exit(0);
    }
    int newsockfd = accept(server_sockfd, NULL, NULL);
    if(newsockfd == -1)
    {
        printf("Socket was not accepted\n");
        exit(0);
    }

    while(1)
    {
        char buf[BUFSIZ] = {0};
        char sorted_buf[BUFSIZ] = {0};
        int read_bytes = read(newsockfd, buf, BUFSIZ);

        if (strncmp("OFF", buf, 3) == 0) {
            break;
        }
        strncpy(sorted_buf, buf, sizeof buf);
        qsort(sorted_buf, strlen(buf), sizeof *buf, compare_char);
        write(newsockfd, sorted_buf, read_bytes);
    }
    close(newsockfd);
    return 0;
}
