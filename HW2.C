#include <math.h>
#include <stdio.h>
#include <stdint.h>
void task1() {
    double r, R, V;

    printf("Enter r and R: ");
    scanf("%lf %lf", &r, &R);
    V = 2 * M_PI * M_PI * R * r * r;
    printf("V = %.2f\n", V);

}

void task2() {
    double x , sigmoid_x, sigmoid_derivative_x ;

    x = 1.0;
    sigmoid_x = 1 / (1 + exp(-x));
    sigmoid_derivative_x = sigmoid_x * (1 - sigmoid_x);


    printf("sigmoid(x) = %f\n", sigmoid_x);
    printf("sigmoid_derivative(x) = %f\n", sigmoid_derivative_x);

}
int main() {
    task1();
    task2();

    return 0;
}