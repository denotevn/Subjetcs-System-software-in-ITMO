#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 32
#define PIPE_BUF 32
#define TEN_MEG ( 1024 * 1024 * 10 )

int main() {
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int bytes_read = 0;
    char buffer[BUFFER_SIZE + 1];
    /* Mở đường ống để đọc */
    printf( "Process %d starting to read on pipe\n", getpid() );
    pipe_fd = open( FIFO_NAME, open_mode);

   if (pipe_fd != -1)
    {
        do
        {
            res = read( pipe_fd, buffer, BUFFER_SIZE);
            bytes_read += res;
        } while ( res > 0 );
        (void ) close( pipe_fd );/*Kết thúc đọc*/ 
    }else
    {
        exit( EXIT_FAILURE );
    }
    printf( "Process %d finished, %d bytes read\n", getpid(), bytes_read );
    exit( EXIT_SUCCESS );
}