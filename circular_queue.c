#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=-1;
int rear=-1;
int queue[size];
void enqueue(int e){
    if(front==(rear+1)%size){
        printf("Queue full!\n");
        return;
    }
    if(front==-1) front=0;
    rear=(rear+1)%size;
    queue[rear]=e;
}
int dequeue(){
    int x;
    if(front==-1){
        printf("Queue empty!\n");
    }
    x=queue[front];
    if (front==rear){
        front=-1;
        rear=-1;
    }else front=(front+1)%size;
    return x;

}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    if (front <= rear) {
        // Case 1: No wrap-around
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        // Case 2: Wrap-around occurred
        for (int i = front; i < size; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}
int main(){
    int ch;
    do{
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                  printf("Element to enter into queue: ");
                  int e;
                  scanf("%d",&e);
                  enqueue(e);
                  printf("Entered!\n");
                  display();
                  break;
            case 2:
                  printf("Queue Element deleted!\n");
                  printf("deleted element: %d\n",dequeue());
                  printf("Queue now:\n");
                  display();
                  break;
            case 3:
                  printf("Queue present presently:\n");
                  display();
                  break;
            case 4:
                  printf("Exiting!");
                  exit(0);
        }
    }while(ch!=4);
    return 0;
}