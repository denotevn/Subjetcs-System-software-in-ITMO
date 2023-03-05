#include <string.h>

int stringStat(const char *string, size_t multiplier, int *count) {
    int len = strlen(string) * multiplier;
    (*count)++;
    return len;
}