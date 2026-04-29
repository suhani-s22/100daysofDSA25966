// This program reads an array of integers from the user and finds the maximum and minimum values in the array.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = a[0];
    int min = a[0];

    // Find max and min
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}