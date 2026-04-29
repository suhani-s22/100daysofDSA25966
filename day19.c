// This program finds two elements in an array whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort array
    qsort(a, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = 1000000;
    int x = 0, y = 0;

    // Two-pointer approach
    while (left < right) {
        int sum = a[left] + a[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = a[left];
            y = a[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}