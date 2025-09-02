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


// -----------------------------------------------------------
// Swap Utility (used in search optimizations)
// -----------------------------------------------------------
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// -----------------------------------------------------------
// 1. Transposition (Pass by pointer)
// -----------------------------------------------------------
int LinearSearch_T(struct Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[i - 1]);
                printf("[Transposition] Element %d moved from index %d to %d\n", key, i, i - 1);
                return i - 1;
            }
            return i;
        }
    }
    printf("[Transposition] Element %d not found\n", key);
    return -1;
}

// -----------------------------------------------------------
// 2. Move to Head (Pass by pointer)
// -----------------------------------------------------------
int LinearSearch_MVH(struct Array* arr, int key) 
{
    for (int i = 0; i < arr->length; i++) 
    {
        if (arr->A[i] == key) 
        {
            swap(&arr->A[i], &arr->A[0]);
            printf("[Move-to-Head] Element %d moved to front\n", key);
            return 0;
        }
    }
    printf("[Move-to-Head] Element %d not found\n", key);
    return -1;
}

// -----------------------------------------------------------
// 3.a. Binary Search — iteration
// -----------------------------------------------------------
int BinarySearch_iter(Array* arr, int key) 
{
    int l = 0;
    int h = arr->length - 1;
    int mid;

    while (l <= h) 
    {
        mid = (l + h) / 2;

        if (arr->A[mid] == key)
            return mid;
        else if (key < arr->A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

// -----------------------------------------------------------
// 3.b. Binary Search — recursion
// -----------------------------------------------------------
int BinarySearch_Recursive(Array* arr, int l, int h, int key) 
{
    int mid;

    if (l <= h) {
        mid = (l + h) / 2;
        
        if (key == arr->A[mid])
            return mid;
        else if (key < arr->A[mid])
            return BinarySearch_Recursive(arr, l, mid - 1, key);
        else
            return BinarySearch_Recursive(arr, mid + 1, h, key);
    }
    return -1;
}

// -----------------------------------------------------------
// 4.a. Sum - iteration
// -----------------------------------------------------------

int sum(Array* arr)
{
    int total = 0;

    for(int i=0; i < arr->length; i++)
    {
        total += arr->A[i];
    }
    return total;
}


int main()
{
	int init[] = {10,20,30,40,50};
	int length = sizeof(init) / sizeof(init[0]);
	int size = length + 5;

	Array* arr = createArray(size,init,length);
	display(arr,"Initialized array");

}
