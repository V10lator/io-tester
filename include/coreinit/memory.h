#ifndef NUSSPLI_TEST_CORE_MEMORY_H
#define NUSSPLI_TEST_CORE_MEMORY_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdbool.h>
#include <string.h>

void *OSBlockMove(void *dest, const void *src, size_t size, bool flush);

#ifdef __cplusplus
	}
#endif

#endif
