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



/* allocate all memory, return -1 on failure
	- clairify difference between mm_t and node_data
	- malloc to include the MM with node_data
	- partition size?
	- ingeneral work on mm_t
*/
int mm_init (mm_t *MM, int tsz)
{
	node* header;
	int i;

	//make your double linked list
	for(i = 0; i < tsz; i++)
	{
		//first node
		if(i == 0)
		{
			//create node
			node* x = (node*) malloc(sizeof(node));

			//save the header, fill in other initial information
			header = x;
			x->backwards_node = NULL;
			x->free = true;
			x->node_number = i;
			x->size_available = tsz;
		}

		//all other nodes
		else
		{
			//save previous node
			node* tmp = x;

			//create node
			node* x = (node*) malloc(sizeof(node));

			//finish initial data for previous node
			tmp->forward_node = &x;

			//fill in initial information
			x->backwards_node = &tmp;
			x->free = true;
			x->node_number = i;
			x->size_available = tsz - 1;
		}

		//Set last nodes forward_node to NULL
		if(i == tsz)
			x->forward_node = NULL;

	}//end for()

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
