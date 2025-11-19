#include <stdio.h>
#include <stdlib.h>

// -----------------------------
// Linked List Node definition
// -----------------------------
struct Node {
    int data;
    struct Node* next;
};

// -----------------------------
// Hash Table definition
// -----------------------------
struct HashTable {
    struct Node** HT;   // Array of linked list heads
};

// -----------------------------
// Function to create Hash Table
// -----------------------------
struct HashTable* createHashTable() {
    struct HashTable* H = (struct HashTable*)malloc(sizeof(struct HashTable));
    H->HT = (struct Node**)malloc(10 * sizeof(struct Node*));
    for (int i = 0; i < 10; i++) {
        H->HT[i] = NULL;   // Initialize all heads to NULL
    }
    return H;
}

// -----------------------------
// Hash function
// -----------------------------
int hash(int key) {
    return key % 10;
}

// -----------------------------
// Insert function
// -----------------------------
void Insert(struct HashTable* H, int key) {
    int hIdx = hash(key);

    // Create new node
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;

    // Case 1: No nodes in the linked list
    if (H->HT[hIdx] == NULL) {
        H->HT[hIdx] = t;
    } else {
        struct Node* p = H->HT[hIdx];
        struct Node* q = H->HT[hIdx];

        // Traverse to find insert position
        while (p && p->data < key) {
            q = p;
            p = p->next;
        }

        // Case 2: Insert at beginning
        if (q == H->HT[hIdx]) {
            t->next = H->HT[hIdx];
            H->HT[hIdx] = t;
        } else {
            // Case 3: Insert in between or at end
            t->next = q->next;
            q->next = t;
        }
    }
}

// -----------------------------
// Search function
// -----------------------------
int Search(struct HashTable* H, int key) {
    int hIdx = hash(key);
    struct Node* p = H->HT[hIdx];

    while (p) {
        if (p->data == key) {
            return p->data;   // Found
        }
        p = p->next;
    }
    return -1;   // Not found
}

// -----------------------------
// Free memory (Destructor equivalent)
// -----------------------------
void freeHashTable(struct HashTable* H) {
    for (int i = 0; i < 10; i++) {
        struct Node* p = H->HT[i];
        while (p) {
            struct Node* temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(H->HT);
    free(H);
}

// -----------------------------
// Main function
// -----------------------------
int main() {
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A) / sizeof(A[0]);

    // Create Hash Table
    struct HashTable* H = createHashTable();

    // Insert elements
    for (int i = 0; i < n; i++) {
        Insert(H, A[i]);
    }

    // Successful search
    printf("Successful Search\n");
    int key = 6;
    int value = Search(H, key);
    printf("Key: %d, Value: %d\n", key, value);

    // Unsuccessful search
    printf("Unsuccessful Search\n");
    key = 95;
    value = Search(H, key);
    printf("Key: %d, Value: %d\n", key, value);

    // Free memory
    freeHashTable(H);

    return 0;
}
