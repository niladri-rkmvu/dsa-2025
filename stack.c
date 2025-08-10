// ------------------
//		Stack
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