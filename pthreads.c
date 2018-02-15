/*
 * pthreads.c
 *
 *  Created on: Feb 15, 2018
 *      Author: Jordan Long
 */


#include <pthread.h>
#include <stdio.h>
int sum;
void *runner(void *param);

//int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	/*
	 * If integer is not included when the program is run, throws error
	 * ./pthread 10
	 */
	if(argc!=2)
	{
		fprintf(stderr,"Usage: a.out <integer value>\n");
		return -1;
	}

	/*
	 * Integer value input must be positive
	 */
	if(atoi(argv[1])<0)
	{
		fprintf(stderr,"Argument %d must be non-negative\n", atoi(argv[1]));
		return -1;
	}

	//Get default attributes
	pthread_attr_init(&attr);
	//Create Thread
	pthread_create(&tid, &attr, runner, argv[1]);
	//Wait for the thread to exit
	pthread_join(tid, NULL);

	printf("sum = %d\n", sum);

}

/*
 * Thread will begin control in this runner function
 */
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	if(upper>0)
	{
		for(i=1; i<=upper;i++)
		{
			sum+=i;
		}
		pthread_exit(0);
	}






}







