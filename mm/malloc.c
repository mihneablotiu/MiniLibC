// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	void *start = mmap(NULL, size + sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (start == MAP_FAILED) {
		return NULL;
	}

	* (size_t *) start = size;
	mem_list_add((void *)((size_t *) start + 1), size);

	return (void *)((size_t *) start + 1);
}

void *calloc(size_t nmemb, size_t size)
{
	void *start = malloc(nmemb * size);
	for (unsigned long i = 0; i < nmemb; i++) {
		*(size_t *) start = 0;
	}

	return start;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);
	if (item != NULL) {
		mem_list_del(ptr);
		munmap(ptr - sizeof(size_t), *((size_t *) ptr - 1) + sizeof(size_t));
	}
}

void *realloc(void *ptr, size_t size)
{
	size_t old_size = *(((size_t *) ptr) - 1);
	void *start = malloc(size);

	if (size > old_size) {
		memcpy(start, ptr, old_size);
	} else {
		memcpy(start, ptr, size);
	}
	free(ptr);
	return start;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *start = realloc(ptr, nmemb * size);
	if (start == NULL) {
		errno = ENOMEM;
		return NULL;
	}

	return start;
}
