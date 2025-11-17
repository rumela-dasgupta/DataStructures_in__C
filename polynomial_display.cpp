#include<stdio.h>
#include<stdlib.h>
typedef struct Polynomial{
	int c,e;
	struct Polynomial *next;
}NODE;
NODE* createNode(int cf,int ex){
NODE *p=(NODE *)malloc(sizeof(NODE));
p->c=cf;
p->e=ex;
p->next=NULL;
}
NODE* insertTerm(NODE *head,int cf,int ex){
	NODE *temp=createNode(cf,ex);
	if(head==NULL||ex>head->e){
		temp->next=head;
		return temp;
	}
	NODE* curr=head;
	while(curr->next!=NULL&&curr->next->e>=ex){
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
	
}
void Display(NODE *head){
	if(head==NULL){
		printf("Polynomial is empty\n");
		return;
	}
	NODE *temp=head;
	while(temp!=NULL){
		printf("%dx^%d",temp->c,temp->e);
		if(temp->next!=NULL)
		printf(" + ");
		temp=temp->next;
	}
	printf("\n");
}
double eval(NODE* head,int x){
	double result=0;
	NODE* temp=head;
	while(temp!=NULL){
		double term=(double)temp->c;
		double powVal=1;
		for(int i=0;i<temp->e;i++)
		powVal*=x;
		term*=powVal;
		result+=term;
		temp=temp->next;
	}
	return result;
}
int main(){
	NODE* head=NULL;
	int n,c,p;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter coefficient and exponent: ");
		scanf("%d %d",&c,&p);
		head=insertTerm(head,c,p);
	}
	printf("Polynomial: ");
	Display(head);
	double x;
	printf("Enter value of x: ");
	scanf("%lf",&x);
	double val=eval(head,x);
	printf("Value of polynomial with the entered value of x is: %lf",val);
	return 0;
}

