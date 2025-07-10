/*---------------------------------------------------------------
		   						Array codes
----------------------------------------------------------------*/


/* -------------------------------
1. Demo array | Show X Code
----------------------------------*/

#include <stdio.h>
#include <iostream>
using namespace std

int main()
{
	int A[5];
	int B[5] = {1,2,3,4,5};
	int C[10] = {2,4,6};
	int D[5] = {0}; // rest of the elements should be filled with 0
	int E[] = {1,2,3,4,5,6};
	int F[10] = {[0]=1,[5]=10}; // designated initialization

	return 0;
}


/* -------------------------------
2. print the array address - to prove contiguous memory locations
----------------------------------*/
#include <stdio.h>
#include <cstdint>
#include <iostream>
using namespace std;

int main()
{
	int A[5];
	int i;

	for (i=0; i<5; i++)
	{
		// printf("%p \n", &A[i]); prints hexadecimal addresses
		printf("%lu\n", (uintptr_t)&A[i]);
	}

	return 0;
}

140735579401376
140735579401380
140735579401384
140735579401388
140735579401392

/* -------------------------------
3. VLAs - allowed after C99 & C++
----------------------------------*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Pass the address of n
    int A[n];         // VLA (only if your compiler supports C99 or later)

    // Optional: Initialize and print the array
    for (int i = 0; i < n; i++) {
        A[i] = i * i;
        printf("A[%d] = %d\n", i, A[i]);
    }

    return 0;
}

/*------------ ------------ ------------ */
//  4.a. Pointers : create array in heap | C 
/*------------ ------------ ------------ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int val = 10;
    int size = 5;

    // create an array in heap
    p = (int*)malloc(size*sizeof(int));

    // initialize the values in the heap
    for (int i = 0; i < size; i++){
        p[i] = val;
        val = val + 10;
    }

    // display the values using pointer
    for (int i = 0; i < size; i++){
        printf("A[%d] = %d\n",i,p[i]);
    }
    
    // display the address of array
    printf("Address of array in Heap = %p\n",p);

    // free the allocated memory from heap
    free(p);

    return 0;
}

A[0] = 10
A[1] = 20
A[2] = 30
A[3] = 40
A[4] = 50
Address of array in Heap = 0x623f543d62a0

/*------------ ------------ ------------ */
//  4.b. Pointers : create array in heap | C++
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main()
{
    int *p;
    int val = 10;
    int size = 5;

    // create an array in heap
    p = new int[5];

    // initialize the values in the heap
    for (int i = 0; i < size; i++){
        p[i] = val;
        val = val + 10;
    }

    // display the values using pointer
    for (int i = 0; i < size; i++){
        cout << "A[" << i << "] = " << p[i] << endl;
    }
    
    // display the address of array
    cout << "Address of array in heap = " << p << endl;

    // free the allocated memory from heap
    delete[] p;

    return 0;
}

A[0] = 10
A[1] = 20
A[2] = 30
A[3] = 40
A[4] = 50
Address of array in heap = 0x639abf51b2b0

/*------------ ------------ ------------ */
//  5. Increase size of Dynamic array
/*------------ ------------ ------------ */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int size = 5;
    int *p = new int[size];
    int val = 10;

    // Assign p array in heap
    for (int i=0; i<size; i++)
    {
    	p[i] = val;
    	val = val + 10;
    }
    
    cout << "Address of p = " << p << endl;
    cout << " ------------- " << endl;
    
    // Display p
    for (int i=0; i<size; i++)
    	cout << "p[" << i << "] = " << p[i] << endl;

    cout << " ------------- " << endl;

    // Assign q array in heap with a bigger size
    int *q = new int[10]; 

    // copy elements from p -> q
    memcpy(q,p,sizeof(p));
    
    cout << "Address of q = " << q << endl;

    /*
    for (int i=0; i<size; i++)
    	q[i] = p[i];
    */

    // Display q
    for (int i=0; i<size; i++)
    	cout << "q[" << i << "] = " << p[i] << endl;

    // free the allocated memory from heap
    delete[] p;

    // Assign p to q
    p = q;

    // Reset q
    q = NULL;
    
    cout << "Address of p after reset = " << p << endl;
    cout << "Address of q after reset = " << q << endl;
    
    return 0;
}

