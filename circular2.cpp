#include<stdio.h>
#include<stdlib.h>
typedef struct List{
	int key;
	struct List *next,*prev;
}NODE;
NODE *head=NULL;
NODE *create(int k){
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->key=k;
	p->next=p->prev=NULL;
	return p;
}
void circular_doubly_linked_list(int k){
	NODE *p=create(k),*q=head;
	if(!head){
		head=p;
		p->next=p;
		p->prev=p;
		return;
	}
	while(q->next!=head){
		q=q->next;
		
	}
	q->next=p;
	p->prev=q;
	p->next=head;
	head->prev=p;
}
void display(){
	NODE *p=head;
	do{
		printf("%d\t",p->key);
		p=p->next;
	}while(p!=head);
}
int main(){
	circular_doubly_linked_list(10);
	circular_doubly_linked_list(20);
	circular_doubly_linked_list(30);
	display();
	return 0;
}
