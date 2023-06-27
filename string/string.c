// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdlib.h>

char *strcpy(char *destination, const char *source)
{
	char *positionDest;

	for (positionDest = destination; *source != '\0'; source++, positionDest++) {
		*positionDest = *source;
	}

	*positionDest = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *positionDest = destination;

	for (unsigned long i = 0; i < len; i++) {
		if (*source != '\0') {
			*positionDest = *source;
		} else {
			for (; i < len; i++) {
				*positionDest = '\0';
				positionDest++;
			}
		}

		positionDest++;
		source++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *positionDest = destination + strlen(destination);

	for(; *source != '\0';  source++, positionDest++) {
		*positionDest = *source;
	}

	*positionDest = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *positionDest = destination + strlen(destination);

	for (unsigned long i = 0; i < len; i++) {
		if (*source != '\0') {
			*positionDest = *source;
		} else {
			*positionDest = *source;
			return destination;
		}

		source++;
		positionDest++;
	}

	*positionDest = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while(*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}

		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 != '\0') {
		return -1;
	} else if (*str1 != '\0' && *str2 == '\0') {
		return 1;
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned long i = 0;

	while(*str1 != '\0' && *str2 != '\0' && i < len) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}

		str1++;
		str2++;
		i++;
	}

	if (i < len) {
		if (*str1 == '\0' && *str2 != '\0') {
			return -1;
		} else if (*str1 != '\0' && *str2 == '\0') {
			return 1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *positionStr = (char *) str;

	while (*positionStr != '\0') {
		if (*positionStr == c) {
			return positionStr;
		}

		positionStr++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *positionStr = (char *) str + strlen(str) - 1;

	while (positionStr != str) {
		if (*positionStr == c) {
			return positionStr;
		}

		positionStr--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	if (strcmp(needle, "") == 0) {
		return (char *) haystack;
	}

	char *positionHaystack = (char *) haystack;
	char *positionNeedle = (char *) needle;
	int needleFound = 1;

	while (*positionHaystack != '\0') {
		if (*positionHaystack == *positionNeedle) {
			needleFound = 1;
			char *currentPosHayStack = positionHaystack;

			while (*positionNeedle != '\0') {
				if (*currentPosHayStack != *positionNeedle) {
					positionNeedle = (char *) needle;
					needleFound = 0;
					break;
				}

				currentPosHayStack++;
				positionNeedle++;
			}

			if (needleFound == 1) {
				return positionHaystack;
			}
		}

		positionHaystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (strcmp(needle, "") == 0) {
		return (char *) haystack;
	}

	char *positionHaystack = (char *) haystack + strlen(haystack) - 1;
	char *positionNeedle = (char *) needle;
	int needleFound = 1;

	while (positionHaystack != haystack) {
		if (*positionHaystack == *positionNeedle) {
			needleFound = 1;
			char *currentPosHayStack = positionHaystack;

			while (*positionNeedle != '\0') {
				if (*currentPosHayStack != *positionNeedle) {
					positionNeedle = (char *) needle;
					needleFound = 0;
					break;
				}

				currentPosHayStack++;
				positionNeedle++;
			}

			if (needleFound == 1) {
				return positionHaystack;
			}
		}

		positionHaystack--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *positionDest = destination;

	for (unsigned long i = 0; i < num; i++) {
		*positionDest = *(char *)source;
		(char *)source++;
		positionDest++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *temporary = malloc(num * sizeof(*temporary));
	char *temporaryPosition = temporary;

	for (unsigned long i = 0; i < num; i++) {
		*temporaryPosition = *(char *)source;
		(char *)source++;
		temporaryPosition++;
	}

	char *positionDest = destination;
	temporaryPosition = temporary;

	for (unsigned long i = 0; i < num; i++) {
		*positionDest = *temporaryPosition;
		temporaryPosition++;
		positionDest++;
	}

	free(temporary);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	for (unsigned long i = 0; i < num; i++) {
		if (*(char *)ptr1 != *(char *)ptr2) {
			return (int) ((*(char *)ptr1) - (*(char *)ptr2));
		}
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *positionSource = source;

	for (unsigned long i = 0; i < num; i++) {
		*positionSource = (char)value;
		positionSource++;
	}

	return source;
}
