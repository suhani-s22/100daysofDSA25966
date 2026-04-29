// This program implements a double-ended queue (deque) using a circular array. It supports operations to push and pop elements from both the front and back of the deque, as well as checking if the deque is empty or full, and getting the front and rear elements.

#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Push front
void push_front(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) return;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Pop back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// Front element
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// Rear element
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// Size
void getSize() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }
    int size = (rear - front + MAX) % MAX + 1;
    printf("%d\n", size);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x; scanf("%d", &x);
            push_front(x);
        }
        else if (type == 2) {
            int x; scanf("%d", &x);
            push_back(x);
        }
        else if (type == 3) {
            pop_front();
        }
        else if (type == 4) {
            pop_back();
        }
        else if (type == 5) {
            getFront();
        }
        else if (type == 6) {
            getBack();
        }
        else if (type == 7) {
            printf("%d\n", isEmpty());
        }
        else if (type == 8) {
            getSize();
        }
    }

    return 0;
}