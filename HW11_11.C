#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned key;
    char data[10];
} TPair;

int compare(const void* a, const void* b) {
    return ((TPair*)a)->key - ((TPair*)b)->key;
}

int binary_search(TPair arr[], int size, unsigned key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].key == key) {
            return mid;
        } else if (arr[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int search_in_ordered_file(TPair arr[], int size, unsigned key) {
    return binary_search(arr, size, key);
}

void delete_from_ordered_file(TPair arr[], int* size, unsigned key) {
    int index = binary_search(arr, *size, key);
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
}

int search_in_unordered_file(TPair arr[], int size, unsigned key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].key == key) {
            return i;
        }
    }
    return -1;
}

void delete_from_unordered_file(TPair arr[], int* size, unsigned key) {
    int index = search_in_unordered_file(arr, *size, key);
    if (index != -1) {
        arr[index] = arr[*size - 1];
        (*size)--;
    }
}

int main() {
    TPair arr[] = {
        {3, "Data3"},
        {1, "Data1"},
        {2, "Data2"}
    };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Упорядоченный файл
    qsort(arr, size, sizeof(TPair), compare);
    printf("Ordered File:\n");
    for (int i = 0; i < size; i++) {
        printf("Key: %u, Data: %s\n", arr[i].key, arr[i].data);
    }

    unsigned key_to_search = 2;
    int index = search_in_ordered_file(arr, size, key_to_search);
    if (index != -1) {
        printf("Found key %u at index %d in ordered file.\n", key_to_search, index);
    } else {
        printf("Key %u not found in ordered file.\n", key_to_search);
    }

    delete_from_ordered_file(arr, &size, key_to_search);
    printf("Ordered File after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("Key: %u, Data: %s\n", arr[i].key, arr[i].data);
    }

    // Неупорядоченный файл
    TPair unordered_arr[] = {
        {3, "Data3"},
        {1, "Data1"},
        {2, "Data2"}
    };
    int unordered_size = sizeof(unordered_arr) / sizeof(unordered_arr[0]);

    printf("Unordered File:\n");
    for (int i = 0; i < unordered_size; i++) {
        printf("Key: %u, Data: %s\n", unordered_arr[i].key, unordered_arr[i].data);
    }

    index = search_in_unordered_file(unordered_arr, unordered_size, key_to_search);
    if (index != -1) {
        printf("Found key %u at index %d in unordered file.\n", key_to_search, index);
    } else {
        printf("Key %u not found in unordered file.\n", key_to_search);
    }

    delete_from_unordered_file(unordered_arr, &unordered_size, key_to_search);
    printf("Unordered File after deletion:\n");
    for (int i = 0; i < unordered_size; i++) {
        printf("Key: %u, Data: %s\n", unordered_arr[i].key, unordered_arr[i].data);
    }

    return 0;
}
