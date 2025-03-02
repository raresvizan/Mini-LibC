#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    if (nanosleep(&req, &rem) < 0) {
        return rem.tv_sec;
    }

    return 0;
}
