/*------------------------------------------------------
                    1. Queue ADT
------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue_T;

// Enqueue operation
void enqueue(Queue_T *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
        printf("enqueue: value = %d is enqueued\n", x);
    }
}

// Dequeue operation
int dequeue(Queue_T *q) {
    int x = -1;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
        printf("dequeue: value = %d is dequeued\n", x);
    }
    return x;
}

// Display operation
void display(Queue_T *q) {
    printf("-----------------\n");
    printf("displaying Queue:\n");
    printf("-----------------\n");

    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("Queue[%d] = %d\n", i, q->Q[i]);
    }

    printf("size = %d\n", q->size);
    printf("front = %d\n", q->front);
    printf("rear = %d\n", q->rear);
    printf("-----------------\n");
}

void create(Queue_T *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
    if (!(q->Q)) {
        printf("Memory allocation failed\n");
    }
}

int main() {
    Queue_T q;
    int size;

    printf("main: Enter the Queue size: ");
    scanf("%d", &size);

    create(&q,size);
    
    int val = 10;
    
    for (int i=0; i<q.size; i++){
        enqueue(&q, val);
        val += 10;
    }
    display(&q);

    for (int i=0; i<q.size; i++){
        dequeue(&q);
    }
    display(&q);

    free(q.Q);
    return 0;
}

/*------------------------------------------------------
            2. Circular Queue ADT
    This addresses drawbacks of regular queue
------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue_T;

// Enqueue operation
void enqueue(Queue_T *q, int x) {
    int new_rear_pos = (q->rear+1)%q->size;
    if (new_rear_pos == q->front) {
        printf("Queue is full\n");
    } else {
        q->rear = new_rear_pos;
        q->Q[new_rear_pos] = x;
        printf("enqueue: value = %d is enqueued\n", x);
    }
}

// Dequeue operation
int dequeue(Queue_T *q) {
    int x = -1;
    int new_front_pos = (q->front+1)%q->size;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->front = new_front_pos;
        x = q->Q[new_front_pos];
        printf("dequeue: value = %d is dequeued\n", x);
    }
    return x;
}

// Display operation
void display(Queue_T *q) {
    printf("-----------------\n");
    printf("displaying Queue:\n");
    printf("-----------------\n");

    for (int i = q->front+1; i <= q->rear; i++) {
        printf("Queue[%d] = %d\n", i, q->Q[i]);
    }

    printf("size = %d\n", q->size);
    printf("front = %d\n", q->front);
    printf("rear = %d\n", q->rear);
    printf("-----------------\n");
}

void create(Queue_T *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(size * sizeof(int));
    if (!(q->Q)) {
        printf("Memory allocation failed\n");
    }
}

int main() {
    Queue_T q;
    int size;

    printf("main: Enter the Queue size: ");
    scanf("%d", &size);

    create(&q,size);
    
    int val = 10;
    
    for (int i=0; i<q.size; i++){
        enqueue(&q, val);
        val += 10;
    }
    display(&q);

    for (int i=0; i<q.size; i++){
        dequeue(&q);
    }
    display(&q);

    free(q.Q);
    return 0;
}
