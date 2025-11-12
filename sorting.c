#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// # time complexity: O(n^2); best case: O(n)
// # space complexity: O(1)
void bubble_sort(int A[], int n){
    int flag = 0; // adaptive version flag
    for (int i = 0; i < n-1; i++) {
        flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break; // Array is already sorted
        }
    }
}

void insertion_sort(int A[], int n){
    for (int i = 1; i < n; i++) {
        int x = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void selection_sort(int A[], int n)
{
    int i, j, k;
    for(i=0; i<(n-1); i++) // for passes
    {
        for(j=k=i; j<n; j++) // for comparisons
        {
            if (A[j] < A[k])
                k = j;
        }
        // now k will be at the smallest element
        swap(&A[i], &A[k]);
    }
}

int main(){
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A)/sizeof(A[0]);
    
    // ------Bubble Sort --------
    // printf("Unsorted Aay: \n");
    // print_array(A, n);
    
    // bubble_sort(A, n);
    
    // printf("Sorted Aay: \n");
    // print_array(A, n);
    // --------------------------

    // ------Insertion Sort -----
    // printf("Unsorted Aay: \n");
    // print_array(A, n);
    // insertion_sort(A, n);
    // printf("Sorted Aay: \n");
    // print_array(A, n);
    // --------------------------

    // ------Selection Sort -----
    printf("Unsorted Aay: \n");
    print_array(A, n);
    selection_sort(A, n);
    printf("Sorted Aay: \n");
    print_array(A, n);
    // --------------------------
    
    return 0;
}
