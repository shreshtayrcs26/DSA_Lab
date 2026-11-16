#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

typedef struct Node* NODE;

NODE getnode() {
    NODE temp = (NODE)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return temp;
}

void freenode(NODE temp) {
    free(temp);
}

NODE insert_front(int item, NODE first) {
    NODE temp = getnode();
    temp->data = item;
    temp->link = first;
    return temp;
}

NODE insert_rear(int item, NODE first) {
    NODE temp = getnode();
    temp->data = item;
    temp->link = NULL;

    if (first == NULL) {
        return temp;
    }

    NODE cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE insert_at_pos(int item, int pos, NODE first) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return first;
    }

    if (pos == 1) {
        return insert_front(item, first);
    }

    NODE temp = getnode();
    temp->data = item;

    NODE cur = first;
    int count = 1;
    while (cur != NULL && count < pos - 1) {
        cur = cur->link;
        count++;
    }

    if (cur == NULL) {
        printf("Position out of bounds!\n");
        freenode(temp);
        return first;
    }

    temp->link = cur->link;
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }
    NODE temp = first;
    first = first->link;
    printf("Deleted first element: %d\n", temp->data);
    freenode(temp);
    return first;
}

NODE delete_rear(NODE first) {
    if (first == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }

    if (first->link == NULL) {
        printf("Deleted last element: %d\n", first->data);
        freenode(first);
        return NULL;
    }

    NODE cur = first;
    NODE prev = NULL;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    printf("Deleted last element: %d\n", cur->data);
    freenode(cur);
    return first;
}

NODE delete_specified(int key, NODE first) {
    if (first == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }

    if (first->data == key) {
        NODE temp = first;
        first = first->link;
        printf("Deleted specified element: %d\n", temp->data);
        freenode(temp);
        return first;
    }

    NODE cur = first;
    NODE prev = NULL;
    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->link;
    }

    if (cur == NULL) {
        printf("Element %d not found in the list\n", key);
        return first;
    }

    prev->link = cur->link;
    printf("Deleted specified element: %d\n", cur->data);
    freenode(cur);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = first;
    printf("Linked List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main() {
    NODE first = NULL;
    int choice, item, pos, key;

    while (1) {
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Delete Specified Element\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                first = insert_front(item, first);
                break;
            case 2:
                printf("Enter item to insert at end: ");
                scanf("%d", &item);
                first = insert_rear(item, first);
                break;
            case 3:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                printf("Enter position index (1-based): ");
                scanf("%d", &pos);
                first = insert_at_pos(item, pos, first);
                break;
            case 4:
                first = delete_front(first);
                break;
            case 5:
                first = delete_rear(first);
                break;
            case 6:
                printf("Enter the element value to search and delete: ");
                scanf("%d", &key);
                first = delete_specified(key, first);
                break;
            case 7:
                display(first);
                break;
            case 8:
                printf("Exiting Program\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option from 1 to 8.\n");
        }
    }
    return 0;
}
