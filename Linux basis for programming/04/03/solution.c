#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// trigger count variable for SIGUSR1
volatile int sigusr1_count = 0; 
// trigger count variable for SIGUSR2
volatile int sigusr2_count = 0; 

void sigusr1_handler(int sig) {
    sigusr1_count++;
}

void sigusr2_handler(int sig) {
    sigusr2_count++;
}

void sigterm_handler(int sig) {
    // When SIGTERM arrives, output the number of processed signals SIGUSR1, 
    // SIGUSR2 and end the program
    printf("%d %d\n", sigusr1_count, sigusr2_count);
    exit(0);
}

int main() {

    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    signal(SIGTERM, sigterm_handler);

    while(1) 
    { 
        sleep(1); // sleep before continue
    }

    return 0;
}
