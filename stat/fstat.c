// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	long returnValue = syscall(5, fd, st);

	if (returnValue >= 0) {
		return returnValue;
	}

	errno = -returnValue;
	return -1;
}
