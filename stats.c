/*
 * stats.c
 *
 *  Created on: Feb 15, 2018
 *      Author: jl1361
 */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int avg, min, max,size = 0;	//three shared values
int *array;
void *sum(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	/*
	 * Throw error if no values are inputted
	 */
	if(argc<2)
	{
		fprintf(stderr,"No values entered, please enter values to calculate.\n");
		return -1;
	}

	array = malloc(sizeof(int)*argc);
	size = argc;
	for (int i = 1; i < size; i++)
	    {
			array[i] = atoi(argv[i]);
			printf("%d\n", array[i]);
	    }


	size-=1;
	printf("Size: %d\n", size);


	int sum, i = 0;
	for(i=0; i<size; ++i)
	{
		sum+=array[i];
	}
	avg = sum/size;
	printf("Sum: %d\n", sum);

	printf("Average: %d\n", avg);

//	//Get default attributes
//	pthread_attr_init(&attr);
//	//Create Thread
//	pthread_create(&tid, &attr, sum, argv[1]);
//	//Wait for the thread to exit
//	pthread_join(tid, NULL);
//
//
//	//Print variable to console
//	printf("The average is %d\n", avg);
//	printf("The minimum is %d\n", min);
//	printf("The maximum is %d\n", max);

}

/*
 * Thread will begin control in this runner function
 */
void *sum(void *param)
{
	int sum, i = 0;
	for(i=0; i<size; ++i)
	{
		sum+=array[i];
	}
	avg = sum/i;


	pthread_exit(0);


}

//
//void *min(void *param)
//{
//	int i, upper = atoi(param);
//	sum = 0;
//
//	if(upper>0)
//	{
//		for(i=1; i<=upper;i++)
//		{
//			sum+=i;
//		}
//		pthread_exit(0);
//	}
//
//}
//
//
//
//
//void *max(void *param)
//{
//	int i, upper = atoi(param);
//	sum = 0;
//
//	if(upper>0)
//	{
//		for(i=1; i<=upper;i++)
//		{
//			sum+=i;
//		}
//		pthread_exit(0);
//	}
//
//}



