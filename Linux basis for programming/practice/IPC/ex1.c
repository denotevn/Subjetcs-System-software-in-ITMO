# include<stdio.h>
#include<unistd.h>
#include <signal.h>

// Ctrl+C: gởi tín hiệu INT( SIGINT ) đến tiến trình, ngắt ngay tiến trình (interrupt).
// Ctrl+Z: gởi tín hiệu TSTP( SIGTSTP ) đến tiến trình, dừng tiến trình (suspend).
// Ctrl+\: gởi tín hiệu ABRT( SIGABRT ) đến tiến trình, kết thúc ngay tiến trình (abort)

// Chuong trinh se khong bi cat ngang khi nguoi dung an Ctrl+C
void catch_int(int sig_num)
{
    signal(SIGINT, catch_int);
    printf("Do not press Ctrl + C \n");
}

/*Chương trình chính*/
int main()
{
    int count = 0;
    /*Thiết lập hàm xử lý cho tín hiệu INT(Ctrl + C)*/
    signal( SIGINT, catch_int );
    /*Đặt bẫy tín hiệu INT*/
    while ( 1 )
    {
        printf( "Counting … %d\n", count++ );
        sleep( 1 );
    }
}