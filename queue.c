#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* temp = newNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
    }

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;

    struct Node* temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return data;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->front->data;
}

// Function to get the rear element of the queue
int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->rear->data;
}

// Example usage of the queue
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 45);
    enqueue(queue, 20);
    enqueue(queue, 50);
    enqueue(queue, 30);
    enqueue(queue, 25);


    printf("Front element is: %d\n", front(queue));
    printf("Rear element is: %d\n", rear(queue));

    printf("Dequeued element is: %d\n", dequeue(queue));
    printf("Front element after dequeue is: %d\n", front(queue));

    return 0;
}
