#include <stdio.h>
#include <stdlib.h>
#include "../includes/Summation.h"

int main(int argc, char** argv) {
    Options options;
    getOptions(&options, argc, argv);

    Thread threads[SUM_THREADS_COUNT];

    // Set to create threads as joinable
    pthread_attr_t threadsAttr;
    pthread_attr_init(&threadsAttr);
    pthread_attr_setdetachstate(&threadsAttr, PTHREAD_CREATE_JOINABLE);

    prepareThreads(threads, &options);

    int i, t;
    void *status;
    for(i = 0; i < SUM_THREADS_COUNT; i++) {
        t = pthread_create(&threads[i].id, &threadsAttr, startThread, (void *)&threads[i]);
        if(t) {
            printf("Error al crear hebra\n");
            exit(EXIT_FAILURE);
        }
    }
     // Free the attribute and wait for workers
    pthread_attr_destroy(&threadsAttr);
    for(i = 0; i < SUM_THREADS_COUNT; i++) {
        t = pthread_join(threads[i].id, &status);
        if(t) {
            printf("Error al unir hebras\n");
            exit(EXIT_FAILURE);
        }
    }

    // Collect the results
    printf("Funcion a integrar: cos(x)\n");
    printf("Limite inferior: %lf\n", LOWER_BOUND);
    printf("Limite superior: %lf\n", UPPER_BOUND);
    printf("Particiones 3*(n = %d): %d\n", options.partitionsCount/3, options.partitionsCount);
    printf("h:  %lf\n", options.h);
    printf("Resultado: %lf\n", simpson(threads));

    pthread_exit(NULL);
}

