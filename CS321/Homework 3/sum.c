#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;


    pthread_attr_init(&attr);
    printf("Thread Created\n");

    pthread_create(&tid, &attr, runner, argv[1]);

    printf("Parent, wait for child thread\n");
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
    printf("done\n");
}

void *runner(void *param)
{
   int i, upper = atoi(param);
   sum = 0;

   for (i =1 ; i <= upper; i++) {
      sum +=i;
   }

   printf("Terminate child thread\n");
   return(0);
}
