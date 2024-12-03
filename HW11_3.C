#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int number) {
    int reversed = 0, original = number, digit;

    while (number > 0) {
        digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    return original == reversed;
}

int main() {
    FILE *fileF, *fileG;
    int number;

    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        printf("Error opening file F.\n");
        return 1;
    }

    printf("Enter integers (0 to stop):\n");
    while (1) {
        scanf("%d", &number);
        if (number == 0) break;
        fprintf(fileF, "%d\n", number);
    }
    fclose(fileF);

    fileF = fopen("F.txt", "r");
    fileG = fopen("G.txt", "w");
    if (fileF == NULL || fileG == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fscanf(fileF, "%d", &number) != EOF) {
        if (isPalindrome(number)) {
            fprintf(fileG, "%d\n", number);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("File G with palindromes has been created.\n");
    return 0;
}
