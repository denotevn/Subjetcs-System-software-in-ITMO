#include <stdio.h>
#include <stdlib.h>

int main() {

    size_t multiplier = 2;
    int count = 0;
    printf("Count is %d\n", count);

    int len = stringStat("Hello Word", multiplier, &count);

    printf("Multi 'Hello word' by %ld. Result is: %d. Count is %d\n", multiplier, len, count);

    return 0;
}
