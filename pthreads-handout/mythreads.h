#ifndef __MYTHREADS_h__
#define __MYTHREADS_h__

#include <pthread.h>

void Pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *restrict attr);
void Pthread_mutex_lock(pthread_mutex_t *m);
void Pthread_mutex_unlock(pthread_mutex_t *m);
void Pthread_create(pthread_t *thread, const pthread_attr_t *attr, 	
	       void *(*start_routine)(void*), void *arg);
void Pthread_join(pthread_t thread, void **value_ptr);

#endif // __MYTHREADS_h__
