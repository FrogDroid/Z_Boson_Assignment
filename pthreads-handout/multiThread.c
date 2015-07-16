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

// Global Variables
int circle_count = 0;		/* the number of hits in the circle */
int verbosity = 0; 			/* print trace if set */
// Main program
int main (int argc, char * argv[]) 
{
	double estimated_pi = 0;
	/* Get Options */
    printUsage(argv);

    /* Make sure that all required command line args were specified */

	/* Allocate memory for array of workers */

	/*  Initialze mutex lock */

	/* seed the random number generator */
	srand((unsigned)time(NULL));
	
	/* Create threads */
	
	
	/* Join threads */

	/* Parent estimates Pi */

	printf("Pi = %f\n",estimated_pi);

	return 0;
}

/*
 * printUsage - Print usage info
 */
void printUsage(char* argv[])
{
    printf("Usage: %s [-hv] -v <num> -t <num>\n", argv[0]);
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