Address of p = 0x58ad764402b0
 ------------- 
p[0] = 10
p[1] = 20
p[2] = 30
p[3] = 40
p[4] = 50
 ------------- 
Address of q = 0x58ad764406e0
q[0] = 10
q[1] = 20
q[2] = 30
q[3] = 40
q[4] = 50
Address of p after reset = 0x58ad764406e0
Address of q after reset = 0


/*------------ ------------ ------------ */
//  6.a Demo 2D array | row major order & col major order
/*------------ ------------ ------------ */

#include <iostream>

int main() {
    const int row = 2;
    const int col = 3;

    // Define a 2D array A[2][3]
    int A[row][col] = {
        {1, 2, 3}, // row 1
        {4, 5, 6}  // row 2
    };

    // Even this declaration will work - but avoid this
    // int A[row][col] = {1,2,3,4,5,6};

    // a. Row-major order (C-style)
    std::cout << "Row-major order:\n";
    for (int i = 0; i < row; ++i) {         // Rows
        for (int j = 0; j < col; ++j) {     // Columns
            std::cout << "A[" << i << "][" << j << "] = " << A[i][j] << std::endl;
        }
    }
    std::cout << std::endl;

    // b. Column-major order (Fortran-style)
    std::cout << "Column-major order:\n";
    for (int j = 0; j < col; ++j) {         // Columns
        for (int i = 0; i < row; ++i) {     // Rows
            std::cout << "A[" << i << "][" << j << "] = " << A[i][j] << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}

Row-major order:
A[0][0] = 1
A[0][1] = 2
A[0][2] = 3
A[1][0] = 4
A[1][1] = 5
A[1][2] = 6

Column-major order:
A[0][0] = 1
A[1][0] = 4
A[0][1] = 2
A[1][1] = 5
A[0][2] = 3
A[1][2] = 6


/*------------ ------------ ------------ */
//  6.b Demo 2D array
//  Array of pointers = stack
//  actual array = heap
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main() {
    const int row = 2;
    const int col = 3;
    int val = 10;

    // Array of pointers | in stack
    int *A[row];

    // create the array in heap
    A[0] = new int[col];
    A[1] = new int[col];

    // assign values to the array in heap
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            A[i][j] = val;
            val = val + 10;
        }
    }

    // Display the Address of Stack
    cout << "Addresses in Array variable in Stack : " << endl;
    cout << " --------------- " << endl;
    cout << "address (A[0]) in stack = " << &A[0] << endl;
    cout << "address (A[1]) in stack = " << &A[1] << endl;
    
    // Display the addresses of Heap
    cout << "Addresses in Array in Heap : " << endl;
    cout << " --------------- " << endl;
    cout << "A[0] = " << A[0] << endl;
    cout << "A[1] = " << A[1] << endl;
    cout << " --------------- " << endl;

    cout << "Values of Array in Heap : " << endl;

    // Display the values from heap
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout << "A[" << i << "]" << "[" << j << "] = " << A[i][j] << endl;
        }
    }

    // free the memory location
    for (int i = 0; i < row; ++i) {
        delete[] A[i];
        A[i] = nullptr;
    }

    return 0;
}

Addresses in Array variable in Stack : 
 --------------- 
address (A[0]) in stack = 0x7fff8f9c9a50
address (A[1]) in stack = 0x7fff8f9c9a58

Addresses in Array in Heap : 
 --------------- 
A[0] = 0x60640f52e2b0
A[1] = 0x60640f52e2d0

 --------------- 
Values of Array in Heap : 
A[0][0] = 10
A[0][1] = 20
A[0][2] = 30
A[1][0] = 40
A[1][1] = 50
A[1][2] = 60


