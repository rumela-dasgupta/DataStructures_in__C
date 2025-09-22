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
void display(){
    NODE *p=head;
    while(p){
        printf("%d\t",p->key);
        p=p->next;
    }
}
void compare(){
	NODE *p=head;
	if (!p) {
        printf("The list is empty.\n");
        return;
    }
	while(p){
		if(p->key >= 10){
			printf("%d\t",p->key);
		}
		p=p->next;
		
	}
	printf("\n");
}
int main(){
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
    printf("\nNodes where current value is greater than next node:\n");
    compare();
    return 0;
}
