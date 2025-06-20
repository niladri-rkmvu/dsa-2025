#include <stdio.h>

int main()
{
	int i,j,k;

	/*
		i = array
		j = row
		k = col
	*/

	int a[2][2][3] = 
	{
		/* array 1 */
		{
			{1,2,3}, 	// row 1
			{4,5,6}  	// row 2 
		},
		/* array 2 */
		{
			{7,8,9}, 	// row 1
			{10,11,12}  // row 2
		}
	};

	// print the array
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			for(k=0; k<3; k++){
				printf("Array Index: a[%d][%d][%d] = %d\n", i,j,k, a[i][j][k]);
			}
		}
	}

	return 0;
}
