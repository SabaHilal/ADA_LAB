#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }
    top++;
    stack[top] = item;
}

// Function to pop an element from the stack
int pop() {
    int item;
    if (isEmpty()) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    }
    item = stack[top];
    top--;
    return item;
}

// Function to get the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return stack[top];
}

// Example usage of the stack
int main() {
    push(10);
    push(20);
    push(30);
    push(10);
    push(20);
    push(30);
    push(10);
    push(20);
    push(30);
    push(11);
   
    
   for(int loop = 0; loop < 10   ; loop++)
      printf("%d ", stack[loop]);
    
    printf("Top element is: %d\n", peek());

    printf("Popped element is: %d\n", pop());
    printf("Top element after pop is: %d\n", peek());

    return 0;
}