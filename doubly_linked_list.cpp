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
void InsertLast(int k){
	NODE *p=create(k),*q=head;
	if(!head){
		head=p;
		return;
	}
	while(q->next){
		q=q->next;
		
	}
	q->next=p;
	p->prev=q;
}
void InsertFirst(int k){
	NODE *p=create(k);
	p->next=head;
	head->prev=p;
	head=p;
}
void InsertPosition(int k,int pos){
	NODE *p=create(k),*q=head;
	int i;
	for(i=1;i<pos-1;i++){
		q=q->next;
	}
	p->prev=q;
	p->next=q->next;
	p->next->prev=p;
	q->next=p;
}
int DeleteFirst(){
	NODE *p=head;
	int k=p->key;
	head=head->next;
	head->prev=NULL;
	p->next=NULL;
	free(p);
	return k;
}
int DeleteLast(){
	NODE *p=head;
	int k;
	while(p->next->next)
	p=p->next;
	k=p->next->key;
	p->next->prev=NULL;
	free(p->next);
	p->next=NULL;
}
int DeletePosition(int pos){
	NODE *p=head,*q;
	int i,k;
	for(i=1;i<pos-1;i++){
		p=p->next;
	}
	k=p->next->key;
	q=p->next;
	p->next=q->next;
	q->next->prev=p;
	q->next=q->prev=NULL;
	free(q);
	return k;
	
}
void display(){
	NODE *p=head;
	while(p){
		printf("%d\t",p->key);
		p=p->next;
	}
}
int main(){
	InsertLast(60);
	InsertLast(10);
	InsertFirst(20);
	InsertLast(30);
	InsertLast(40);
	InsertPosition(50,3);
	DeleteFirst();
	DeleteLast();
	DeletePosition(3);
	display();
	return 0;
}
