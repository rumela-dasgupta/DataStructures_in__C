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
void InsertLast(int k){
    NODE *p=create(k),*q=head;
    if (!head){
        head=p;
        return;
    }
    while(q->next)
    q=q->next;
    q->next=p;
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
int deletefirst(){
    NODE *p=head;
    int k=p->key;
    head=head->next;
    p->next=NULL;
    free(p);
    return k;
}
/*int peek() {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return head->key;
}*/
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1.Enqueue \n");
        printf("2. Dequeue\n");
       // printf("3. Peek\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                InsertLast(value);
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