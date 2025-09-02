#include<stdio.h>
#define SIZE 5
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
int main(){
void bubble_sort(int arr[],int n){
int temp,i,j;
int flag=1;
for(i=0;i<n-1&&flag;i++){
flag=0;
for(j=0;j<n-i-1;j++){
if (arr[j]>arr[j+1]){
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
flag=1;
}
}
}
}
void insertion_sort(int arr[],int n){
int t,i,j;
for(i=1;i<n;i++){
t=arr[i];
for(j=i-1;j>=0&&t<arr[j];j--){
arr[j+1]=arr[j];
}
arr[j+1]=t;
}
}
void selection_sort(int arr[],int n){
int temp,i,j;
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(arr[i]>arr[j]){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
}
int binary_search(int arr[],int n,int e){
int low=0;
int high=n-1;
while(low<=high){
int mid=(low+high)/2;
if(e==arr[mid])
return 1;
if(e<arr[mid])
high=mid-1;
else
low=mid+1;

}
return -1;
}
int quick_sort_partition(int a[], int l, int h) {
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
int p;
if (l<h){
p=quick_sort_partition(a,l,h);
quicksort(a,l,p-1);
quicksort(a,p+1,h);
}
}
int n;
int arr[SIZE];
printf("Enter number of elements in array: ");
scanf("%d",&n);
if(n>SIZE)
printf("INDEX OUT OF BOUNDS");
else
inputArray(arr,n);
printf("unsorted array: \n");
DisplayArray(arr,n);
int ch;
printf("\n1.Bubble Sort \n2.Insertion Sort \n3.Selection Sort \n4.Binary Search \n5.Quick Sort\nEnter Choice:\t");

scanf("%d",&ch);
int e;


switch(ch){
case 1:
bubble_sort(arr,n);
printf("Sorted Array: \n");
DisplayArray(arr,n);
break;
case 2:
insertion_sort(arr,n);
printf("Sorted Array: \n");
DisplayArray(arr,n);
break;
case 3:
selection_sort(arr,n);
printf("Sorted Array: \n");
DisplayArray(arr,n);
break;
case 4:
selection_sort(arr,n);
printf("Sorted Array: \n");
DisplayArray(arr,n);

printf("Enter element to search: ");
scanf("%d",&e);
int result=binary_search(arr,n,e);
if(result!=-1){
printf("Element found at index %d",result);
}
else{
printf("Not found");
}
break;
case 5:
quicksort(arr,0,n-1);
printf("Sorted Array: \n");
DisplayArray(arr,n);
break;


default:
printf("Wrong Choice");
break;




}


return 0;

}
