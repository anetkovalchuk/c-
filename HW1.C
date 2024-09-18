#include <math.h>
#include <stdio.h>
#include <stdint.h>
int main() {
    float a, S, t, V, tv;
    printf("Enter a, t, V: ");
    scanf("%f %f %f", &a, &t, &V);
    S = (a * t * t) / 2;
    tv = V / a;
    printf("S = %.2f\n, tv = %.2f\n", S, tv);

    return 0;
}