/*------------ ------------ ------------ */
//  6.c Demo 2D array
//  Array of pointers = Heap
//  actual array = heap
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main() {
    const int row = 2;
    const int col = 3;
    int val = 10;

    // Pointer of Pointers | A is created in stack
    int **A;

    // creates 2 rows in heap
    A = new int *[row]; 

    // create the array in heap
    A[0] = new int[col];
    A[1] = new int[col];

    // assign values to the array in heap
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            A[i][j] = val;
            val = val + 10;
        }
    }

    // Display the Address of Stack
    cout << "Address (A) in stack = " << &A << endl;
    cout << "A[0] in heap = " << A << endl;
    cout << " --------------- " << endl;
    
    // Display the addresses of Heap
    cout << "Addresses in Array in Heap : " << endl;
    cout << " --------------- " << endl;
    cout << "A[0] (should be same what A[0] in heap printed above) = " << A[0] << endl;
    cout << "A[1] = " << A[1] << endl;
    cout << " --------------- " << endl;

    cout << "Values of Array in Heap : " << endl;

    // Display the values from heap
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout << "A[" << i << "]" << "[" << j << "] = " << A[i][j] << endl;
        }
    }

    // free the memory location
    for (int i = 0; i < row; ++i) {
        delete[] A[i];
        A[i] = nullptr;
    }

    delete[] A; // free row pointer array
    A = nullptr;

    return 0;
}

Address (A) in stack = 0x7ffd68058730
A[0] in heap = 0x55ffa9bde2b0
 --------------- 
Addresses in Array in Heap : 
 --------------- 
A[0] (should be same what A[0] in heap printed above) = 0x55ffa9bde2d0
A[1] = 0x55ffa9bde2f0
 --------------- 
Values of Array in Heap : 
A[0][0] = 10
A[0][1] = 20
A[0][2] = 30
A[1][0] = 40
A[1][1] = 50
A[1][2] = 60


/*------------ ------------ ------------ */
//  7. Demo 3D array | row major order & col major order
/*------------ ------------ ------------ */

#include <iostream>

