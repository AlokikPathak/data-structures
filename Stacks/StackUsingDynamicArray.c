#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/**
 * Stack(Last-In-First-Out)
 * @member int front: stores index of 1st element of Stack
 * @member int rear: stores index of last element of Stack
 * @member int size: stores number of elements present in Stack
 * @member unsigned int capacity: maximum no. of elements stack can have
 * @member int* array: store pointer to array of elements
 */
struct Stack{
    int top, size;
    unsigned int capacity;
    int* array;
};

/**
 * Name: createStack()
 * Purpose: creates a Stack of given capacity
 * @param unsigned int capacity
 * @return struct Stack*
 */
struct Stack* createStack(unsigned int capacity) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    // Allocating a array of given capacity and stack->array points to it
    stack->array = (int*) malloc(capacity * sizeof(int));
    // Initialization
    stack->capacity = capacity;
    stack->top = -1;//Stack-Underflow
    stack->size = 0;
    return stack;
}

/**
 * Name: isEmpty()
 * Purpose: Check whether Stack is empty or not,If False, returns 0, else any number
 * @param struct Stack* stack
 * @return int
 */
int isEmpty(struct Stack* stack) {
    return (stack->size == 0);
}

/**
 * Name: isFull()
 * Purpose: Check whether Stack is Full or not, If False, returns 0, else any number
 * @param struct Stack* stack
 * @return int
 */
int isFull(struct Stack* stack) {
    return (stack->size == stack->capacity);
}

/**
 * Name: pop()
 * Purpose: Pop out the top item(last item) from Stack
 * @param struct Stack*
 * @return void
 */
void pop(struct Stack* stack) {
    if(isEmpty(stack)){
        printf("\nStack underflow");
        return;
    }
    stack->top--;
    stack->size--;
}

/**
 * Name: push()
 * Purpose: Push item to Stack if it in not full
 * @param struck Stack*
 * @param int item
 * @return void
 */
void push(struct Stack* stack, int item) {
    if(isFull(stack)) {
        printf("\nStack Overflow");
        return;
    }
    stack->top = (stack->top+1)%stack->capacity;
    stack->array[stack->top] = item;
    stack->size++;
}

/**
 * Name: getTop()
 * Purpose: Return the Top Item, if Stack is not empty, else INT_MIN
 * @param struct Stack* stack
 * @return int
 */
int getTop(struct Stack* stack) {
    if(isEmpty(stack)){
        printf("\nStack is empty");
        return INT_MIN;
    }
    return (stack->array[stack->top]);
}

int main() {
    unsigned int capacity, choice;
    int item;
    printf("Enter the capacity of Stack\n");
    scanf("%d", &capacity);
    struct Stack* stack = createStack(capacity);

    while(1){
        printf("\nEnter your choice?\n1. Show Top\n2. Pop \n3. Push \n4. Size of Stack \n5. Capacity of Stack\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("\nTop of Stack is: %d", getTop(stack));
                    break;
            case 2: pop(stack);
                    break;
            case 3: printf("\nEnter item to be pushed in Stack: ");
                    scanf("%d", &item);
                    push(stack, item);
                    break;
            case 4: printf("\nSize of Stack is: %d", stack->size);
                    break;
            case 5: printf("\nCapacity of Stack is: %d", stack->capacity);
                    break;
            case 6: exit(0);
            default: break;
        }
    }

    free(stack);
    return 0;
}


