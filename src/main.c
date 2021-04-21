#include <ioThread.h>
#include <utils.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TESTFILES	10
#define TEST_BUFSIZE	4096

int main(int argc, void *argv)
{
	debugPrintf("main()");
	size_t fc = 0;
	if(initIOThread())
	{
		debugPrintf("I/O thread started!");
		srand(time(NULL));
		
		//TODO...
		uint8_t buf[TEST_BUFSIZE];
		for(int i = 0; i < TEST_BUFSIZE; i++)
			buf[i] = rand();
		FILE *f;
		unsigned int r;
		size_t fn = 0;
		char fns[512];
		for( ; fc < TESTFILES; fc++)
		{
			sprintf(fns, "temp-%04d.file", ++fn);
			remove(fns);
			f = fopen(fns, "wb");
			do
			{
				r = rand();
				if(r > RAND_MAX - (16 * 1024))
					r = 0;
				else
				{
					while(r > TEST_BUFSIZE)
						r >>= 1;
					
					if(rand() < RAND_MAX / 2)
						r >>= 1;
					
					if(r != 0)
						addToIOQueue(buf, 1, r, f);
				}
			}
			while(r != 0);
			addToIOQueue(NULL, 0, 0, f);
		}
		
		shutdownIOThread();
		fn = 0;
		for(size_t i = 0; i < fc; i++)
		{
			sprintf(fns, "temp-%04d.file", ++fn);
			remove(fns);
		}
	}
	debugPrintf("bye!");
	return 0;
}
