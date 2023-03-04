#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2)
{
    //allocate an uninitialized block of memory
    char *buffer = malloc(strlen(s1) + strlen(s2) + 1);

    if (NULL == buffer) {
        printf("Input failed\n");
        exit(1);
    }

    strcpy(buffer, s1);
    strcat(buffer, " ");
    strcat(buffer, s2);
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <utility> <param>\n", argv[0]);
        return 1;
    }
    char *command = concat(argv[1], argv[2]);

    FILE *fp = popen(command, "r");
    if (fp == NULL) 
    {
        printf("Failed to run command\n" );
        exit(1);
    }

    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '0') {
            count++;
        }
    }

    pclose(fp);
    printf("%d\n", count);
    return 0;
}
