#include<stdio.h>
#include<stdlib.h>
typedef struct List{
    int key;
    struct List *next;
}NODE;
NODE *head=NULL;
NODE *create (int k){
    NODE *x=(NODE *)malloc(sizeof(NODE));
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
void reverse(){
    NODE *p1=head,*p2=NULL,*p3;
    while(p1){
        p3=p2;
        p2=p1;
        p1=p1->next;
        p2->next=p3;
    }
    head=p2;
}
void display(){
    NODE *p=head;
    while(p){
        printf("%d\t",p->key);
        p=p->next;
    }
}
int main() {
    int value,choice;

   do {
        printf("Enter value(key) to insert: ");
        scanf("%d", &value);
        InsertLast(value);

        printf("Do you want to insert another value? (press 0 for yes or 1 for no): ");
        scanf("%d", &choice);  
    } while (choice == 0);

    printf("\nOriginal linked list:\n ");
    display();
    reverse();
    printf("\nReversed linked list:\n");
    display();
    return 0;
}

