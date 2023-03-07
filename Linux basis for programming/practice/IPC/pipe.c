#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
/*
Tạo đường ống, gọi hàm fork() để tạo ra tiến trình con. 
Tiến trình cha sẽ đọc dữ liệu nhập vào từ phía người dùng và ghi vào
đường ống trong khi tiến trình con phía bên kia đường ống tiếp nhận dữ 
liệu bằng cách đọc từ đường ống và in ra màn hình.
*/

// định nghĩa kích thước buffer và các chỉ số cho đầu đọc và đầu ghi
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
    /*
    BUFFER_SIZE để lưu trữ thông điệp sẽ được ghi vào đường ống 
    và một biến pid để lưu trữ id của tiến trình con
    */
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    // tạo một đường ống thông qua hàm pipe(). Nếu hàm pipe() trả về -1 thì đường ống tạo thất bại.
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }
    // create child process
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) // Parent process
    {
        printf("Enter a message to send to child process: ");
        fgets(write_msg, BUFFER_SIZE, stdin);
        close(fd[READ_END]); // Close unused read end
        write(fd[WRITE_END], write_msg, BUFFER_SIZE); // Write to pipe
        close(fd[WRITE_END]); // Close write end
        printf("Message sent to child process\n");
    }else { // Child process
        close(fd[WRITE_END]); // Close unused write end
        read(fd[READ_END], read_msg, BUFFER_SIZE); // Read from pipe
        printf("Message received from parent process: %s", read_msg);
        close(fd[READ_END]); // Close read end
    }

    return 0;

}