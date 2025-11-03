#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
	int key;
	struct Tree *left,*right;
}NODE;
NODE *root=NULL;
void create_BinaryTree(int k){
	NODE *p=(NODE *)malloc(sizeof(NODE));
	NODE *q=root,*r;
	int ch;
	p->key=k;
	p->left=p->right=NULL;
	if(!root){
		root=p;
		return;
	}
	while(q){
		r=q;
		printf("%d will be at left subtree or at right subtree of %d (1/0): ",k,r->key);
		scanf("%d",&ch);
		if(ch)
		q=q->left;
		else
		q=q->right;
	}
	if(ch)
	r->left=p;
	else
	r->right=p;
}
void create_BinarySearchTree(int k){
	NODE *p=(NODE *)malloc(sizeof(NODE));
	NODE *q=root,*r;
	int ch;
	p->key=k;
	p->left=p->right=NULL;
	if(!root){
		root=p;
		return;
	}
	while(q){
		r=q;
		if(k<r->key)
		q=q->left;
		else
		q=q->right;
	}
	if(k<r->key)
	r->left=p;
	else
	r->right=p;
}
void inorder(NODE *r){
	if(r){
		inorder(r->left);
		printf("%d\t",r->key);
		inorder(r->right);
	}
}
void preorder(NODE *r){
	if(r){
		printf("%d\t",r->key);
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(NODE *r){
	if(r){
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->key);
	}
}
int main(){
	/* create_BinaryTree(20);
	create_BinaryTree(10);
	create_BinaryTree(30);
	create_BinaryTree(40);
	create_BinaryTree(50); */
	create_BinarySearchTree(20);
	create_BinarySearchTree(10);
	create_BinarySearchTree(11);
	create_BinarySearchTree(30);
	create_BinarySearchTree(40);
	printf("inorder traversal:\n");
	inorder(root);
	printf("\npreorder traversal:\n");
	preorder(root);
	printf("\npostorder traversal:\n");
	postorder(root);
	return 0;
}

