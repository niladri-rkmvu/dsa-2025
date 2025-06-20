#include <stdio.h>

int main()
{
	int i,j;
	/*
		i = row
		j = col
	*/
	int a[3][4] = 
	{
		/* array 1 */
		{1,2,3,4}, 		// row 1
		{5,6,7,8},  	// row 2 
		{9,10,11,12}  	// row 3
	};

	// print the array
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("Array Index: a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}

	return 0;
}
