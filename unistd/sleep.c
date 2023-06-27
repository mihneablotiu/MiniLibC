#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    const struct timespec time = {seconds, 0};
    struct timespec remTime = {0, 0};
    int returnValue = nanosleep(&time, &remTime);

    if (returnValue == 0) {
        return 0;
    }

    return remTime.tv_sec;
}
