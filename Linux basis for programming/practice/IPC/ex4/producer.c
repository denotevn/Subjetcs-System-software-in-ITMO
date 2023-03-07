#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "my_fifo"/*Tạo đường ống*/
#define BUFFER_SIZE  32
#define PIPE_BUF 32 /*Vùng đệm dùng cho đường ống*/
#define TEN_MEG ( 1024 * 1024 * 10 ) /*Dữ liệu*/

int main()
{
    int pipe_fd;
    int res;
    int open_mode = O_WRONLY;
    int bytes_sent = 0;
    char buffer[BUFFER_SIZE + 1];
    // Create pipe
    /*Tạo pipe nếu chưa có*/
    if ( access( FIFO_NAME, F_OK ) == -1 )
    {
        res = mkfifo( FIFO_NAME, (S_IRUSR | S_IWUSR) );
        if ( res != 0 )
        {
            fprintf( stderr, "FIFO object not created [%s]\n", FIFO_NAME);
            exit( EXIT_FAILURE );
        }
    }

    /*Mở đường ống để ghi*/
    printf( "Process %d starting to write on pipe\n", getpid() );
    pipe_fd = open( FIFO_NAME, open_mode);
    if ( pipe_fd != -1 )
    {
        /*Liên tục đổ vào đường ống*/
        while ( bytes_sent < TEN_MEG )
        {
            res = write( pipe_fd, buffer, BUFFER_SIZE );
            if ( res == -1 )
            {
                fprintf( stderr, "Write error on pipe\n" );
                exit( EXIT_FAILURE );
            }
            bytes_sent += res;
        }
        /*Kết thúc quá trình ghi dữ liệu*/
        ( void ) close( pipe_fd );
    }else{
        exit( EXIT_FAILURE );
    }

    printf( "Process %d finished, %d bytes sent\n", getpid(), bytes_sent );
    exit( EXIT_SUCCESS );
}