#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>

int puts(const char *s) {
    char *buffer = malloc((strlen(s) + 2) * sizeof(*buffer));
    strcpy(buffer, s);
    strcat(buffer, "\n");

    long returnValue = syscall(1, 1, buffer, strlen(buffer));
    free(buffer);

    if (returnValue >= 0) {
        return returnValue;
    }

    return -1;
}
