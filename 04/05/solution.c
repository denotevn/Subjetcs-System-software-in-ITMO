#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <unistd.h>

#define SM_SIZE 1000
#define NUM_INTS 100

int *shm_ptr1, *shm_ptr2, *shm_res;

void cleanup(int sig) {
    // Giải phóng các vùng bộ nhớ dùng chung
    shmctl(shm_ptr1, IPC_RMID, NULL);
    shmctl(shm_ptr2, IPC_RMID, NULL);
    shmctl(shm_res, IPC_RMID, NULL);
    exit(0);
}

int main(int argc, char const *argv[]) {
    // Tạo key cho các vùng bộ nhớ dùng chung
    key_t key1 = atoi(argv[1]);
    key_t key2 = atoi(argv[2]);
    key_t key_res = ftok("/home/tuandinh/Desktop/Linux_programming_tutorial/04/05", 3);

    // Tạo các vùng bộ nhớ dùng chung
    shm_ptr1 = shmget(key1, SM_SIZE, IPC_CREAT | 0666);
    shm_ptr2 = shmget(key2, SM_SIZE, IPC_CREAT | 0666);
    shm_res = shmget(key_res, SM_SIZE, IPC_CREAT | 0666);

    // Kiểm tra xem việc tạo vùng bộ nhớ dùng chung có thành công không
    if (shm_ptr1 == -1 || shm_ptr2 == -1 || shm_res == -1) {
        perror("Error creating shared memory segment");
        exit(1);
    }

    // Gán con trỏ tới vùng bộ nhớ dùng chung
    int *p1 = (int *) shmat(shm_ptr1, NULL, 0);
    int *p2 = (int *) shmat(shm_ptr2, NULL, 0);
    int *p_res = (int *) shmat(shm_res, NULL, 0);

    // Tính tổng theo cặp 100 số đầu tiên trong các vùng bộ nhớ
    for (int i = 0; i < NUM_INTS; i++) {
        p_res[i] = p1[i] + p2[i];
    }

    // In khóa của vùng bộ nhớ dùng chung mới
    printf("Shared memory key: %d\n", key_res);

    // Đăng ký xử lý tín hiệu SIGINT để giải phóng các vùng bộ nhớ dùng chung
    signal(SIGINT, cleanup);

    // Chờ tín hiệu SIGINT
    while (1) {
        pause();
    }

    return 0;
}
