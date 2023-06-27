// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    long returnValue = syscall(9, addr, length, prot, flags, fd, offset);

    if (returnValue >= 0) {
        return (void *) returnValue;
    }

	errno = -returnValue;
	return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long returnValue = syscall(25, old_address, old_size, new_size, flags);

    if (returnValue >= 0) {
        return (void *) returnValue;
    }

	errno = -returnValue;
	return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	long returnValue = syscall(11, addr, length);

    if (returnValue >= 0) {
        return 0;
    }

	errno = -returnValue;
	return -1;
}
