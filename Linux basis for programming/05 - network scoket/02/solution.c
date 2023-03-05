#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include <string.h>

struct sockaddr_in local;
int BUFFER_SIZE = 5000;
// gcc udp.c -o udp
// ./upd
// sau do mo terminal khac chay nc 127.0.0.1 -u 1234 de tao client

int main(int c, char const *argv[])
{
    if(c != 2)
    {
        printf("Enter port number\n");
        return -1;
    }
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    // check 
    if (s == -1) {
        printf("Socket was not created\n");
        return -1;
    }

    inet_aton("127.0.0.1", &local.sin_addr);
    // use htons for true port
    local.sin_port = htons(atoi(argv[1]));
    local.sin_family = AF_INET;

    int result = bind(s, (struct sockaddr*) &local, sizeof(local));

    char buf[BUFFER_SIZE];
    while(1)
    {
        int lenght = read(s,buf,BUFFER_SIZE);
        buf[lenght] = '\0';
        if (strcmp(buf, "OFF\n") == 0)
        {
            break;
        }else{
            printf("%s\n", buf);
        }

    }

    return 0;

}