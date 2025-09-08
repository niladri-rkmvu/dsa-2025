#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *A;
    int size;
    int length;
} Array;

Array* createArray(int size, int* initialElements, int initLength) {
    Array* arr_heap = (Array*)malloc(sizeof(Array));

    if (arr_heap == NULL) {
        printf("[createArray]: Heap is full\n");
        return NULL;
    }

    arr_heap->A = (int*)malloc(size * sizeof(int));

    if (arr_heap->A == NULL) {
        printf("[createArray]: Heap is full. Array could not be created\n");
        free(arr_heap);
        return NULL;
    }

    for (int i = 0; i < initLength; i++) {
        arr_heap->A[i] = initialElements[i];
    }

    arr_heap->size = size;
    arr_heap->length = initLength;

    return arr_heap;
    printf("---------------------\n");
}

void destroyArray(Array* arr) {
    printf("---------------------\n");
    if (arr != NULL) {
        if (arr->A != NULL) {
            free(arr->A);
            arr->A = NULL;
            printf("[destroyArray]: arr->A destoyed..\n");
        }
        free(arr);
        arr = NULL;
        printf("[destroyArray]: arr destoyed..\n");
    }
    printf("---------------------\n");
}

void display(const Array* arr, const char* msg) {
    printf("---------------------\n");
    printf("[display]: %s\n", msg);
    printf("---------------------\n");
    // for (int i = 0; i < arr->length; i++)
    //     printf("%d ", arr->A[i]);
    // printf("\n");
    // printf("\n");
    for (int i = 0; i < arr->length; i++)
        printf("A[%d] = %d\n", i, arr->A[i]);
    printf("\n");
    // printf("\n");
    printf("[display]: length = %d\n", arr->length);
    printf("[display]: size = %d\n", arr->size);
    printf("---------------------\n");
}

// Insert = Best O(1), Worst O(n)
// Index is zero-based; insertion at arr->length appends to the end.
void Insert(Array* arr, int index, int element) {
    if (index < 0 || index > arr->length || arr->length >= arr->size) {
        printf("[Insert] Failed: Invalid index or array full\n");
        return;
    }
    // Shift elements to the right
    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = element;
    arr->length++;
}

// Delete = Best O(1) when deleting the last element, Worst O(n) when deleting from the beginning or middle (due to shifting elements)
void Delete(Array* arr,int index) {
    if (index < 0 || index >= arr->length) {
        printf("[Delete] Failed: Invalid index\n");
        return;
    }
    // Shift elements to the left
    for (int i = index; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;  // Optional: clear last element
    arr->length--;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch_T(Array* arr, int key) {
    printf("---------------------\n");
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            if (i > 0) {
                swap(&arr->A[i], &arr->A[i - 1]);
                printf("[LinearSearch_T]: [Transposition] Element %d moved from index %d to %d\n", key, i, i - 1);
                return i - 1;
            }
            return i;
        }
    }
    printf("[LinearSearch_T]: [Transposition] Element %d not found\n", key);
    printf("---------------------\n");
    return -1;
}

int LinearSearch_MVH(Array* arr, int key) {
    printf("---------------------\n");
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            swap(&arr->A[i], &arr->A[0]);
            printf("[LinearSearch_MVH]: [Move-to-Head] Element %d moved to front\n", key);
            return 0;
        }
    }
    printf("[LinearSearch_MVH]: [Move-to-Head] Element %d not found\n", key);
    printf("---------------------\n");
    return -1;
}

