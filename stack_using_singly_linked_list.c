#include<stdio.h>
#include<stdlib.h>
typedef struct List{
    int key;
    struct List *next;
}NODE;
NODE *head=NULL;
NODE *create (int k){
    NODE *x=(NODE *)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    x->key=k;
    x->next=NULL;
    return x;
}
void InsertFirst(int k){ //push
    NODE *p=create(k);
    p->next=head;
    head=p;
    printf("Pushed %d onto the stack.\n", k);
}
void display(){
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    NODE *p=head;
    while(p){
        printf("%d\t",p->key);
        p=p->next;
    }
     printf("\n");
}
int deletefirst(){ //pop
    if (head == NULL) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;  // Sentinel value for empty stack
    }
    NODE *p=head;
    int k=p->key;
    head=head->next;
    p->next=NULL;
    free(p);
    return k;
}
int peek() {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return head->key;
}
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                InsertFirst(value);
                break;
            case 2:
                deletefirst();
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element is: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
