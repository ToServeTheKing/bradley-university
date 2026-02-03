//CS 321:  Skeleton code for multithreaded sorting program 
//Feel free to modify the code as you wish. 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE				10
#define NUMBER_OF_THREADS	3

void *sorter(void *params);	/* thread that performs basic sorting algorithm */
void *merger(void *params);	/* thread that performs merging of results */

int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};

int result[SIZE];

typedef struct
{
	int from_index;
	int to_index;
} parameters;

int main (int argc, const char * argv[]) 
{
	int i;
    
	pthread_t workers[NUMBER_OF_THREADS];
	
	/* establish the first sorting thread */
	parameters *data = (parameters *) malloc (sizeof(parameters));
	data->from_index = 0;
	data->to_index = (SIZE/2) - 1;
	pthread_create(&workers[0], 0, sorter, data);
	
	/* establish the second sorting thread */
    //-------------[TO BE COMPLETED]-------------

	
	/* now wait for the 2 sorting threads to finish */
    //-------------[TO BE COMPLETED]-------------
	

	/* establish the merge thread */
    //-------------[TO BE COMPLETED]-------------
	

	/* wait for the merge thread to finish */
    //-------------[TO BE COMPLETED]-------------

	/* output the sorted array */
	for (i = 0; i < SIZE; i++)
		printf("%d  ",result[i]);
	printf("\n");
	
    return 0;
}

/**
 * Sorting thread.
 *
 * This thread can essentially use any algorithm for sorting
 */

void *sorter(void *params)
{
	int i;
	parameters* p = (parameters *)params;
	
	int begin = p->from_index;
	int end = p->to_index;
	
    //-------------[TO BE COMPLETED]-------------

	pthread_exit(0);
}



/**
 * Merge thread
 *
 * Uses simple merge sort for merging two sublists
 */

void *merger(void *params)
{
	parameters* p = (parameters *)params;
	
	int i,j;
	
	i = p->from_index;
	j = p->to_index;
	
	int position = 0;	/* position being inserted into result list */
	
	while (i < p->to_index && j < SIZE) {
		if (list[i] <= list[j]) {
			result[position++] = list[i];
			i++;
		}
		else {
			result[position++] = list[j];
			j++;
		}
	}
		
	/* copy the remainder */
	if (i < p->to_index) {
		while (i < p->to_index) {
			result[position] = list[i];
			position++;
			i++;
		}
	}
	else {
		while (j < SIZE) {
			result[position] = list[j];
			position++;
			j++;
		}
	}

		
	
	pthread_exit(0);
}

