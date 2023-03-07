// nhan ban tien trinh torng C
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t new_pid;
    new_pid = fork();
    switch(new_pid)
    {
        case -1: printf( "Khong the tao tien trinh moi" );  break;
        case 0: printf( "Day la tien trinh con" );
        // mã lệnh dành cho tiến trình con đặt ở đây
        break;
        default: printf( "Day la tien trinh cha" );
        // mã lệnh dành cho tiến trình cha đặt ở đây
        break;
    }
    return 0;
    
}



