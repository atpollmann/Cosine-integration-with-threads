#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/Options.h"
#include "../includes/Utils.h"

void getOptions(Options *option, int argc, char **argv) {
    int partitionsCount = 0;
    int opt;

    if(argc != 3) {
        printUsage(argv[0]);
        abort();
    }

    while((opt = getopt(argc, argv, "p:")) != -1) {
        switch(opt) {
            case 'p':
                if(!stringToPositiveInteger(optarg, &partitionsCount)
                        || (partitionsCount % PARTITION_MULTIPLE) != 0) {
                    printf("Numero de particiones invalido (%s)\n\n", optarg);
                    printUsage(argv[0]);
                    exit(EXIT_SUCCESS);
                }
                break;
            default:
                printUsage(argv[0]);
                abort();
        }
    }

    partitionsCount *= 3;
    option->partitionsCount = partitionsCount;
    option->h = (UPPER_BOUND - LOWER_BOUND) / partitionsCount;
}

void printUsage(char *binaryName) {
    printf("\nIntegra la funcion cos(x) entre 0 y 20 con el metodo de Simpson\n");
    printf("\nUso: ./%s -p <cantidad de particiones>\n", binaryName);
    printf("Donde <cantidad de particiones> es multiplo de 3.\n\nEjemplos:\n");
    printf("%s -p 3\n", binaryName);
    printf("%s -p 18\n", binaryName);
    printf("%s -p 702\n", binaryName);
}