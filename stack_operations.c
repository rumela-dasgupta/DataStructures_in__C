#include<stdio.h>
#include<stdlib.h>
int top=-1;
int size;
void push(int a[],int e){
    if(top==size-1){
        printf("Stack full\n");
        return;
    }
    a[++top]=e;
}
int pop(int a[]){
    int x;
    if(top==-1){
        printf("Stack empty\n");
        return -1;
    }
    x=a[top];
    top--;
    return x;
}
/*int Display_element(int a[]){
    return (a[top]);
}*/
void Display_Stack(int a[]){
    if(top==-1){
        printf("stack empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\n",a[i]);
    }
}
int main(){
    printf("Array size?: ");
    int n,x;
    
    scanf("%d",&n);
    size=n;
    int a[n];
    /*if(n>size){
        printf("Enter element size less than or equal to %d",size);
    }
    
    printf("Enter elements of array:\n");
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        a[i]=x;
    }*/
    int ch;
    do{
        
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                   printf("Enter element to be pushed into the stack: ");
                   int e;
                   scanf("%d",&e);
                   push(a,e);
                   Display_Stack(a);
                   break;
            case 2:
                  printf("The popped element is: ");
                  printf("%d",pop(a));
                  break;
            case 3:
                  printf("Present stack contents:\n");
                  Display_Stack(a);
                  break;
            case 4:
                  printf("Exiting!");
                  exit(0);
        }

    }while(ch!=4);
    return 0;



}