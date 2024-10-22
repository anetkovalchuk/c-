#include <stdio.h>
#include <math.h>


int is_even_perfect_cube(int num) {
    int cube_root = round(cbrt(num));
    if (cube_root * cube_root * cube_root == num && num % 2 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int N;


    printf("Enter size of N: ");
    scanf("%d", &N);

    int arr[N];
    int count = 0;

    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);

        if (is_even_perfect_cube(arr[i])) {
            count++;
        }
    }

    printf("Number of even full cubes in the array: %d\n", count);

    return 0;
}
