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



task2
#include <math.h>
#include <stdio.h>
#include <stdint.h>
int main() {
    int a, b, c, d, e;
    float a1, b1, c1, d1, e1;
    //y[5] = {3.0, 1.0, 5.0, 4.0, 2.1};
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    a1 = 3.0;
    b1 = 1.0;
    c1 = 5.0;
    d1 = 4.0;
    e1 = 2.1;


    printf("x  |   %d   |   %d   |   %d   |   %d   |   %d   |\n", a, b, c, d, e);
    printf("---|-------|-------|-------|-------|-------|\n");
    printf("y  |  %.1f  |  %.1f  |  %.1f  |  %.1f  |  %.1f  |\n", a1, b1, c1, d1 , e1);

    return 0;
}
