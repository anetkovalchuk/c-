#include <stdio.h>
#include <math.h>


double calculate_u(int i, double *u, double *v) {
    return (u[i-1] - u[i-2] * v[i-1] * v[i-2]) / (1 + u[i-2] * u[i-2] + v[i-1] * v[i-1]);
}


double calculate_v(int i, double *u, double *v) {
    return (u[i-1] - v[i-1]) / (fabs(u[i-2] + v[i-1]) + 2);
}

int main() {
    int n;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    double u[n+1], v[n+1];

    u[0] = u[1] = 0;
    v[0] = v[1] = 1;

    for (int i = 2; i <= n; i++) {
        u[i] = calculate_u(i, u, v);
        v[i] = calculate_v(i, u, v);
    }

    printf("Значення v[%d] = %lf\n", n, v[n]);

    return 0;
}
