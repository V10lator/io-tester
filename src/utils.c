#include <utils.h>

#include <stdio.h>

void debugPrintf(const char *str, ...)
{
	printf(str);
	printf("\n");
}