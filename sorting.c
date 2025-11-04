#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// # time complexity: O(n^2); best case: O(n)
// # space complexity: O(1)
void bubble_sort(int arr[], int n){
    int flag = 0; // adaptive version flag
    for (int i = 0; i < n-1; i++) {
        flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break; // Array is already sorted
        }
    }
}

void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // ------Bubble Sort --------
    // printf("Unsorted array: \n");
    // print_array(arr, n);
    
    // bubble_sort(arr, n);
    
    // printf("Sorted array: \n");
    // print_array(arr, n);
    // --------------------------

    // ------Insertion Sort -----
    printf("Unsorted array: \n");
    print_array(arr, n);
    insertion_sort(arr, n);
    printf("Sorted array: \n");
    print_array(arr, n);
    // --------------------------
    
    return 0;
}
