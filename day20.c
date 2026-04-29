// This program counts the number of subarrays in an array that sum to zero.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;

    // Brute force approach (easy to understand)
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == 0) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}