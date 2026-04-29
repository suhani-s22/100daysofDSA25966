// This program implements a priority queue using an array. It supports insertion, deletion of the minimum element, and peeking at the minimum element.

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    // Shift elements
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek (show min)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            insert(x);
        } 
        else if (type == 2) {
            deleteMin();
        } 
        else if (type == 3) {
            peek();
        }
    }

    return 0;
}