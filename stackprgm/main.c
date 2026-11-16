#include <stdio.h>
#include <stdlib.h>
#define max 5

int item;
int item_deleted;
int s[max];
int top=-1;

void push(int item, int s[], int *top){
if(*top==max-1){
    printf("Stack is overflow \n");
    return;
}
*top=*top+1;
s[*top]=item;
}

int pop(int item, int s[], int *top){
if (*top==-1){
    printf("Stack is underflow \n");
    return -1;
    }
    item_deleted=s[*top];
    *top=*top-1;
    return item_deleted;
}
int display(int item, int s[], int *top){
    if(*top==-1){
        printf("Stack is empty");
        return 0;
    }
    for(int i=*top; i>=0; i--){
        printf("%d \n",s[i]);
    }
    return 0;
}

int main(){
int choice;
int item_deleted;
for(;;){
    printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch(choice){
    case 1:
        printf("Enter the element to be inserted: \n");
        scanf("%d",&item);
        push(item,s,&top);
        break;
    case 2:
        item_deleted=pop(item,s,&top);

         if (item_deleted != -1) {
                    printf("The deleted element from stack: %d \n", item_deleted);
                }
        break;
    case 3:
        printf("the elements present inside the stack: \n");
        display(item,s,&top);
        break;
    case 4:
        exit(0);
    default:
        printf("invalid choice");
    }
}
}

