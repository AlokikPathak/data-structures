#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front, rear, size;
    unsigned int capacity; //Stores the capacity of Queue
    int *array;
};
// Function to create Queue of a specific capacity
// Initialize the size of Queue as 0
struct Queue* createQueue(unsigned int capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity-1; //refer enqueue function
    // Create Integer array of size 'capacity'
    queue->array =(int*) malloc((queue->capacity)*sizeof(int));
    return queue;
}
// Queue is full when size becomes equal to capacity
// Overflow
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
// Queue is empty when size is 0
// Underflow
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

//Function to add item in Queue
//It alters rear and size
void enqueue(struct Queue* queue, int item) {
    if(isFull(queue))
        return;
    //Circular Indexing Technique
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
  //  printf("\nEnqueued %d", item);
}

//Function to remove item from queue
//It removes item from queue
void dequeue(struct Queue* queue) {
    if(isEmpty(queue))
        return;

    int item = queue->array[queue->front];
    // Circular indexing technique , after last index queue->front will be point to Null Index i.e index before 0th Index(empty queue)
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
  //  printf("\nDequeued: %d", item);
}

//Function to get front item of queue
int getFront(struct Queue* queue) {
    // Checking underflow condition
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear item of queue
int getRear(struct Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main(){

    struct Queue* queue = createQueue(1000);
    enqueue(queue, 10);
    enqueue(queue, 345);
    enqueue(queue, 675);
    enqueue(queue, 3435);

    printf("%d front of Queue", getFront(queue));
    dequeue(queue);
    printf("\n%d front of Queue", getFront(queue));
    printf("\n%d rear of Queue", getRear(queue));

    return 0;
}
