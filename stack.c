// ------------------
//	Stack using array
//-------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int size;
    int top;
    int *s;
} Stack;

int push(Stack *st, int x)
{
	if(st->top == (st->size-1))
	{
		printf("Stack overflow\n");
		return 0;
	}

	st->top++;
	st->s[st->top] = x;
	return 1;
}

int pop(Stack *st)
{
	if(st->top==-1)
	{
		printf("Stack underflow\n");
		return -1;
	}

	int x = st->s[st->top];
	st->top--;
	return x;
}

int peekFromTop(Stack st, int pos)
{
	int x = -1;
	int index = st.top - pos + 1;

	if(index < 0 || index > st.size-1)
	{
		printf("peekFromTop : Invalid position\n");
		return x;
	}
	else
		x = st.s[index];

	return x;
}

int StackTop(Stack st)
{
	if(st.top == -1)
		return -1;
	return st.s[st.top];
}

int isEmpty(Stack st)
{
	if (st.top == -1)
	{
		printf("isEmpty : Stack is empty\n");
		printf("----------------- \n");
		return 1;
	}
	printf("isEmpty : Stack is not empty\n");
	printf("----------------- \n");
	return 0;
}

int isFull(Stack st)
{
	if (st.top == st.size-1)
	{
		printf("isFull : Stack is Full\n");
		printf("----------------- \n");
		return 1;
	}
	printf("isFull : Stack is not Full\n");
	printf("----------------- \n");
	return 0;
}

void display_peek(Stack st)
{
	printf("display_peek : Displaying stack with peek\n");
	printf("----------------- \n");
	int index = 0;

	for(int pos=1; pos <= st.top+1; pos++)
	{
		index = st.top - pos + 1;
		printf("st[%d] = %d\n", index, peekFromTop(st, pos));
	}
	printf("----------------- \n");
}

void display_pop(Stack *st)
{
	printf("display_pop : Displaying stack with pop \n");
	printf("----------------- \n");
	
	int val = -1;

	// Pop operation
	for(int i=0; i<st->size; i++)
	{
		val = pop(st);
		printf("display_pop : st[%d] = %d \n",st->top+1,val);
	}
	printf("----------------- \n");
}

void push_all(Stack *st)
{
	printf("----------------- \n");
    int val = 0;
	// Push operation
	for(int i=0; i<st->size; i++)
	{
		val += 10;
		push(st,val);
	}
	printf("push_all : Stack filled....\n");
	printf("----------------- \n");
}

int main()
{
	Stack st;

	int val = 0;
	printf("main : Enter the stack size : ");
	scanf("%d",&st.size);

	// create the stack in heap
	st.s = (int *)malloc(st.size * sizeof(int));

	if (st.s == NULL) {
    	printf("Memory allocation failed\n");
    	return 1;
	}

	st.top = -1; // initial top

	push_all(&st);
	isFull(st);

	display_peek(st);
	// display_pop(&st);
	isEmpty(st);

	free(st.s);
	return 0;
}

// ------------------
// Stack using Linked List
//-------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Declare top as a global pointer to Node
Node *top = NULL;

void push(int x)
{
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	if (p == NULL){
		printf("Stack is full\n");
	}
	else{
		p->data = x;
		p->next = top;
		top = p;
	}
}

int pop()
{
	Node *t;
	int x = -1;
	
	if(top == NULL){
		printf("Stack is empty\n");
	}
	else{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void Display()
{
	Node *p;
	p = top;
	while(p != NULL){
		printf("%d -> ",p->data);
		p = p->next;
	}
	printf("None\n");
}

int main()
{
	push(10);
	push(20);
	push(30);

	Display();

	printf("%d ",pop());
}

// ------------------------------------
// Stack : Linked List : Parenthesis check
//-------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the linked list
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Declare top as a global pointer to the top of the stack
Node *top = NULL;

// Function to push a character onto the stack
void push(char x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("push(char x) : Stack overflow (Heap full)\n");
    } else {
        p->data = x;
        p->next = top;
        top = p;
    }
}

// Function to pop a character from the stack
char pop() {
    Node *t;
    char x = '\0'; // Use a null character to indicate an empty stack
    
    if (top == NULL) {
        printf("pop() : Stack is empty\n"); // No need for this print in the main logic
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to check if the stack is full (not possible with this implementation)
int isFull() {
    Node *t = (Node *)malloc(sizeof(Node));
    if (t) {
        free(t);
        return 0; // Not full
    }
    return 1; // Full
}

// Function to clear the stack (important for subsequent calls to isBalanced)
void clearStack() {
    Node *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

// Function to check if an expression has balanced parentheses
int isBalanced(char *exp) {
    // Clear the stack before starting
    clearStack();

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isEmpty()) {
                printf("isBalanced(char *exp) -> stack isEmpty() : Extra closing brackets detected. Expression is unbalanced.\n");
                return 0;
            }
            
            char popped_char = pop();
            // Check for matching brackets
            if ((exp[i] == ')' && popped_char != '(') ||
                (exp[i] == ']' && popped_char != '[') ||
                (exp[i] == '}' && popped_char != '{')) {
                printf("isBalanced(char *exp) -> check_mistmatching_brackets_after_pop : Mismatched brackets detected. Expression is unbalanced.\n");
                return 0;
            }
        }
    }

    if (isEmpty()) {
        printf("isBalanced(char *exp) -> isEmpty() after_loop : Expression is balanced.\n");
        return 1;
    } else {
        printf("isBalanced(char *exp) -> isEmpty() after_loop : Extra opening brackets detected. Expression is unbalanced.\n");
        return 0;
    }
}

int main() {
    // Corrected string declaration
    char *exp1 = "((a+b)*(c-d))";
    char *exp2 = "((a+b)*[c-d]}"; // Mismatched brackets
    char *exp3 = "((a+b)*(c-d)";   // Extra opening bracket
    char *exp4 = "((a+b)))+((c-d)"; // Extra closing bracket

    printf("main() : Expression: %s\n", exp1);
    isBalanced(exp1);
    printf("\n");

    printf("main() : Expression: %s\n", exp2);
    isBalanced(exp2);
    printf("\n");

    printf("main() : Expression: %s\n", exp3);
    isBalanced(exp3);
    printf("\n");
    
    printf("main() : Expression: %s\n", exp4);
    isBalanced(exp4);
    printf("\n");

    return 0;
}
