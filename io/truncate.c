// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	long returnValue = syscall(76, path, length);

	if (returnValue >= 0) {
		return returnValue;
	}

	errno = -returnValue;
	return -1;
}
