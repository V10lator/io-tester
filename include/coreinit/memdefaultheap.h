#ifndef NUSSPLI_TEST_CORE_MEMDEFAULTHEAP_H
#define NUSSPLI_TEST_CORE_MEMDEFAULTHEAP_H

#include <stdint.h>
#include <stdlib.h>

#define MEMAllocFromDefaultHeap		malloc
#define MEMFreeToDefaultHeap		free

void *MEMAllocFromDefaultHeapEx(uint32_t size, int al);

#endif
