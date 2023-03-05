# Note 
+ gethostbyname: man getshostbyname

```
#include <netdb.h>
#include<stdio.h>

// gcc -o gethostbyname gethostbyname.c
// ./gethostbyname yandex.ru

int main(int c, char **v)
{
    if(c!=2)
    {
        return -1;
    }
    struct hostent *h;
    h = gethostbyname(v[1]);
    if (NULL == h)
    {
        printf("Error\n");
        return -1;
    }
    printf("Canonical name%s", h->h_name);
    printf("Type = %s len = %d\n", (h->h_addrtype == AF_INET) ? "ip4" : "ip6", h->h_length);
}
```
+ [inet](https://man7.org/linux/man-pages/man3/inet.3.html): man inet - operation with adress
> char *inet_ntoa(struct in_addr in);  - convert network adress to char* (text)
> int inet_aton(const char *cp, struct in_addr *inp); - convert text format to struct *in_addr

## TCP/IP
+ Tao client vaf sever tren command line
1. nc 3000 -> nc 3000 -l (sever) - l(listen)
2. nc 3000 -> nc localhost 3000 -> vim data(viet file helloword)-> nc localhost 3000 <data
> helloword se xuat hien o ben server
> Sau do 2 chuong trinh se ken noi va doc du liu cua nhau
> 5.5 video thu 2
## UDP
1. Sever
> nc localhost -u 3000  -l
2. Client
> netstat -anp | grep 3000
> nc localhost 3000 -u
## Code
```

```