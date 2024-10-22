#include <stdio.h>

int main() {
    unsigned int m;
    int j;

    printf("Enter 32-bit number m: ");
    scanf("%u", &m);
    printf("Enter number bita j (0-31): ");
    scanf("%d", &j);


    unsigned int mask = ~(1 << j);


    unsigned int result = m & mask;

    printf("Decimal form: %u\n", result);
    printf("Hexadecimal form: 0x%X\n", result);

    return 0;
}
