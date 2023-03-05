#include <stdio.h>
#include <stdlib.h>

int main() {
    int pid, ppid;
    char stat_path[50];
    FILE* stat_file;
    
    // Get the current process ID (PID)
    pid = getpid();
    
    // Construct the path to the current process's stat file
    sprintf(stat_path, "/proc/%d/stat", pid);
    
    // Open the stat file for the current process
    stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        printf("Failed to open %s\n", stat_path);
        return 1;
    }
    
    // Read the current process's parent process ID (PPID) from the stat file
    fscanf(stat_file, "%*d %*s %*c %d", &ppid);
    
    // Print the current process's PPID
    printf("%d\n",ppid);
    
    // Close the stat file
    fclose(stat_file);
    
    return 0;
}
