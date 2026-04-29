// This program implements a queue using an array and supports enqueue, dequeue (with rotation), and display operations.

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue
void enqueue(int value) {
    if (size == MAX) return;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

// Dequeue + rotate
void dequeue() {
    if (size == 0) return;

    int val = queue[front];
    front = (front + 1) % MAX;

    // push it back (rotation)
    enqueue(val);
}

// Display
void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // Perform m rotations
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}