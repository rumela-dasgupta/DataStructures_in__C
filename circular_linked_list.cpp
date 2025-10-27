#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
	int key;
	struct List *next;
}NODE;

NODE *head=NULL;

NODE *create(int k)
{
	NODE *x=(NODE *)malloc(sizeof(NODE));
	x->key=k;
	x->next=NULL;
	return x;
}
void circular_linked_list(int k)
{
	NODE *p=create(k);
	NODE *q=head;
	if(!head)
	{
		head=p;
		p->next=p;
		return;
	}
	while(q->next!=head)
		q=q->next;
	q->next=p;
	p->next=head;

}
void display(){
	NODE *p=head;
	do{
		printf("%d\t",p->key);
		p=p->next;
	}while(p!=head);
}
int main(){
	circular_linked_list(10);
	circular_linked_list(20);
	circular_linked_list(30);
	display();
	return 0;
}
