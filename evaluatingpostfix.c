#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
void push(int[],int);
int pop(int[]);
int is_digit(char sym);
int oper(char,int,int);
int eval(char[]);
int main(){
    char exp[MAX];
    printf("Enter postfix form: ");
    scanf("%[^\n]",exp);
    printf("%d",eval(exp));
    return 0;
}
int is_digit(char sym){
    if((sym>='0')&&(sym<='9')) return 1;
    else return 0;
}
int oper(char sym,int op1,int op2){
    switch(sym){
        case '+': return (op1+op2); break;
        case '-': return (op1-op2); break;
        case '*': return (op1*op2); break;
        case '/': return (op1/op2); break;

    }
}
int eval(char exp[]){
    int i,j,val,op1,op2;
    int a[MAX];
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]==' ') continue;
        if(is_digit(exp[i])==1) push(a,(exp[i]-'0'));
        else{
            op2=pop(a);
            op1=pop(a);
            val=oper(exp[i],op1,op2);
            push(a,val);
        }
    }
    j=pop(a);
    return j;
}
void push(int a[],int x){
    ++top;
    if(top==MAX-1){
        printf("stack full");
        return;
    }
    a[top]=x;
}
int pop(int a[]){
    if(top==-1){
        printf("Stack empty");
        return top;
    }
    int x=a[top--];
    return x;
}