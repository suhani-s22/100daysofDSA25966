// This program demonstrates how to reverse a queue using a stack in C.

#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = n - 1, top = -1;

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Step 1: Enqueue → Stack (push)
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Step 2: Stack → Queue (pop)
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    // Output reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}