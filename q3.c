// 3. Write a program that converts an infix expression to its equivalent prefix expression using
// a stack.
// The program should have the following functionality:
// (a) Read an infix expression from the user.
// (b) Convert the infix expression to its equivalent prefix expression using a stack.
// (c) Print the prefix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top];
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    initialize(&stack);
    int j = 0;

    for (int i = strlen(infix) - 1; i >= 0; i--) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')' || infix[i] == '*' || infix[i] == '/' ||
                   infix[i] == '+' || infix[i] == '-' || infix[i] == '^') {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&stack) && peek(&stack) != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); 
        }
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';  

    infixToPrefix(infix, prefix);

    printf("Equivalent prefix expression: %s\n", prefix);

    return 0;
}
