#include "mm_public.h"

int main (int argc, char **argv)
{
	int j, i;
	struct timeval times, timee;
	void *chunk = NULL;
	mm_t MM;

	j = gettimeofday (&times, (void *)NULL);

	//if mm_init fails...
	if (mm_init(&MM, 56) < 0)
		perror("mm_init");

	for (i=0; i< how; i++) { 	//how is in mm_public.h defined as 8
		chunk = mm_get(&MM, i+1);
		mm_put(&MM,chunk);
	}

	mm_release(&MM);

	j = gettimeofday (&timee, (void *)NULL);

	fprintf (stderr, "MM time took %f msec\n",comp_time (times, timee)/1000.0);
}


//****************************************************************************************************


/*

int mm_init (mm_t *MM, int tsz);		//allocate all memory, return -1 on failure
void* mm_get (mm_t *MM, int neededSize);	//get a chunch of memory (pointer to void) of size sz, NULL on failure
void mm_put (mm_t *MM, void *chunk);		//give back chunck to the memory manager, don't free it though!
void  mm_release (mm_t *MM);			//release all memory bac to the system
double comp_time (struct timeval times, struct timeval timee);

*/
