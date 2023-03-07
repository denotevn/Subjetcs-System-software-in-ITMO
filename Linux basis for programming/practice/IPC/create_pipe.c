#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>


int main()
{
    // Đường ống được tạo ra từ hàm pipe() được gọi là đường ống vô danh (anonymouse pipe).
    // int pipes[2];
    // int rc = pipe(pipes);
    // if (rc == -1)
    // {
    //     perror("Error: Pipe not created !");
    //     exit(1);
    // }
    // Tạo pipe đặt tên với hàm mkfifo()
    int res = mkfifo("~/tmp/my_fifo", 0777); // === mkfifo ~/tmp/my_fifo --mode=0777
    if ( res == 0 ) printf( "FIFO object created" );
    exit ( EXIT_SUCCESS );


}