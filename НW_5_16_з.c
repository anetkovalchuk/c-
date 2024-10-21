#include <stdio.h>
#include <math.h>

double calculate_series(double x, double epsilon) {
    double sum = 1.0;  
    double term = -x;
    int n = 1;

    while (fabs(term) >= epsilon) {
        sum += term;
        n++;
        term *= -x;
    }

    return sum;
}

int main() {
    double x, epsilon;

    printf("Введіть значення x: ");
    scanf("%lf", &x);
    printf("Введіть значення epsilon: ");
    scanf("%lf", &epsilon);

    double result = calculate_series(x, epsilon);

    printf("Сума ряду для y = 1/(1 + x) при epsilon = %lf: %lf\n", epsilon, result);

    return 0;
}
