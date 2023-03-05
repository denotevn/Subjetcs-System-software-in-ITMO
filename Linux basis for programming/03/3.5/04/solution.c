#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

pid_t get_parent_pid(const pid_t pid)
{
    pid_t ppid = pid;
    char path[100];
    char buffer[1024];
    sprintf(path, "/proc/%d/stat", pid);
    FILE *fd = fopen(path, "r");

    if (fd == NULL) {
        perror("fd");
        printf("Error path: %s\n", path);
        exit(1);
    }

    size_t size = fread(buffer, sizeof(char), sizeof(buffer), fd);
    if (size > 0) {
        int counter = 0;
        char *pch = strtok(buffer, " ");
        while (counter != 2) {
            pch = strtok(NULL, " ");
            counter++;
        }
        ppid = atoi(strtok(NULL, " "));
    }

    fclose(fd);

    return ppid;
}

int count_descendants(const pid_t needle, int counter)
{
    DIR *dir;
    struct dirent *ent;

    // Open the directory /proc
    if ((dir = opendir("/proc/")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            pid_t pid = atoi(ent->d_name);

            if (pid > 0) {
                pid_t ppid = get_parent_pid(pid);
                if (ppid == needle) {
                    counter = count_descendants(pid, counter);
                    counter += 1;
                }
            }
        }
    } else {
        perror("dir");
        exit(EXIT_FAILURE);
    }

    closedir(dir);

    return counter;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || (atoi(argv[1])) <= 0) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t needle = atoi(argv[1]);
    int counter = count_descendants(needle, 1);
    printf("%d\n", counter);

    return 0;
}
