// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	long returnValue = syscall(8, fd, offset, whence);

	if (returnValue >= 0) {
		return returnValue;
	}

	errno = -returnValue;
	return -1;
}
