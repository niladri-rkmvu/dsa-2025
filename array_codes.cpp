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

// -----------------------------------------------------------
//   9 Array ADT 
// -----------------------------------------------------------

#include <iostream>
#include <utility>   // For std::pair
#include <algorithm> // For std::sort, max
#include <limits>    // for (-infinity)
using namespace std;

class Array {
private:
    int* A;
    int size;
    int length;

public:
    // Constructor with initialization
    Array(int size, int initialElements[], int initialLength) {
        this->size = size;
        this->length = initialLength;
        A = new int[size];
        for (int i = 0; i < initialLength; i++) {
            A[i] = initialElements[i];
        }
    }

    void Reset(int initialElements[], int initialLength) {
        length = initialLength;
        for (int i = 0; i < initialLength; i++) {
            A[i] = initialElements[i];
        }
    }

    // Insert — Best O(1), Worst O(n)
    void Insert(int index, int element) {
        if (index < 0 || index > length || length >= size) {
            cout << "[Insert] Failed: Invalid index or array full" << endl;
            return;
        }
        // Shifting elements to the right
        for (int i = length; i > index; i--) {
            A[i] = A[i - 1];
        }
        A[index] = element;
        length++;
    }

    // Delete — Best O(1), Worst O(n)
    void Delete(int index) {
        if (index < 0 || index >= length) {
            cout << "[Delete] Failed: Invalid index" << endl;
            return;
        }
        // Shifting elements to the left
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        A[length-1] = 0;
        length--;
    }

    // Search — Best O(1), Worst O(n)
    int Search(int element) {
        for (int i = 0; i < length; i++) {
            if (A[i] == element) return i;
        }
        return -1;
    }

    // Get — O(1)
    int Get(int index) {
        if (index < 0 || index >= length) {
            cout << "[Get] Failed: Invalid index" << endl;
            return -1;
        }
        return A[index];
    }

    // Set — O(1)
    void Set(int index, int element) {
        if (index < 0 || index >= length) {
            cout << "[Set] Failed: Invalid index" << endl;
            return;
        }
        A[index] = element;
    }

