// This program converts an infix expression to a postfix expression using a stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Check precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int j = 0;

    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Operand
        if (isalnum(c)) {
            postfix[j++] = c;
        }

        // Opening bracket
        else if (c == '(') {
            push(c);
        }

        // Closing bracket
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}