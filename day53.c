// This program builds a binary tree from a level order input and prints its vertical order traversal.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node with horizontal distance
struct QNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[MAX];
    int front = 0, rear = 0;

    // For storing results
    int result[MAX][MAX];
    int count[MAX] = {0};

    int offset = MAX / 2;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode curr = queue[front++];
        int hd = curr.hd + offset;

        result[hd][count[hd]++] = curr.node->data;

        if (curr.node->left)
            queue[rear++] = (struct QNode){curr.node->left, curr.hd - 1};

        if (curr.node->right)
            queue[rear++] = (struct QNode){curr.node->right, curr.hd + 1};
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}