// This program rotates a linked list to the right by k places.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: find length
    int n = 1;
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    // Step 2: optimize k
    k = k % n;
    int steps = n - k;

    // Step 3: find new tail
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 4: break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}