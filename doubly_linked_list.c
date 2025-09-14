#include<stdio.h>
#include<stdlib.h>
typedef struct List{
    int key;
    struct List *next,*prev;

}NODE;
NODE *head=NULL;
NODE *create(int k){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    p->key=k;
    p->next=p->prev=NULL;
    return p;
}
void insertLast(int k){
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
void insertFirst(int k){
    NODE *p=create(k);
    p->next=head;
    head->prev=p;
    head=p;
}
void insertPosition(int k,int pos){
    NODE *p=create(k),*q=head;
    int i;
    for(i=1;i<pos-1;i++) q=q->next;
    p->prev=q;
    p->next=q->next;
    p->next->prev=p;
    q->next=p
}