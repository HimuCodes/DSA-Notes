#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue element\n");
        return -1;
    } else {
        int dequeued = q->items[q->front];
        if (q->front == q->rear) {
            // The queue becomes empty after this operation
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return dequeued;
    }
}

// Function to display all elements of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    display(&q);

    enqueue(&q, 40);
    display(&q);

    return 0;
}
