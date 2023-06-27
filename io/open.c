// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	va_list args;
	va_start(args, flags);
	mode_t mode = va_arg(args, mode_t);

	long returnValue = syscall(2, filename, flags, mode);

	if (returnValue >= 0) {
		va_end(args);
		return returnValue;
	}

	va_end(args);
	errno = -returnValue;
	return -1;
}
