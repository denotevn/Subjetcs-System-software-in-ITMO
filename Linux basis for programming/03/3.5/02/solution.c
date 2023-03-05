#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main() {
    int count = 0;
    char command[MAX_LINE_LEN];
    FILE* cmd_output;
    char line[MAX_LINE_LEN];
    
    snprintf(command, MAX_LINE_LEN, "pgrep genenv");
    
    // Open a pipe to execute the command and read its output
    cmd_output = popen(command, "r");
    if (cmd_output == NULL) {
        printf("Failed to execute command: %s\n", command);
        return 1;
    }
    
    // Read each line of output from the command
    while (fgets(line, MAX_LINE_LEN, cmd_output) != NULL) {
        count++;
    }
    
    // Close the pipe
    pclose(cmd_output);
    
    printf("%d\n", count);
    
    return 0;
}
