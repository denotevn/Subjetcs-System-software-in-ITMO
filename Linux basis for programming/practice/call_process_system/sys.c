#include<stdlib.h>
#include<stdio.h>

int main()
{
    printf("Thuc thi lenh ps voi system: \n");
    system("ps -ax");
    system("mkdir daihoc");// Tep dai hoc se duoc tao ra
    printf("Thuc hien xong\n");
    return 0;
}