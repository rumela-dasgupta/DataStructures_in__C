#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size];
int top=-1;
void inputArray(int arr[],int n){
int i;
for(i=0;i<n;i++){
printf("Enter element %d\t:",i+1);
scanf("%d",&arr[i]);
}
}

void DisplayArray(int arr[],int n){
int i;
for(i=0;i<n;i++){
printf("%d\t",arr[i]);
}
printf("\n");
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
void push(int x) {
    if (top == size - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}
int partition(int a[], int l, int h) {
    int pivot = a[l];
    int low = l ;
    int high = h;

    while (low < high) {
        while ( a[low] <= pivot) {
            low++;
        }
        while (a[high] > pivot) {
            high--;
        }
        if (low < high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }

    int temp1 = a[l];
    a[l] = a[high];
    a[high] = temp1;

    return high;
}
void quicksort(int a[],int l,int h){
	push(l);
	push(h);
	int p;
	while(top!=-1){
		h=pop();
		l=pop();
		if((h-l)>=1){
			p=partition(a,l,h);
			push(l);
			push(p-1);
			push(p+1);
			push(h);
		}
	}
}
int main(){
int n;
int arr[size];
printf("Enter number of elements in array: ");
scanf("%d",&n);
if(n>size)
printf("INDEX OUT OF BOUNDS");
else
inputArray(arr,n);

quicksort(arr,0,n-1);
printf("Sorted array:\n");
DisplayArray(arr, n);

}