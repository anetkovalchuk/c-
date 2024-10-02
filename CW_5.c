#include <stdio.h>

int find_max_fib_index(int a) {
    int f1 = 0, f2 = 1, f_next = 0;
    int index = 1;
        while (f_next <= a) {
        f_next = f1 + f2;
        f1 = f2;
        f2 = f_next;
        index++;
    }

    return index - 2;  }

double calculate_x2n(int n) {
    double result = 0.5;
    for (int i = 2 * n; i > 0; i--) {
        result = 1.0 / (2 + result);
        result = 1.0 + result;
    }

    return result;
}

void task2_b() {
    int a;
    printf(" Enter a: ");
    scanf("%d", &a);

    int result = find_max_fib_index(a);
    printf("Number : %d\n", result);

}

void task6_B() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double result = calculate_x2n(n);
    printf(" x_{2n} for n = %d: %.10lf\n", n, result);
}
int main() {
    task2_b();
    task6_B();
    return 0;
}
