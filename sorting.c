#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// used for quick sort
int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l;
    int j = h;
    while (i < j) {
        while (i <= h && A[i] <= pivot) i++;
        while (j >= l && A[j] > pivot) j--;
        if (i < j) swap(&A[i], &A[j]);
    }
    swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        quick_sort(A, l, j-1);
        quick_sort(A, j+1, h);
    }
}

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[h+1];  // temporary array

    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    // copy remaining elements from left half
    while(i <= mid)
        B[k++] = A[i++];

    // copy remaining elements from right half
    while(j <= h)
        B[k++] = A[j++];

    // copy back to A
    for(i = l; i <= h; i++)
        A[i] = B[i];
}

void merge_sort_iter(int A[], int n)
{
    int p, i, l, mid, h;

    // p = size of subarray to merge
    for(p = 2; p <= n; p = p * 2)
    {
        for(i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }

    // If array size is odd / not power of 2, merge remaining part
    if(p/2 < n)
    {
        merge(A, 0, (p/2) - 1, n - 1);
    }
}



int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(A[0]);
    
    // ------Bubble Sort --------
    // printf("Unsorted Array: \n");
    // print_array(A, n);
    // bubble_sort(A, n);
    // printf("Bubble Sorted Array: \n");
    // print_array(A, n);
    // --------------------------

    // ------Insertion Sort -----
    // printf("Unsorted Array: \n");
    // print_array(A, n);
    // insertion_sort(A, n);
    // printf("Insertion Sorted Array: \n");
    // print_array(A, n);
    // --------------------------

    // ------Selection Sort -----
    // printf("Unsorted Array: \n");
    // print_array(A, n);
    // selection_sort(A, n);
    // printf("Selection Sorted Array: \n");
    // print_array(A, n);
    // --------------------------

    // ------Quick Sort -----
    // printf("Unsorted Array: \n");
    // print_array(A, n);
    // quick_sort(A, 0, n-1);
    // printf("Quick Sorted Array: \n");
    // print_array(A, n);
    // --------------------------

    // ------Merge Sort -----
    printf("Unsorted Array: \n");
    print_array(A, n);
    merge_sort_iter(A, n);
    printf("Merge Sorted Array: \n");
    print_array(A, n);
    // --------------------------
    
    return 0;
}