int main() {
    const int M = 2;
    const int row = 2;
    const int col = 3;

    // Define a 3D array A[M][row][col]
    int A[M][row][col] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };

    // a. Row-major order: i → j → k
    std::cout << "Row-major order:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < row; ++j) {
            for (int k = 0; k < col; ++k) {
                std::cout << "A[" << i << "][" << j << "][" << k << "] = " << A[i][j][k] << std::endl;
            }
        }
    }
    std::cout << std::endl;

    // b. Column-major order (simulated): k → j → i
    std::cout << "Column-major order:\n";
    for (int k = 0; k < col; ++k) {
        for (int j = 0; j < row; ++j) {
            for (int i = 0; i < M; ++i) {
                std::cout << "A[" << i << "][" << j << "][" << k << "] = " << A[i][j][k] << std::endl;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}

Row-major order:
A[0][0][0] = 1
A[0][0][1] = 2
A[0][0][2] = 3
A[0][1][0] = 4
A[0][1][1] = 5
A[0][1][2] = 6
A[1][0][0] = 7
A[1][0][1] = 8
A[1][0][2] = 9
A[1][1][0] = 10
A[1][1][1] = 11
A[1][1][2] = 12

Column-major order:
A[0][0][0] = 1
A[1][0][0] = 7
A[0][1][0] = 4
A[1][1][0] = 10
A[0][0][1] = 2
A[1][0][1] = 8
A[0][1][1] = 5
A[1][1][1] = 11
A[0][0][2] = 3
A[1][0][2] = 9
A[0][1][2] = 6
A[1][1][2] = 12

/*------------ ------------ ------------ */
//  8.a. 2x2 RMO and CMO Address Calculation
/*------------ ------------ ------------ */
#include <iostream>
using namespace std;

int main() {
    // Bounds
    int X_lower = -5, X_upper = 5;
    int Y_lower = -10, Y_upper = 10;

    // Memory setup
    int base_address = 1000;
    int size_bytes = 2;

    // Dimensions
    int X = (X_upper - X_lower) + 1; // Rows
    int Y = (Y_upper - Y_lower) + 1; // Cols

    // Target indices
    int i = 1; // row index
    int j = 1; // column index

    // --- Row Major Order Calculation ---
    int rmo_preceding_elements = ((i - X_lower) * Y) + (j - Y_lower);
    int rmo_address = base_address + (rmo_preceding_elements * size_bytes);

    cout << "RMO Preceding Elements = " << rmo_preceding_elements << endl;
    cout << "RMO Address            = " << rmo_address << endl << endl;

    // --- Column Major Order Calculation ---
    int cmo_preceding_elements = ((j - Y_lower) * X) + (i - X_lower);
    int cmo_address = base_address + (cmo_preceding_elements * size_bytes);

    cout << "CMO Preceding Elements = " << cmo_preceding_elements << endl;
    cout << "CMO Address            = " << cmo_address << endl;

    return 0;
}

RMO Preceding Elements = 137
RMO Address            = 1274

CMO Preceding Elements = 127
CMO Address            = 1254

// -----------------------------------------------------------
// Title: 8.b. 3x3 RMO and CMO Address Calculation
// -----------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    // ---------- Array Boundaries ----------
    int X_lower = 0, X_upper = 5;    // Matrix (depth) bounds
    int Y_lower = 0, Y_upper = 10;   // Row bounds
    int Z_lower = 0, Z_upper = 7;    // Column bounds

    // ---------- Memory Setup ----------
    int base_address = 1000;         // Starting memory location
    int size_bytes = 2;              // Size of each element (e.g., int = 2 bytes)

    // ---------- Dimension Calculation ----------
    int X = (X_upper - X_lower) + 1; // Total matrices
    int Y = (Y_upper - Y_lower) + 1; // Total rows
    int Z = (Z_upper - Z_lower) + 1; // Total columns

    // ---------- Target Element Indices ----------
    int i = 1; // Matrix index
    int j = 1; // Row index
    int k = 1; // Column index

    // ---------- Row-Major Order (RMO) Address Calculation ----------
    int rmo_preceding_elements = ((i - X_lower) * (Y * Z)) + ((j - Y_lower) * Z) + (k - Z_lower);
    int rmo_address = base_address + (rmo_preceding_elements * size_bytes);

    cout << "Row-Major Order (RMO) Address Calculation\n";
    cout << "RMO Preceding Elements = " << rmo_preceding_elements << endl;
    cout << "RMO Address            = " << rmo_address << "\n\n";

    // ---------- Column-Major Order (CMO) Address Calculation ----------
    int cmo_preceding_elements = ((k - Z_lower) * (X * Y)) + ((j - Y_lower) * X) + (i - X_lower);
    int cmo_address = base_address + (cmo_preceding_elements * size_bytes);

    cout << "Column-Major Order (CMO) Address Calculation\n";
    cout << "CMO Preceding Elements = " << cmo_preceding_elements << endl;
    cout << "CMO Address            = " << cmo_address << endl;

    return 0;
}

Row-Major Order (RMO) Address Calculation
RMO Preceding Elements = 97
RMO Address            = 1194

Column-Major Order (CMO) Address Calculation
CMO Preceding Elements = 73
CMO Address            = 1146


// -----------------------------------------------------------
// 9. Array ADT 
// Description: Demonstrates a simple fixed-size Array structure 
//              and displays its initialized elements.
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// Structure to represent a statically allocated array
struct Array {
    int A[10];     // Fixed-size internal array
    int length;    // Logical number of elements present
};

// Function to display elements of the array
void Display(struct Array arr)
{
    cout << "\nElements are:\n";
    for (int i = 0; i < arr.length; i++) {
        cout << "arr.A[" << i << "] = " << arr.A[i] << endl;
    }
}

int main() {
    // Initialize the array with 5 integers and set length to 5
    struct Array arr = {{2, 3, 4, 5, 6}, 5};

    // Display current contents of the array
    Display(arr);

    return 0;
}


Elements are:
arr.A[0] = 2
arr.A[1] = 3
arr.A[2] = 4
arr.A[3] = 5
arr.A[4] = 6
