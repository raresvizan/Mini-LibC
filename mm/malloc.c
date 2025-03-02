// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (p == MAP_FAILED) {
        return NULL;
    }
    mem_list_add(p, size);
    return p;
}

void *calloc(size_t nmemb, size_t size) {
    void *p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (p == MAP_FAILED) {
        return NULL;
    }

    return p;
}

void free(void *ptr) {
    struct mem_list *new = mem_list_find(ptr);
    if (munmap(ptr, new->len) != -1) {
        if (new != NULL) {
            mem_list_del(ptr);
        }
    }
}

void *realloc(void *ptr, size_t size) {
    void *new = malloc(size);

    if (new == NULL) {
        return NULL;
    }

    memcpy(new, ptr, size);

    free(ptr);

    return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    realloc(ptr, nmemb * size);
    return ptr;
}
