#include <math.h>
#include <stdio.h>
#include <float.h> // Для використання DBL_EPSILON

void task1() {
    double x;
    int n;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    double result = x;
    for (int i = 0; i < n; i++) {
        result = sin(result);
    }

    printf("Result: %lf\n", result);
}

void task2() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int result = 1;
    printf("Factorial (up): ");
    for (int i = 1; i <= n; i++) {
        result *= i;
        printf("%d", i);
        if (i < n) {
            printf("*");
        }
    }
    printf(" = %d\n", result);

    int result2 = 1;
    printf("Factorial (down): ");
    for (int i = n; i >= 1; i--) {
        result2 *= i;
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }
    printf(" = %d\n", result2);
}

void task3_a() {
    int x, n;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    double result = 0;
    printf("Polynomial (a): ");
    for (int i = 0; i <= n; i++) {
        result += pow(x, i);
        printf("x^%d", i);
        if (i < n) {
            printf(" + ");
        }
    }
    printf(" = %lf\n", result);
}

void task3_b() {
    int x, y, n;
    printf("Enter x, y, n: ");
    scanf("%d %d %d", &x, &y, &n);

    double result = 0;
    printf("Polynomial (b): ");
    for (int i = 0; i <= n; i++) {
        result += pow(x, 2 * n - i) * pow(y, n - i);
        printf("x^%d * y^%d", 2 * n - i, n - i);
        if (i < n) {
            printf(" + ");
        }
    }
    printf(" = %lf\n", result);
}

void task4() {
    int x, n;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    double result = 0;
    printf("Expression: ");
    for (int i = 1; i <= n; i++) {
        result += i * pow(x, i);
        printf("%d*x^%d", i, i);
        if (i < n) {
            printf(" + ");
        }
    }
    printf(" = %lf\n", result);
}

void task5() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int result = 1;

    if (n % 2 != 0) {
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
    } else {
        for (int i = 2; i <= n; i += 2) {
            result *= i;
        }
    }

    printf("n!! = %d\n", result);
}

void task6a() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double result = 0.0;

    for (int i = 0; i < n; i++) {
        result = sqrt(2 + result);
    }

    printf("Result = %.6f\n", result);
}

void task6b() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double result = 0.0;

    for (int i = 1; i < n; i++) {
        result = sqrt(3 * i + result);
    }

    printf("Result = %.6f\n", result);
}

void task7() {
    int n;
    double x, y = 1.0;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    int factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        y += (pow(x, i) / factorial);
    }

    printf("y = %.6f\n", y);
}

void task8() {
    int m, k = 0;
    printf("Enter m: ");
    scanf("%d", &m);

    while (pow(4, k + 1) <= m) {
        k++;
    }

    printf("The largest k such that 4^k <= %d is: %d\n", m, k);
}

void task9() {
    int n, r = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    while (pow(2, r) <= n) {
        r++;
    }

    printf("The smallest r such that 2^r >= %d is: %d\n", n, r);
    printf("2^r = %d\n", (int)pow(2, r));
}

void task10() {
    float a = 1.0f;

    while (1.0f + a != 1.0f) {
        a /= 2.0f;
    }

    printf("The machine epsilon for float is: %.50f\n", a);
}

void task11() {
    int count = 0, i = 0;
    double sum = 0, product = 1, num;

    do {
        printf("a[%d] = ", i++);
        scanf("%lf", &num);

        if (num > DBL_EPSILON) {
            sum += num;
            product *= num;
            count++;
        }
    } while (fabs(num) > DBL_EPSILON);

    double average = sum / count;
    double geometric_mean = pow(product, 1.0 / count);

    printf("Sum: %.2lf\n", sum);
    printf("Arithmetic average: %.2lf\n", average);
    printf("Geometric mean: %.2lf\n", geometric_mean);
}

void task12() {
    unsigned int n;
    double subfact = 1;

    printf("Enter n (n < 25): ");
    scanf("%u", &n);

    for (unsigned int i = 1; i <= n; i++) {
        subfact = subfact * i + pow(-1, i);
    }

    printf("!%u = %.0f\n", n, subfact);
}

int main() {
    // task1();
    // task2();
    // task3_a();
    // task3_b();
    task4();
    task5();
    task6a();
    task6b();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();

    return 0;
}
