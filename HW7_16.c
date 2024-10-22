#include <math.h>

double f(const double *x, int d) {
    double sum = 0.0;
    for (int i = 0; i < d - 1; i++) {
        sum += 100 * pow((x[i+1] - x[i]), 2) + pow((x[i] - 1), 2);
    }
    return sum;
}
