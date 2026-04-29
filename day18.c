// This program reads an array of integers from the user and finds the maximum and minimum values in the array.
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int a[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    // Handle k > n
    k = k % n;

    int temp[100];

    // Copy last k elements to beginning
    for (int i = 0; i < k; i++) {
        temp[i] = a[n - k + i];
    }

    // Copy remaining elements
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = a[i];
    }

    // Print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}