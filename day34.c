// This program evaluates a postfix expression using a stack implemented with a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack node
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) return 0;

    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {

        // Skip spaces
        if (exp[i] == ' ') continue;

        // If digit
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; // adjust index

            push(&stack, num);
        }

        // Operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            switch (exp[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(&stack, res);
        }
    }

    return pop(&stack);
}

int main() {
    char exp[100];

    // Read full line input
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d", result);

    return 0;
}