    void display(const string &msg) {
        cout << endl;
        cout << "Array contents: " << msg << endl;
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // TC = O(n)
    pair<int, int> max_1_2() {
        if (length < 2) {
            cout << "[max_1_2] Failed: Not enough elements" << endl;
            return {-1, -1};
        }

        int max1;
        int max2;

        if (A[0] > A[1]){
            max1 = A[0];
            max2 = A[1];
        }
        else{
            max1 = A[1];
            max2 = A[0];
        }

        for (int i = 2; i < length; i++) {
            if (A[i] > max1) {
                max2 = max1;
                max1 = A[i];
            }
            else if (A[i] > max2){
                max2 = A[i];
            }
        }

        return {max1, max2};
    }

    // TC = O(n)
    int min(){
        int min;
        min = A[0];
        for (int i=1; i < length; i++){
            if (A[i] < min){
                min = A[i];
            }
        }
        return min;
    }

    // TC = O(n)
    int sum(){
        int total = 0;

        for(int i=0; i < length; i++){
            total += A[i];
        }
        return total;
    }

    // private method
    // TC = O(n) = depth of recursion
    // SC = O(n)
    int rsumHelper(int index) {
        if (index < 0) 
            return 0;
        return A[index] + rsumHelper(index - 1);
    }

    int rsum(){
        return rsumHelper(length - 1);
    }

    // TC = O(n)
    pair<int, int> findPairWithSum(int target) {

        sort(A, A+length);
        display("After sorting = sort(A, A+length)");

        int L = 0;
        int R = length-1;

        while (L < R) {
            int curr_sum = A[L] + A[R];

            if (curr_sum == target) {
                return {L, R}; // Return indices of the pair
            }
            else if (curr_sum > target) {
                R--;
            }
            else {
                L++;
            }
        }

        return {-1, -1}; // Not found
    }

    // TC = O(n^2)
    int sum_SubArray_brute_force(int w){
        int maxx = numeric_limits<int>::min();
        int curr_sum = 0;

        if (w > length || w <= 0) {
            cout << "[sum_SubArray_brute_force] Invalid window size" << endl;
            return -1;
        }

        for (int i=0; i <= length-w; i++){
            curr_sum = 0;
            for (int j=i; j <= i+w-1; j++){
                curr_sum = curr_sum + A[j];
            }
            maxx = max(curr_sum, maxx);
        }
        return maxx;
    }

    // TC = O(n)
    int sum_SubArray_sliding_window(int w){
        int curr_sum = 0;

        if (w > length || w <= 0) {
            cout << "[sum_SubArray_sliding_window] Invalid window size" << endl;
            return -1;
        }

        // for window 0
        for (int i=0; i<w; i++){
            curr_sum = curr_sum + A[i];
        }

        int maxx = curr_sum;

        // for windows 1,2,3
        for (int i=1; i <= length-w; i++){
            curr_sum = curr_sum - A[i-1] + A[i+w-1];
            maxx = max(curr_sum, maxx);
        }

        return maxx;
    }

    ~Array() {
        delete[] A;
        cout << "Array destroyed (memory released)" << endl;
    }
};

int main() {
    int init[] = {10, 20, 30, 40, 23, 89, 11, 94, 4};
    int n = sizeof(init) / sizeof(init[0]);
    Array arr(10, init, n);

    arr.display("Array arr(10, init, n)");

    arr.Insert(2, 25);    // Insert 25 at index 2
    arr.display("arr.Insert(2, 25)");

    arr.Delete(4);        // Delete element at index 4
    arr.display("arr.Delete(4)");

    int idx = arr.Search(30);  // Search for 30
    if (idx != -1)
        cout << "[Search] Element 30 found at index " << idx << endl;
    else
        cout << "[Search] Element 30 not found" << endl;

    int val = arr.Get(1);      // Get value at index 1
    if (val != -1)
        cout << "[Get] Value at index 1 = " << val << endl;

    arr.Set(0, 99);            // Set value at index 0
    arr.display("arr.Set(0, 99)");

    pair<int, int> result = arr.max_1_2();
    cout << "[Max] Maximum = " << result.first << ", Second Maximum = " << result.second << endl;

    int min_result = arr.min();
    cout << "[Min] Minimum = " << min_result << endl;

    int sum_result = arr.sum();
    cout << "[Sum] = " << sum_result << endl;

    int r_sum_result = arr.rsum();
    cout << "[RSum] = " << r_sum_result << endl;

    int avg = sum_result / n;
    cout << "[avg] = " << avg << endl;

    result = arr.findPairWithSum(183);
    cout << "target = 183 | " << "First =" << result.first << " | Second = " << result.second << endl;
    
    arr.Reset(init, n);
    arr.display("arr.Reset(init, n);");

    int max_sum_SubArray_brute_force = arr.sum_SubArray_brute_force(4);
    cout << "max_sum_SubArray_brute_force = " << max_sum_SubArray_brute_force << endl;

    int max_sum_SubArray_sliding_window = arr.sum_SubArray_sliding_window(4);
    cout << "max_sum_SubArray_sliding_window = " << max_sum_SubArray_sliding_window << endl;

    return 0;
}


// -----------------------------------------------------------
// 10. Remove duplicate elements from a sorted array
// -----------------------------------------------------------

#include <iostream>
#include <utility>   // For std::pair
using namespace std;


pair<int*, int> remove_duplicates(int *p, int size){
    int* newArr = new int[size];
    int x = 0;

    newArr[x++] = p[0];  // Always keep the first element

    for (int i = 1; i < size; i++) {
        if (p[i] != p[i - 1]) {
            newArr[x++] = p[i];
        }
    }
    pair<int*, int> result(newArr, x);  // Explicit constructor
    return result;
}


int main(){
    int arr[] = {5,5,7,8,8,9,9,10,10};
    int length = sizeof(arr) / sizeof(arr[0]);

    pair<int*, int> result = remove_duplicates(arr, length);
    int* newArr = result.first;
    int newSize = result.second;

    cout << "Unique elements: ";
    for (int i = 0; i < newSize; ++i)
        cout << newArr[i] << " ";
    cout << endl;

    delete[] newArr;
    return 0;
}

// -----------------------------------------------------------
// 11.a. Linear Search
// -----------------------------------------------------------

#include <stdio.h>
#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

// best case = O(1), worst case = O(n)
int LinearSearch(struct Array arr,int key)
{
    for (int i=0; i < arr.length; i++)
    {
        if (key==arr.A[i])
            return i;
    }
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    printf("%d\n",LinearSearch(arr,4));
    printf("%d\n",LinearSearch(arr,6));
    printf("%d\n",LinearSearch(arr,15));
    Display(arr);
    return 0;
}

/****************************  *************************** ***/

// -----------------------------------------------------------
// 11.b Linear Search
// Improvements
//      1. Transposition
//      2. Move to Head
// (Pointer-based implementation)
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// -----------------------------------------------------------
// Array ADT Definition
// -----------------------------------------------------------
struct Array {
    int A[10];     // Static fixed-size array
    int size;      // Total capacity
    int length;    // Current number of elements
};

// -----------------------------------------------------------
// Swap Utility (used in search optimizations)
// -----------------------------------------------------------
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// -----------------------------------------------------------
// Display Function — shows array contents
// -----------------------------------------------------------
void Display(Array* arr) {
    cout << "Array elements → ";
    for (int i = 0; i < arr->length; i++)
        cout << arr->A[i] << " ";
    cout << endl;
}

// -----------------------------------------------------------
// 1. Transposition (Pass by pointer)
// -----------------------------------------------------------
int LinearSearch_T(Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[i - 1]);
                cout << "[Transposition] Element " << key << " moved from index " << i << " to " << i - 1 << endl;
                return i - 1;
            }
            return i;
        }
    }
    cout << "[Transposition] Element " << key << " not found\n";
    return -1;
}

