// ------------------
// Infix to Postfix Conversion using Stack
// ------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

// Push a character onto the stack
void push(char x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Heap is full\n");
        return;
    }
    p->data = x;
    p->next = top;
    top = p;
}

// Pop a character from the stack
char pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node *t = top;
    char x = t->data;
    top = top->next;
    free(t);
    return x;
}

// Display the stack contents (for debugging)
void Display() {
    Node *p = top;
    while (p != NULL) {
        printf("%c -> ", p->data);
        p = p->next;
    }
    printf("None\n");
}

// Return precedence of operators
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Check if character is an operand
int isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

// Convert infix expression to postfix
char* InfixToPostfix(char* infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 2) * sizeof(char)); // +2 for '\0' and safety

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (top != NULL && precedence(infix[i]) <= precedence(top->data)) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (top != NULL && top->data != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

// ------------------
// Main Function
// ------------------

int main() {
    char infix[] = "a+b*c-d/e";
    push('#');  // Sentinel to mark bottom of stack

    char *postfix = InfixToPostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    free(postfix);  // Clean up heap memory
    return 0;
}