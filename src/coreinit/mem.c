#include <coreinit/memory.h>
#include <coreinit/memdefaultheap.h>

#include <stdbool.h>

void *OSBlockMove(void *dest, const void *src, size_t size, bool flush)
{
	memcpy(dest, src, size);
}

void *MEMAllocFromDefaultHeapEx(uint32_t size, int al)
{
	return aligned_alloc(al, size);
}
