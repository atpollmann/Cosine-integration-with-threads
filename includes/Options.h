#define PARTITION_MULTIPLE 3
#define LOWER_BOUND 0.0
#define UPPER_BOUND 20.0
#define SUM_THREADS_COUNT 3
#define STEP 3

typedef struct options{
    int partitionsCount;
    double h;
}Options;

/**
 * Returns the user option using getopt
 */
void getOptions(Options *opt, int argc, char **argv);
void printUsage(char *binaryName);