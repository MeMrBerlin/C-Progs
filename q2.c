// 2. Write a C program where a string of parenthesis has been given as input from the user and
// determine whether the given string is balanced or not using stack.
// Input: exp = “[()][()()]()”
// Output: Balanced
// Input: exp = “[(])”
// Output: Not Balanced

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

bool isBalanced(char exp[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty(&stack)) {
                return false;
            }

            char popped = pop(&stack);
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == ']' && popped != '[') ||
                (exp[i] == '}' && popped != '{')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';  

    if (isBalanced(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
