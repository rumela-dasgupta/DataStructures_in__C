#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
	int key;
	struct List *next;
	struct List  *prev;
}NODE;

NODE *head=NULL;

NODE *create(int k)
{
	NODE *x=(NODE *)malloc(sizeof(NODE));
	x->key=k;
	x->next=x->prev=NULL;
	return x;
}
void insertLast(int k)
{
	NODE *p=create(k);
	NODE *q=head;
	if(!head)
	{
		head=p;
		return;
	}
	while(q->next)
		q=q->next;
	q->next=p;
	p->prev=q;
}
void insertFirst(int k)
{
	NODE *p=create(k);
	p->next=head;
	head->prev=p;
	head=p;
}
/*void insertPosition(int k,int pos)
{
	NODE *p=create(k);
	NODE *q=head;
	int i;
	for(i=1;i<pos-1;i++)
		q=q->next;
	p->next=q->next;
	q->next=p;
}*/
void display()
{
	NODE *p=head;
	while(p)
	{
		printf("%d  ",p->key);
		p=p->next;
	}
}
int main()
{
	int ch,k,pos,y;
	while(1)
	{
	printf("\nEnter 1 to insert first, 2 to insert last, 3 to display & 4 to exit: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter element: ");
			scanf("\n%d",&k);
			insertFirst(k);
			break;
		case 2:
			printf("Enter element: ");
			scanf("\n%d",&k);
			insertLast(k);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid choice!");
			break;
	}
	}
	return 0;
}

