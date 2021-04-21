#include <coreinit/thread.h>

#include <pthread.h>
#include <stdbool.h>

static void *pthread_entry_point(void *arg)
{
	OSThread *thread = (OSThread *)arg;
	while(thread->valid)
		if(thread->running)
		{
			thread->running = false;
			return (void *)thread->entry(thread->argc, thread->argv); // TODO
		}
}

bool OSCreateThread(OSThread *thread, OSThreadEntryPointFn entry, int argc, void *argv, void *stack, size_t stackSize, int32_t prop, OSThreadAttributes atts)
{
	thread->valid = true;
	thread->running = false;
	thread->name = "";
	thread->entry = entry;
	thread->argc = argc;
	thread->argv = argv;
	return pthread_create(&(thread->pthread), NULL, pthread_entry_point, thread) == 0;
}

void OSSetThreadName(OSThread *thread, const char *name)
{
	thread->name = name;
}

int32_t OSResumeThread(OSThread *thread)
{
	thread->running = true;
	return 0; // TODO
}

bool OSJoinThread(OSThread *thread, int *ret)
{
	*ret = 0; // TODO
	return pthread_join(thread->pthread, NULL) == 0;
}
