#include <stdio.h>
#include <stdlib.h>
#define size=5;

int item;
int item_deleted;
int s[max];
int top;

void push(){
if (top=size-1){
    printf("Stack is overflow");
    return;
}
*top=*top+1;
s[*top]=item;
}

int pop(){
if (top==-1){
    printf("Stack is underflow");
    return;
}
item_deleted=s[top];
top=top-1;
return item_deleted;
}

void display(){
if (top==-1){
    printf("Stack is empty");
    return;
}
for (int i=top; i>=0; i--){
    printf("%d \n",s[i]);
}
}

int main(){
int choice;
int item_deleted;
for(;;){
    printf("1:push \n,2:pop \n,3:display \n,4:exit\n");
    printf("Enter your choice: \n";
    scanf("%d \n", &choice);

    switch(choice){
    case 1:
        printf("Enter the element to be inserted: \n");
        scanf("%d \n",item);
        push();
        break;
    case 2:
        item_deleted=pop();
        printf(item_deleted);
        break;
    case 3:
        printf("the elements present inside the stack: \n");
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("invalid choice");
    }
}
}