int BinarySearch_iter(const Array* arr, int key) {
    int l = 0;
    int h = arr->length - 1;
    int mid;

    while (l <= h) {
        mid = (l + h) / 2;

        if (arr->A[mid] == key)
            return mid;
        else if (key < arr->A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    printf("---------------------\n");
    return -1;
}

int BinarySearch_Recursive(const Array* arr, int l, int h, int key) {
    if (l <= h) {
        int mid = (l + h) / 2;

        if (key == arr->A[mid])
            return mid;
        else if (key < arr->A[mid])
            return BinarySearch_Recursive(arr, l, mid - 1, key);
        else
            return BinarySearch_Recursive(arr, mid + 1, h, key);
    }
    printf("---------------------\n");
    return -1;
}

int sum(const Array* arr) {
    printf("---------------------\n");
    int total = 0;
    for (int i = 0; i < arr->length; i++) {
        total += arr->A[i];
    }
    printf("[sum]: Array Total = %d\n", total);
    printf("---------------------\n");
    return total;
}

int Rsum_Helper(const int* A, int index) {
    if (index < 0)
        return 0;
    return A[index] + Rsum_Helper(A, index - 1);
}

int Rsum(const Array* arr) {
    if (arr == NULL || arr->A == NULL || arr->length <= 0) {
        printf("[Rsum]: Invalid array or empty\n");
        return 0;
    }
    return Rsum_Helper(arr->A, arr->length - 1);
}

int Get(const Array* arr, int index) {
    if (index < 0 || index >= arr->length) {
        printf("[Get]: Failed - Invalid index\n");
        return -1;
    }
    return arr->A[index];
}

void Set(Array* arr, int index, int element) {
    if (index < 0 || index >= arr->length) {
        printf("[Set]: Failed - Invalid index\n");
        return;
    }
    arr->A[index] = element;
}

int min(const Array* arr){
    int min;
    min = arr->A[0];

    for (int i=1; i < arr->length; i++){
        if (arr->A[i] < min){
            min = arr->A[i];
        }
    }
    return min;
}

int max(const Array* arr){
    int max;
    max = arr->A[0];

    for (int i=1; i < arr->length; i++){
        if (arr->A[i] > max){
            max = arr->A[i];
        }
    }
    return max;
}

int remove_duplicates_sorted_array(const Array* arr, int output[]) {
    if (arr->length == 0) 
        return 0;

    int outIndex = 0;
    output[outIndex++] = arr->A[0];

    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] != arr->A[i - 1]) {
            output[outIndex++] = arr->A[i];
        }
    }
    return outIndex;
}

int sum_2_pointer(Array* arr, int target, int *left_ptr, int *right_ptr) {
    *left_ptr = 0;
    *right_ptr = arr->length - 1;

    while (*left_ptr < *right_ptr) {
        int current_sum = arr->A[*left_ptr] + arr->A[*right_ptr];
        if (current_sum == target) {
            return current_sum;
        } else if (current_sum < target) {
            (*left_ptr)++;
        } else {
            (*right_ptr)--;
        }
    }
    return -1; // No pair found
}

// O(n^2) time complexity
// O(1) space complexity
int brute_force_subarray_sum(Array* arr, int w) {
    int maxx = -1;
    int curr_sum = 0;
    for(int i = 0; i<= (arr->length - w); i++) {
        curr_sum = 0;
        for(int j = i; j <= (i + w - 1); j++) {
            curr_sum = curr_sum + arr->A[j];
        }
        if(curr_sum > maxx) {
            maxx = curr_sum;
        }
    }
    return maxx;
}

// O(n) time complexity
// O(1) space complexity
int sliding_window_subarray_sum(Array* arr, int w) {
    int maxx = -1;
    int curr_sum = 0;

    // window = 1
    for(int i = 0; i < w; i++) {
        curr_sum += arr->A[i];
    }
    maxx = curr_sum;

    // rest of the windows
    for(int i = w; i < arr->length; i++) {
        curr_sum = curr_sum + arr->A[i] - arr->A[i - w]; 
        if(curr_sum > maxx) {
            maxx = curr_sum;
        }
    }
    return maxx;
}

