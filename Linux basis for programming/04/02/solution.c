#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int in1 = open("in1", O_RDONLY);
    int in2 = open("in2", O_RDONLY);
    if (in1 == -1 || in2 == -1) {
        perror("open");
        return 1;
    }

    int sum = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(in1, &rfds);
    FD_SET(in2, &rfds);
    int maxfd = MAX(in1, in2) + 1;
    while (1) {
        fd_set rfds_copy = rfds;
        int ret = select(maxfd, &rfds_copy, NULL, NULL, NULL);
        if (ret == -1) {
            perror("select");
            return 1;
        } else if (ret > 0) {
            if (FD_ISSET(in1, &rfds_copy)) {
                char buf[32];
                ssize_t n = read(in1, buf, sizeof(buf));
                if (n == -1) {
                    perror("read");
                    return 1;
                } else if (n == 0) {
                    // Канал in1 закрыт
                    close(in1);
                    FD_CLR(in1, &rfds);
                } else {
                    sum += atoi(buf);
                }
            }
            if (FD_ISSET(in2, &rfds_copy)) {
                char buf[32];
                ssize_t n = read(in2, buf, sizeof(buf));
                if (n == -1) {
                    perror("read");
                    return 1;
                } else if (n == 0) {
                    // Канал in2 закрыт
                    close(in2);
                    FD_CLR(in2, &rfds);
                } else {
                    sum += atoi(buf);
                }
            }
        } else {
            // Timeout (не должно возникать в данной задаче)
        }

        if (FD_ISSET(in1, &rfds) || FD_ISSET(in2, &rfds)) { 
            continue;
        } else {
            printf("%d\n", sum);
            return 0;
        }
    }
}