// -----------------------------------------------------------
// 2. Move to Head (Pass by pointer)
// -----------------------------------------------------------
int LinearSearch_MVH(Array* arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            swap(&arr->A[i], &arr->A[0]);
            cout << "[Move-to-Head] Element " << key << " moved to front\n";
            return 0;
        }
    }
    cout << "[Move-to-Head] Element " << key << " not found\n";
    return -1;
}

// -----------------------------------------------------------
// Main — Demonstrates both techniques on sample array
// -----------------------------------------------------------
int main() {
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    cout << "Initial ";
    Display(&arr);

    int index_T = LinearSearch_T(&arr, 4);
    cout << "[Transposition] Returned index: " << index_T << endl;
    Display(&arr);

    int index_MVH = LinearSearch_MVH(&arr, 4);
    cout << "[Move-to-Head] Returned index: " << index_MVH << endl;
    Display(&arr);

    return 0;
} 

/****************************  *************************** ***/

// -----------------------------------------------------------
// 12. Binary Search
// Iterative approach
// Recursion approach
// -----------------------------------------------------------

#include <iostream>
using namespace std;

// -----------------------------------------------------------
// Array ADT Definition
// -----------------------------------------------------------
struct Array {
    int A[10];     // Static fixed-size array
    int size;      // Total capacity
    int length;    // Current number of elements
};

// -----------------------------------------------------------
// Display Function — shows array contents
// -----------------------------------------------------------
void Display(Array arr) {
    for (int i = 0; i < arr.length; i++)
        cout << "A[" << i << "] = " << arr.A[i] << endl;
    cout << endl;
}

// -----------------------------------------------------------
// Iterative Binary Search — Step-by-step trace table
// -----------------------------------------------------------
int BinarySearch_iter(Array arr, int key) {
    int l = 0;
    int h = arr.length - 1;
    int mid;

    while (l <= h) {
        mid = (l + h) / 2;

        if (arr.A[mid] == key)
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// -----------------------------------------------------------
// Recursive Binary Search — with Key column in trace table
// -----------------------------------------------------------
int BinarySearch_Recursive(int a[], int l, int h, int key) {
    int mid;

    if (l <= h) {
        mid = (l + h) / 2;
        
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return BinarySearch_Recursive(a, l, mid - 1, key);
        else
            return BinarySearch_Recursive(a, mid + 1, h, key);
    }
    return -1;
}

// -----------------------------------------------------------
// Main — Demonstrates both search methods
// -----------------------------------------------------------
int main() {
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Display(arr);

    int key = 5;

    int index = BinarySearch_iter(arr, key);
    cout << "BinarySearch_iter | key = " << key << " | Returned Index = " << index << endl;

    index = BinarySearch_Recursive(arr.A, 0, arr.length - 1, key);
    cout << "BinarySearch_Recursive | key = " << key << " | Returned Index = " << index << endl;

    return 0;
}
/****************************  *************************** ***/
