#include <stdio.h>

int count_set_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {

        if (n & 1) {
            count++;
        }

        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int number;


    printf("Enter 32-bit number: ");
    scanf("%u", &number);

    int result = count_set_bits(number);

    printf("Count of bit: %d\n", result);

    return 0;
}
