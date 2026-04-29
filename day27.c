// This program finds the intersection point of two linked lists, if it exists.

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

// Get intersection node
struct Node* getIntersection(struct Node* headA, struct Node* headB) {
    struct Node *p1 = headA, *p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1; // either intersection or NULL
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // ⚠️ NOTE:
    // This input DOES NOT create real intersection automatically.
    // So result will be "No Intersection" unless nodes are manually linked.

    struct Node* inter = getIntersection(list1, list2);

    if (inter == NULL)
        printf("No Intersection");
    else
        printf("%d", inter->data);

    return 0;
}