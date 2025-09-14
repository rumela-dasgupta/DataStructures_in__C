#include<stdio.h>
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
void InsertFirst(int k){
    NODE *p=create(k);
    p->next=head;
    head=p;
}
void InsertPosition(int k,int pos){
    NODE *p=create(k),*q=head;
    int i;
    for(i=1;i<pos-1;i++){
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
}
void display(){
    NODE *P=head;
    while(p){
        printf("%d\t",p->key);
        p=p->next;
    }
}
int deletefirst(){
    NODE *p=head;
    int k=p->key;
    head=head->next;
    p->next=NULL;
    free(p);
    return k;
}
int deletelast(){
    NODE *p=head;
    int k;
    while(p->next->next) p=p->next;
    k=p->next->key;
    free(p->next);
    p->next=NULL;
    return k;
}
int deleteposition(int pos){
    NODE *p=head,*q;
    int k,i;
    for(i=1;i<pos-1;i++){
        p=p->next;
    }
    k=p->next->key;
    q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
    return k;
}