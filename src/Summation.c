#include <math.h>
#include "../includes/Summation.h"

double doSummation(int lowerBound, int upperBound, double h) {
    int i;
    double summation = 0;

    for (i = lowerBound; i <= upperBound; i = i+STEP) {
        double xi = (h * i) + LOWER_BOUND;
        summation += fn(xi);
    }

    return summation;
}

double fn(double x) {
    return cos(x);
}

double simpson(Thread *threads) {
    double summation = 0;
    double h = threads->options->h;

    summation += 3 * threads[0].summation;
    summation += 3 * threads[1].summation;
    summation += 2 * threads[2].summation;

    summation += fn(LOWER_BOUND);
    summation += fn(UPPER_BOUND);

    return 3.0 * h * summation / 8.0;
}
