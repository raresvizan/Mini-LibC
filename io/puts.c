#include <unistd.h>

int puts(const char *str) {
    int len = 0;
    while (*(str + len) != '\0') {
        len++;
    }
    write(1, str, len);
    write(1, "\n", 1);
    len++;
    return len;
}
