#include<stdio.h>
#include<stdlib.h>
#define size 50
int queue[size];
int rear=-1;
int front=-1;
void enqueue(int e){
    if (rear==size-1){
        printf("Queue full\n");
        return;
    }
    if(front==-1){
        front=0;
        
    }
    queue[++rear]=e;
}
int dequeue(){
    int x,i;
    if(rear==-1){
        printf("Queue Empty\n");
        return -1;
    }
    x=queue[0];
    for(i=0;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear--;
    return x;

}
void display(){

    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
}
printf("\n");
}
int main(){
    int ch;
    do{
        printf("1.Enque\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("Enter element to be entered into queue: ");
                   int e;
                   scanf("%d",&e);
                   enqueue(e);
                   display();
                   break;
            case 2:
                  printf("The deleted element is:\n ");
                  printf("%d\n",dequeue());
                  display();
                  break;
            case 3:
                  printf("Present queue contents:\n");
                  display();
                  break;
            case 4:
                   printf("Exiting!");
                   exit(0);
                   
        }
    }while(ch!=4);
    return 0;
}