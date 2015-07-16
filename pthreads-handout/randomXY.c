/**
 * Generate random number
 * Determine if the random point occurs within a circle
 *
 * Compilation:
 *	gcc -o randomXY -std=c99  randomXY.c -lm
 *	Note: Use the stdandard C99
 *		Use the -lm (load math) at the end
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>

// Prototypes
double RandomDouble();
int InsideCircle(int number_of_darts);

// Main
int main (int argc, const char * argv[]) 
{
	// Check for input argument
	if (argc == 1)
	{
		fprintf(stderr,"Usage: %s <starting value>\n", argv[0]);
		return -1;
	}

	int circle_count = 0;
	int hits = atoi(argv[1]);

	/* seed the random number generator */
	srand((unsigned)time(NULL));

	circle_count = InsideCircle(hits);


	printf("Out of %d hits, %d landed inside the circle\n", hits, circle_count);

	return 0;
}

/*
 * Generates a double precision random number
 */
double RandomDouble() 
{
	return rand() / ((double)RAND_MAX + 1);
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InsideCircle
 *  Description:  This function loops over a fixed number of iterations
 *  			Calculates a random number, and determines if this number
 *  			lands within a circle of radius 1
 *  			Returns the number of hits
 * =====================================================================================
 */
int InsideCircle(int number_of_darts)
{
	int hit_count = 0;
	double x,y,c;
	
	for (int i = 0; i < number_of_darts; i++) {
		
		/* generate random numbers between -1.0 and +1.0 (exclusive) */
		x = RandomDouble() * 2.0 - 1.0;
		y = RandomDouble() * 2.0 - 1.0;
		c = sqrt(x*x + y*y);
		
		if ( c < 1.0 )
			++hit_count;		
	}
	
	return hit_count;
}

