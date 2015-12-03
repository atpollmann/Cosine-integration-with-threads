#include <pthread.h>
#include "Options.h"

typedef struct thread{
    pthread_t id;
    int lowerBound;
    int upperBound;
    double summation;
    Options *options;
}Thread;

/**
 * Kick start the threads
 */
void *startThread(void *thread);

/**
 * Takes the thread array and for each one
 * calculates the lower and upper bounds
 */
void prepareThreads(Thread *threads, Options *options);
