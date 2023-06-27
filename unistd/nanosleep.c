#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long returnValue = syscall(35, req, rem);

    if (returnValue >= 0) {
        return 0;
    }

    errno = -returnValue;
    return -1;
}
