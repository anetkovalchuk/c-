#include <stdio.h>
#include <math.h>

double calculateC(double x, int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result += pow(x, i * i);
    }
    return result;
}

void task12_B() {
    double x;
    int n;
    printf("Enter x, n: ");
    scanf("%lf %d", &x, &n);

    double resultC = calculateC(x, n);
    printf("Result: %.2lf\n", resultC);
}

void task23_B() {
    int n, i;
    double z_sum = 0.0;
    printf("Enter count of n: ");
    scanf("%d", &n);

    double y[n];
    printf("Enter %d real numbers (y1, y2, ..., yn):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < n; i++) {
        double z_i;
        if (y[i] < 10) {
            z_i = y[i];
        } else {
            z_i = 1;
        }
        z_sum += z_i;
    }

    printf("Sum z1 + z2 + ... + zn = %.2lf\n", z_sum);
}
int main() {
   task12_B();
    task23_B();
    return 0;
}
