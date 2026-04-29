// This program implements a stack using an array and supports push, pop, and display operations.

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if (top == MAX - 1) return; // overflow ignore
    stack[++top] = val;
}

// Pop
void pop() {
    if (top == -1) return; // underflow ignore
    top--;
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}