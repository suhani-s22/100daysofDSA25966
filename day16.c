//Problem: Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    int visited[100] = {0};  // To mark counted elements

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Count frequency
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;  // Mark as counted
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}