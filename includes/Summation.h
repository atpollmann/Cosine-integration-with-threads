#include "Thread.h"

/**
 * For each from lower to upper bound calculates
 * the summation of the result given by a call to
 * fn with the argument
 *
 * @return  Summation
 */
double doSummation(int lowerBound, int upperBound, double h);

/**
 * Implements the function to be integrated
 *
 * @return  Function result
 */
double fn(double argument);

/**
 * Collects the summations from the threads
 * and calculates the final result
 */
double simpson(Thread *threads);