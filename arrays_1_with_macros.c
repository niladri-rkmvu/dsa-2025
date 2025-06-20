#include <stdio.h>
#define N 10

int main()
{
	int a[N], i;

	for(i=0; i<N; i++){
		printf("Enter the i/p of index %d:",i);
		scanf("%d",&a[i]);
	}

	printf("\nArray elements are as follows:\n\n");
	for(i=0; i<N; i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
