#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} NODE;
NODE* root = NULL;
void create_BinarySearchTree(int k){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->key = k;
    p->left = p->right = NULL;

    if (!root) {
        root = p;
        return;
    }

    NODE *q = root, *r = NULL;
    while (q) {
        r = q;
        if (k < q->key)
            q = q->left;
        else
            q = q->right;
    }

    if (k < r->key)
        r->left = p;
    else
        r->right = p;
}

void inorderToArray(NODE* r, int arr[], int *i) {
    if (r) {
        inorderToArray(r->left, arr, i);
        arr[(*i)++] = r->key;
        inorderToArray(r->right, arr, i);
    }
}

int inorderSuccessor(int arr[], int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == x)
            return arr[i + 1];
    }
    return -1;
}

int main() {
    create_BinarySearchTree(10);
    create_BinarySearchTree(5);
    create_BinarySearchTree(20);
    create_BinarySearchTree(15);
    create_BinarySearchTree(35);

    int n = 5;
    int arr[n], i = 0;

    inorderToArray(root, arr, &i);

    int x = 20;
    int succ = inorderSuccessor(arr, n, x);

    if (succ != -1)
        printf("Inorder successor of %d is %d\n", x, succ);
    else
        printf("%d has no inorder successor\n", x);

    return 0;
}


