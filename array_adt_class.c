#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *A;
	int size;
	int length;
} Array;

Array* createArray(int size, int* initialElements, int initLength)
{
	Array* arr_heap = (Array* )malloc(sizeof(Array));

	if(arr_heap == NULL)
	{
		printf("Heap is full\n");
		return NULL;
	}

	arr_heap->A = (int *)malloc(size * sizeof(int));

	if(arr_heap->A == NULL)
	{
		printf("Heap is full. Array could not be created\n");
		free(arr_heap);
		return NULL;
	}

	for(int i=0; i <initLength; i++)
	{
		arr_heap->A[i] = initialElements[i];
	}

	arr_heap->size = size;
	arr_heap->length = initLength;

	return arr_heap;
}

void display(Array* arr, const char* msg)
{
	printf("----------\n");
	printf("%s\n", msg);
	printf("----------\n");
	for(int i=0; i<arr->length; i++)
		printf("%d ",arr->A[i]);
	printf("\n");
	printf("length = %d\n",arr->length);
}

int main()
{
	int init[] = {10,20,30,40,50};
	int length = sizeof(init) / sizeof(init[0]);
	int size = length + 5;

	Array* arr = createArray(size,init,length);
	display(arr,"Initialized array");

}
