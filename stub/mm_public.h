#include <sys/time.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INTERVAL 0
#define INTERVAL_USEC 800000
#define SZ 64
#define how 8

typedef struct{
	struct node*	forward_node;
	struct node*	backwards_node;
	void*	node_data;			//mm_t in our case
	bool	free;
	int	node_number;
	int	size_available;
} node;

typedef struct {
	node* header;
	int tsz;
	int partitions;
	int number_of_free_nodes;
	int largest_free_partition; 
} mm_t;

int mm_init (mm_t *MM, int tsz);		//allocate all memory, return -1 on failure
void* mm_get (mm_t *MM, int neededSize);	//get a chunch of memory (pointer to void) of size sz, NULL on failure
void mm_put (mm_t *MM, void *chunk);		//give back chunck to the memory manager, don't free it though!
void  mm_release (mm_t *MM);			//release all memory bac to the system
double comp_time (struct timeval times, struct timeval timee);
