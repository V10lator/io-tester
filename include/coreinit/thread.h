#ifndef NUSSPLI_TEST_CORE_THREAD_H
#define NUSSPLI_TEST_CORE_THREAD_H

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#define OSSleepTicks	usleep

typedef uint8_t OSThreadAttributes;
typedef int (*OSThreadEntryPointFn)(int argc, const char **argv);

typedef struct
{
	pthread_t pthread;
	char *name;
	volatile bool valid;
	volatile bool running;
	OSThreadEntryPointFn entry;
	int argc;
	void *argv;
} OSThread;

typedef enum
{
	OS_THREAD_ATTRIB_AFFINITY_CPU0 =	0x00000001,
	OS_THREAD_ATTRIB_AFFINITY_CPU1 =	0x00000010,
	OS_THREAD_ATTRIB_AFFINITY_CPU2 =	0x00000100,
	OS_THREAD_ATTRIB_AFFINITY_ANY =		0x00000111,
	OS_THREAD_ATTRIB_DETACHED =		0x00001000,
	OS_THREAD_ATTRIB_STACK_USAGE =		0x00100000,
} OS_THREAD_ATTRIB;

static void *pthread_entry_point(void *arg);

bool OSCreateThread(OSThread *thread, OSThreadEntryPointFn entry, int argc, void *argv, void *stack, size_t stackSize, int32_t prop, OSThreadAttributes atts);
void OSSetThreadName(OSThread *thread, const char *name);
int32_t OSResumeThread(OSThread *thread);
bool OSJoinThread(OSThread *thread, int *ret);

#endif
