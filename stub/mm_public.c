#include "mm_public.h"

/* Returns microseconds. */
double comp_time (struct timeval times, struct timeval timee)
{
	double elap = 0.0;

	if (timee.tv_sec > times.tv_sec) {
		elap += (((double)(timee.tv_sec - times.tv_sec -1))*1000000.0);
		elap += timee.tv_usec + (1000000-times.tv_usec);
	}
	else {
		elap = timee.tv_usec - times.tv_usec;
	}
	return ((unsigned long)(elap));
}

/* Write these ... */



//allocate all memory, return -1 on failure
int mm_init (mm_t *MM, int tsz)
{
	//make your double linked list
	



}//end mm_init()


//get a chunch of memory (pointer to void) of size sz, NULL on failure
void* mm_get (mm_t *MM, int neededSize)
{

}//end mm_get()


//give back chunck to the memory manager, don't forget to free!
void mm_put (mm_t *MM, void *chunk)
{

}//end mm_get()


//release all memory bac to the system
void mm_release (mm_t *MM)
{
	
}//end mm_release()
