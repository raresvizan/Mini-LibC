#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
