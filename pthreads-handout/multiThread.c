#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <getopt.h>
#include "mythreads.h"
// Prototypes
void printUsage(char* argv[]);
// .. others 
void * throwDarts(void * lock);
double RandomDouble();
double estimatePi();

// Global Variables
int circle_count = 0;		/* the number of hits in the circle */
int isVerbose = 0; 			/* print trace if set */
int threadCount = 0;	//number of threads to run
int dartCount = 0;	//the number of darts to run.
int dartsThrown = 0; //the counter for how many darts have been thrown
// Main program
int main (int argc, char * argv[]) 
{
	double estimated_pi = 0;
	/* Get Options */

    /* Make sure that all required command line args were specified */
	int hasDarts = 0;
        int  hasThreads = 0;
        int c = 0;
         while (optind < argc)
        {
         	if ((c = getopt(argc, argv, "d:t:v")) != -1)
		{
                	switch (c)
               		{
                        	case 'v':
                                isVerbose = 1;
                                break;
                        	case 'd':
                                dartCount  = atoi(optarg);
                                hasDarts = 1;
                                break;
                        	case 't':
                                threadCount   = atoi(optarg);
                                hasThreads = 1;
                                break;
                        	default:
                                printUsage(argv);
                	}
		}
		else
		{
			//move along.
			optind++;
		}
        }

        if(!(hasDarts && hasThreads)){
                printUsage(argv);
        }

	/* Allocate memory for array of workers */
	pthread_t * workers = malloc(sizeof(pthread_t) * threadCount); 

	/*  Initialze mutex lock */
	pthread_mutex_t * lock = malloc(sizeof(pthread_mutex_t));
	Pthread_mutex_init(lock, NULL); 

	/* seed the random number generator */
	srand((unsigned)time(NULL));
	
	/* Create threads */
	for(int w = 0; w < threadCount; w++)
	{
		if(isVerbose){
			printf("creating thread %d \n", w);
		}
		Pthread_create(&workers[w], NULL, throwDarts, lock );	
	}	
	
	/* Join threads */
	for(int j = 0; j < threadCount; j++)
	{
		Pthread_join((pthread_t) workers[j], NULL);
	}

	if(isVerbose){

		printf("All threads complete.\n");
		printf("Total darts Thrown: %d \n", dartsThrown);
		printf("Total hits: %d \n", circle_count);
	}
	/* Parent estimates Pi */
	estimated_pi = estimatePi();

	printf("Pi = %f\n",estimated_pi);

	return 0;
}

void * throwDarts(void * lock)
{
	double x,y,c;
	//generate the random point
	while(dartsThrown < dartCount){
	
		x = RandomDouble() * 2.0 - 1.0;
		y = RandomDouble() * 2.0 - 1.0;
		c = sqrt(x*x + y*y);
		// if the point was within the circle,
		if(c < 1.0){
			//!LOCK
			Pthread_mutex_lock(lock);
			// increment the hits counter
			circle_count++;
			//!UNLOCK
			Pthread_mutex_unlock(lock);
		}
		//!LOCK
		Pthread_mutex_lock(lock);
		// increment the darts thrown counter
		dartsThrown++;
		//!UNLOCK
		Pthread_mutex_unlock(lock);
	}
	return NULL;
}

/*
 * printUsage - Print usage info
 */
void printUsage(char* argv[])
{
    printf("Usage: %s [-hv] -d <num> -t <num>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -t <num>   Number of threads.\n");
    printf("  -d <num>   Number of darts.\n");
    printf("\nExamples:\n");
    printf("  linux>  %s -t 1 -d 5000\n", argv[0]);
    printf("  linux>  %s -v -t 1 -d 5000\n", argv[0]);
    exit(0);
}

double RandomDouble() 
{
	return rand() / ((double)RAND_MAX + 1);
}

double estimatePi()
{
	double pi = 0.0;
	pi = (4.0 * (double) circle_count) / (double) dartsThrown;
	return pi;
}
