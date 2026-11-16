#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d to Stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d from Stack\n", temp->data);
    top = top->next;
    free(temp);
}

void enqueue(int value) {
    struct Node* newNode = createNode(value);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d to Queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d from Queue\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}


void display(struct Node* head, const char* name) {
    if (head == NULL) {
        printf("%s is empty\n", name);
        return;
    }
    printf("%s elements: ", name);
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    printf("STACK OPERATIONS\n");
    push(10);
    push(20);
    push(30);
    display(top, "Stack");

    pop();
    display(top, "Stack");

    printf("\n QUEUE OPERATIONS \n");
    enqueue(100);
    enqueue(200);
    enqueue(300);
    display(front, "Queue");

    dequeue();
    display(front, "Queue");

    return 0;
}
