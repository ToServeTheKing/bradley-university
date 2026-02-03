#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* the list of integers */
int *list;

/* the threads will set these values */
double average;
int maximum;
int minimum;

void *calculate_average(void *param);
void *calculate_maximum(void *param);
void *calculate_minimum(void *param);

int main(int argc, char *argv[])
{
	int i;
	int num_of_args = argc-1;
	pthread_t tid_1;
    pthread_t tid_2;
    pthread_t tid_3;

    /* allocate memory to hold array of integers */
    list = malloc(sizeof(int)*num_of_args);

	for (i = 0; i < num_of_args; i++)
		list[i] = atoi(argv[i+1]);	

	/* create the threads */
    //-------------[TO BE COMPLETED]-------------
    pthread_create(&tid_1, NULL, calculate_average, NULL);
    pthread_create(&tid_2, NULL, calculate_maximum, NULL);
    pthread_create(&tid_3, NULL, calculate_minimum, NULL);

	/* wait for the threads to exit */
    //-------------[TO BE COMPLETED]-------------
    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);
    pthread_join(tid_3, NULL);

	printf("The average is %f\n", average);
	printf("The maximum is %d\n", maximum);
	printf("The minimum is %d\n", minimum);

	return 0;
}

void *calculate_average(void *param)
{
    //-------------[TO BE COMPLETED]-------------
    double sum = 0.0;
    int num_of_args = argc - 1;

    for (int i = 0; i < num_of_args; i++)
    {
        sum += list[i];
    }

    average = sum / num_of_args;
    pthread_exit(0);
}

void *calculate_maximum(void *param)
{
    //-------------[TO BE COMPLETED]-------------
    int num_of_args = argc - 1;
    maximum = list[0];

    for (int i = 1; i < num_of_args; i++)
    {
        if (list[i] > maximum)
        {
            maximum = list[i];
        }
    }

    pthread_exit(0);
}

void *calculate_minimum(void *param)
{
    //-------------[TO BE COMPLETED]-------------
    int num_of_args = argc - 1;
    minimum = list[0];

    for (int i = 1; i < num_of_args; i++)
    {
        if (list[i] < minimum)
        {
            minimum = list[i];
        }
    }

    pthread_exit(0);
}
