// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
    char *d;
    for (d = destination; *source != '\0'; source++, d++) {
        *d = *source;
    }
    *d = *source;
    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    char *d;
    for (d = destination; *source != '\0' && len > 0; source++, d++) {
        *d = *source;
        len--;
    }
    while (len > 0) {
        *d = '\0';
        d++;
        len--;
    }
    return destination;
}

char *strcat(char *destination, const char *source) {
    char *d = destination + strlen(destination);
    while (*source != '\0') {
        *d = *source;
        d++;
        source++;
    }
    *d = '\0';
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    char *d = destination + strlen(destination);
    while (*source != '\0' && len > 0) {
        *d = *source;
        d++;
        source++;
        len--;
    }
    *d = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 < *str2) {
            return -1;
        } else {
            str1++;
            str2++;
        }
    }
    if (*str1 != '\0') {
        return 1;
    }
    if (*str2 != '\0') {
        return -1;
    }
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    while (*str1 != '\0' && *str2 != '\0' && len > 0) {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 < *str2) {
            return -1;
        } else {
            str1++;
            str2++;
        }
        len--;
    }
    if (len == 0) {
        return 0;
    }
    if (*str1 != '\0') {
        return 1;
    }
    if (*str2 != '\0') {
        return -1;
    }
    return 0;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    char *back = (char *)str + strlen(str) - 1;
    while (back != str) {
        if (*back == c) {
            return back;
        }
        back--;
    }
    return NULL;
}

char *strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if (strncmp(haystack, needle, strlen(needle)) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    char *back = (char *)haystack + strlen(haystack) - 1;
    while (back != haystack) {
        if (strncmp(back, needle, strlen(needle)) == 0) {
            return back;
        }
        back--;
    }
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
    char *d = destination;
    char *s = (char *)source;
    while (num > 0) {
        *d = *s;
        d++;
        s++;
        num--;
    }
    *d = *s;
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    char *d = destination;
    char *s = (char *)source;
    if (d < s && d + num > s) {
        while (num > 0) {
            *(d + num - 1) = *(s + num - 1);
            num--;
        }
    } else {
        while (num > 0) {
            *d = *s;
            d++;
            s++;
            num--;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    char *str1 = (char *)ptr1;
    char *str2 = (char *)ptr2;
    while (num > 0) {
        if (*str1 > *str2) {
            return 1;
        } else if (*str1 < *str2) {
            return -1;
        } else {
            str1++;
            str2++;
        }
        num--;
    }
    return 0;
}

void *memset(void *source, int value, size_t num) {
    char *s = source;
    while (num > 0) {
        *s = value;
        s++;
        num--;
    }
    return source;
}
