#include <stdio.h>
#include <stdlib.h>

// Time complexity: O(log n)
void insert(int H[], int n) {
    int i = n;
    int temp = H[i];
    while (i > 1 && temp > H[i/2]) {
        H[i] = H[i/2]; // H[i/2] = parent node
        i = i/2; // i moves to parent index
    }
    H[i] = temp; // Place temp at its correct position
}

int delete(int H[], int n) {
    int i, j, root, last, temp;
    root = H[1]; // root element
    H[1] = H[n]; // move last element to root
    H[n] = root; // place root at the end

    i = 1; // index of root element
    j = 2 * i; // index of left child

    while (j < n - 1) {
        if (H[j + 1] > H[j]) {
            j = j + 1; // right child index
        }
        if (H[i] < H[j]) {
            // swap
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j; // move i to j
            j = 2 * i; // left child index
        } else {
            break; // heap property is satisfied
        }
    }
    return root; // return deleted root element
}

int main(void) {
    // Example array with dummy 0th index
    int H[] = {0,10,20,30,25,5,40,35};
    // max Heap = 40,25,35,10,5,20,30
    // Number of elements in the heap. we are excluding 0th index
    int n = sizeof(H) / sizeof(H[0]) - 1;
    int i;
    for (int i = 2; i <= n; i++) {
        insert(H, i);
    }

    // Delete elements from heap
    // i = n;
    // printf("Deleted value : %d\n", delete(H, i--)); // 40
    // printf("Deleted value : %d\n", delete(H, i--)); // 35

    for(i = n; i >= 2; i--) {
        printf("Deleted value : %d\n", delete(H, i));
    }

    // display the array
    for (int i=1; i<=n; i++)
        printf("%d ",H[i]);
    printf("\n");
    
    return 0;
}
