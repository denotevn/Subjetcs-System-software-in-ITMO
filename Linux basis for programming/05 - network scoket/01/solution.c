#include <netdb.h>
#include<stdio.h>
#include <sys/socket.h>
#include<arpa/inet.h>

// gcc -o gethostbyname gethostbyname.c
// ./gethostbyname yandex.ru

int main(int c, char const *argv[])
{
    if(c!=2)
    {
        return -1;
    }
    struct hostent *h;

    h = gethostbyname(argv[1]);
    if (NULL == h)
    {
        printf("Error\n");
        return -1;
    }
    
    int i =0;
    while(NULL != h->h_addr_list[i])
    {
        struct in_addr *a = (struct in_addr*) h->h_addr_list[i];
        printf("%s\n",inet_ntoa(*a));
        i++;
    }
    return 0;
}