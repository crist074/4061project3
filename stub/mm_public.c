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

//******************************************************************************************

/* allocate all memory, return -1 on failure
	- find out where it can fail and return -1
	- what does it return on success?
*/
int mm_init (mm_t* MM, int tsz)
{
	//node* headerNode;
	int i;

	//MM->header = headerNode;
	MM->tsz = tsz;
	MM->partitions = tsz;
	MM->number_of_free_nodes = tsz;
	MM->largest_free_partition = tsz;

	//make your double linked list
	for(i = 0; i < tsz; i++)
	{
		//first node
		if(i == 0)
		{
			//create node
			node* newNode = (node*) malloc(sizeof(node));

			//save the header, fill in other initial information
			MM->header = newNode;
			newNode->backwards_node = NULL;
			newNode->free = true;
			newNode->node_number = i;
			newNode->size_available = tsz;
		}

		//all other nodes
		else
		{
			//save previous node
			node* previousNode = newNode;

			//create node
			node* newNode = (node*) malloc(sizeof(node));

			//finish initial data for previous node
			previousNode->forward_node = &newNode;

			//fill in initial information
			newNode->backwards_node = &previousNode;
			newNode->free = true;
			newNode->node_number = i;
			newNode->size_available = tsz - i;
		}

		//Set last nodes forward_node to NULL
		if(i == tsz - 1)
			newNode->forward_node = NULL;

	}//end for()

}//end mm_init()

//******************************************************************************************

//get a chunch of memory (pointer to void) of size sz, NULL on failure
void* mm_get (mm_t *MM, int neededSize)
{
	//check if we have a large enough free space for new partition
	if(MM->largest_free_partition < neededSize)
	{
		return NULL;
	}




}//end mm_get()

//******************************************************************************************

//give back chunck to the memory manager, don't free it though!
void mm_put (mm_t *MM, void *chunk)
{

}//end mm_get()

//******************************************************************************************

//release all memory bac to the system
void mm_release (mm_t *MM)
{
	
}//end mm_release()
