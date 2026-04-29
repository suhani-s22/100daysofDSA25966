// This program checks if a given array represents a Min-Heap.

#include <stdio.h>

// Check Min-Heap property using array (level-order)
int isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return 0;

        if (right < n && arr[i] > arr[right])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}