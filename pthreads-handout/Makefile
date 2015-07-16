# Student makefile for Cache Lab
# Change the USER/TEAM to your First_Last 
USER = Waldo_Weber
VERSION = 1
# Change your icarus server user, ex: hv12345 
ICAUSER =  NOBODY
DEST = "$(ICAUSER)@icarus.cs.weber.edu:/home/hvalle/submit/cs3100/"
#
# Student makefile for Threads
# 
CC = gcc
CFLAGS = -Wall -Werror -std=c99 
# Compiler Flags:
# 		-g			-- Enables debugig
# 		-Wall		-- Turns on all the warnings
# 		-Werror		-- All warnings are errors
# 		-std=c99	-- Use C99 standard
# 		-Wno-pointer-to-int-cast --To suppress warning	
# 									on 32bit systems

all: random multiThread
	# Generate a handin tar file each time you compile
	-tar -cvf $(USER)-hw5-$(VERSION).tar  mythreads.c mythreads.h randomXY.c multiThread.c Makefile

random: randomXY.c
	# Load math library:  -lm
	$(CC) $(CFLAGS) -o randomXY randomXY.c -lm

multiThread: multiThread.c mythreads.c
	# Load Threads library:  -lpthread
	# Load math library:  -lm
	$(CC) $(CFLAGS) -o multiThread multiThread.c mythreads.c -lpthread  -lm

# info
handin:
	scp $(USER)-hw5-$(VERSION).tar $(DEST)
#
# Clean the src dirctory
#
clean:
	rm -f randomXY multiThread
