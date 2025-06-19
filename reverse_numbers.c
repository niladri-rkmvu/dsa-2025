#include <stdio.h>

int main()
{
	int arr[9]={34,56,54,32,67,89,90,32,21};
	int i;
	int size = (sizeof(arr)/sizeof(arr[0]) - 1);

	// Loop through the array to print normal way
	printf("Normal order:\n");

	for(i=0; i<9; i++){
		printf("Array Index: %d, value: %d\n", i, arr[i]);
	}

	printf("\nArray elements in reversed order are as follows:\n\n");
	for(i=size; i>=0; i--){
		printf("Array Index: %d, value: %d\n", i, arr[i]);
	}
	return 0;
}