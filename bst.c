#include <stdio.h>
#include <stdlib.h>

// -------------------- Struct Definition --------------------
typedef struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
} Node;

// -------------------- Global Root --------------------
Node* root = NULL;

// -------------------- Node Creation --------------------
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

// -------------------- Iterative Insertion --------------------
void Insert_iter(int key) {
    Node *t = root;
    Node *r = NULL;
    Node *p;

    if (root == NULL) {
        root = createNode(key);
        return;
    }

    while (t != NULL) {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return; // Duplicate key
    }

    p = createNode(key);
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

Node* Insert_recursive(Node *t, int key) {
    if (t == NULL) {
        return createNode(key);
    }

    if (key < t->data)
        t->lchild = Insert_recursive(t->lchild, key);
    else if (key > t->data)
        t->rchild = Insert_recursive(t->rchild, key);
    else{
        // Duplicate key, do nothing
        printf("Duplicate key\n");
        return NULL;
    }
    return t;
}


// -------------------- Inorder Traversal --------------------
void Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// -------------------- Free Tree --------------------
void freeTree(Node* p) {
    if (p == NULL) return;
    freeTree(p->lchild);
    freeTree(p->rchild);
    free(p);
}

Node* Search_iter(int key){
    Node *t = root;
    while(t!=NULL){
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

// -------------------- Main --------------------
int main(void) {
    // Insert_iter(10);
    // Insert_iter(5);
    // Insert_iter(20);
    // Insert_iter(8);
    // Insert_iter(30);

    Node* temp;

    root = Insert_recursive(root,10);
    temp = Insert_recursive(root,5);
    temp = Insert_recursive(root,20);
    temp = Insert_recursive(root,8);
    temp = Insert_recursive(root,30);

    Inorder(root);
    printf("\n");
    
    // Node* temp;
    // int key = 21;
    // temp = Search_iter(key);
    
    // if (temp)
    //     printf("element = [%d] is found\n",key);
    // else
    //     printf("element = [%d] is not found\n",key);

    freeTree(root);
    return 0;
}

