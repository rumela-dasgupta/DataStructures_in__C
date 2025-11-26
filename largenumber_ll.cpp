#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int digit;
    struct Node *next;
} Node;

// Create a new node
Node* newNode(int digit) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->digit = digit;
    n->next = NULL;
    return n;
}

// Insert at end (MSD at head)
void append(Node **head, int digit) {
    Node *temp = newNode(digit);

    if (*head == NULL) {
        *head = temp;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
}

// Read a very large number and store it in linked list
Node* storeNumber(const char *num) {
    Node *head = NULL;
    for (int i = 0; num[i] != '\0'; i++) {
        append(&head, num[i] - '0');
    }
    return head;
}

// Print number
void printList(Node *head) {
    while (head != NULL) {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}

int main() {
    char number[1000];

    printf("Enter a large number: ");
    scanf("%s", number);

    Node *numList = storeNumber(number);

    printf("Stored number: ");
    printList(numList);

    return 0;
}

