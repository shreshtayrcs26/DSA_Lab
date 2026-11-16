#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        printf("Created list with node %d\n", value);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Appended %d to the list\n", value);
}

void insertLeft(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the left\n", value);
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List Underflow (List is empty)\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (temp == head) {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("Deleted %d from the list\n", value);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Doubly Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- CREATING DOUBLY LINKED LIST ---\n");
    createList(10);
    display();

    printf("\n--- INSERTING AT THE LEFT ---\n");
    insertLeft(20);
    insertLeft(30);
    insertLeft(40);
    insertLeft(50);
    display();

    printf("\n--- DELETING BY VALUE ---\n");
    deleteByValue(10);
    display();
    deleteByValue(50);
    display();

    return 0;
}