int main() {
    int init[] = {3,8,2,5,7,6,12};
    int length = sizeof(init) / sizeof(init[0]); // initial length of the array
    int size = length + 5; // extra space for future insertions
    int key, search, index, element, total; // general-purpose variables
    int minVal, maxVal; // for min() and max() functions
    int result, left_idx,right_idx, target_sum = 15; // used for sum_2_pointer
    int maxx = -1, w; // used for brute_force_subarray_sum, sliding_window_subarray_sum

    // --------------------------------------
    // Array* createArray(int size, int* initialElements, int initLength)
    // --------------------------------------
    Array* arr = createArray(size, init, length);
    if (arr == NULL) {
        return 1; // graceful exit on allocation failure
    }
    // --------------------------------------


    // --------------------------------------
    // void display(const Array* arr, const char* msg)
    // --------------------------------------
    display(arr, "Initialized array");
    // --------------------------------------


    // --------------------------------------
    // int LinearSearch_T(Array* arr, int key)
    // --------------------------------------
    // LinearSearch_T(arr, 30);
    // display(arr, "[main]: After LinearSearch_T(arr, 30)");
    // --------------------------------------


    // --------------------------------------
    // int LinearSearch_MVH(Array* arr, int key)
    // --------------------------------------
    // LinearSearch_MVH(arr, 40);
    // display(arr, "[main]: After LinearSearch_MVH(arr, 40");
    // --------------------------------------


    // --------------------------------------
    // void sum(const Array* arr)
    // --------------------------------------
    // total = sum(arr);
    // --------------------------------------


    // --------------------------------------
    // int Rsum(const Array* arr)
    // --------------------------------------
    // total = Rsum(arr);
    // printf("[main]: int Rsum(const Array* arr) = %d\n",total);
    // --------------------------------------


    // --------------------------------------
    // int BinarySearch_Recursive(const Array* arr, int l, int h, int key)
    // --------------------------------------
    // key = 97;
    // search = BinarySearch_Recursive(arr,0,(arr->length-1),key);

    // if (search != -1)
    //     printf("[main]: BinarySearch_Recursive: input (element) = %d, output (index position) = %d\n",key,search);
    // else
    //     printf("[main]: BinarySearch_Recursive: input (element) = %d, output (index position) = failed\n",key);
    // --------------------------------------


    // --------------------------------------
    // int BinarySearch_iter(const Array* arr, int key)
    // --------------------------------------
    // search = BinarySearch_iter(arr,key);
   
    // if (search != -1)
    //     printf("[main]: BinarySearch_iter input (element) = %d, output (index position) = %d\n",key,search);
    // else
    //     printf("[main]: BinarySearch_iter: input (element) = %d, output (index position) = failed\n",key);
    // --------------------------------------


    // --------------------------------------
    // void Insert(Array* arr, int index, int element)
    // --------------------------------------
    // index = 4; // taking a random index
    // element = 78;
    // Insert(arr, index, element);
    // display(arr, "Insert(4,78)");
    // --------------------------------------


    // --------------------------------------
    // void Delete(Array* arr, int index)
    // --------------------------------------
    // index = 4;
    // Delete(arr, index);
    // display(arr, "Delete(4)");
    // --------------------------------------


    // --------------------------------------
    // int Get(const Array* arr, int index)
    // --------------------------------------
    // index = 3;
    // element = Get(arr, index);
    // printf("[main]: Get input (index) = %d, output (element) = %d\n",index,element);
    // --------------------------------------


    // --------------------------------------
    // void Set(Array* arr, int index, int element)
    // --------------------------------------
    // index = 3;
    // element = 65;
    // Set(arr, index, element);
    // display(arr, "[main]: Set(arr, 3, 65);");
    // --------------------------------------


    // --------------------------------------
    // int max(const Array* arr)
    // --------------------------------------
    // maxVal = max(arr);
    // printf("[main]: max(arr) = %d\n",maxVal);
    // --------------------------------------


    // --------------------------------------
    // int min(const Array* arr)
    // --------------------------------------
    // minVal = min(arr);
    // printf("[main]: min(arr) = %d\n",minVal);
    // --------------------------------------


    // --------------------------------------
    // int remove_duplicates_sorted_array(const Array* arr, int output[])
    // --------------------------------------
    // int output[size];
    // int newLength = remove_duplicates_sorted_array(arr,output);
    // printf("[main]: after removing duplicates\n");
    // for (int i = 0; i < newLength; i++)
    //     printf("%d ", output[i]);
    // printf("\n");
    // --------------------------------------


    // --------------------------------------
    // int sum_2_pointer(Array* arr, int target, int *left_ptr, int *right_ptr)
    // --------------------------------------
    // result = sum_2_pointer(arr, target_sum, &left_idx, &right_idx);
    // if (result == -1) {
    //     printf("[main]: sum_2_pointer | No pair found with the target sum %d\n", target_sum);
    // }
    // else{
    //     printf("[main]: sum_2_pointer | Pair found with the target sum %d: A[%d] = %d, A[%d] = %d\n", target_sum, left_idx, arr->A[left_idx], right_idx, arr->A[right_idx]);
    // }
    // --------------------------------------

    // --------------------------------------
    // int brute_force_subarray_sum(Array* arr, int w)
    // --------------------------------------
    // w = 4; // window size
    // maxx = brute_force_subarray_sum(arr, w);
    // printf("[main]: brute_force_subarray_sum | w = %d is max sum = %d\n", w, maxx);
    // --------------------------------------


    // --------------------------------------
    // int sliding_window_subarray_sum(Array* arr, int w)
    // --------------------------------------
    // w = 4; // window size
    // maxx = sliding_window_subarray_sum(arr, w);
    // printf("[main]: sliding_window_subarray_sum | w = %d is max sum = %d\n", w, maxx);
    // --------------------------------------


    // --------------------------------------
    // void destroyArray(Array* arr)
    // --------------------------------------
    destroyArray(arr);
    // --------------------------------------

    return 0;
}

