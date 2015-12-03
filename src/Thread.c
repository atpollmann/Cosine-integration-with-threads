#include <stdio.h>
#include "../includes/Summation.h"

void *startThread(void *thread) {
    Thread *th = (Thread *) thread;
    th->summation = doSummation(th->lowerBound, th->upperBound, th->options->h);
    pthread_exit(NULL);
}

void prepareThreads(Thread *threads, Options *options) {
    int i, n = options->partitionsCount;
    for (i = 0; i < SUM_THREADS_COUNT; i++) {
        threads[i].summation = 0;
        threads[i].lowerBound = i + 1;
        threads[i].options = options;
    }

    threads[0].upperBound = n - 2;
    threads[1].upperBound = n - 1;
    threads[2].upperBound = n - 3;
}
