#include<stdio.h>
#include<stdlib.h>
void mergeSort(int a[],int n){
	int s=1,l1,l2,u1,u2,i,j,k;
	int t[n];
	while(s<n){
		l1=0;
		k=0;
		while(l1+s<n){
		l2=l1+s;
		u1=l2-1;
		u2=(u1+s)<n?u1+s:n-1;
		for(i=l1,j=l2;i<=u1&&j<=u2;k++){
			if(a[i]<a[j])
			t[k]=a[i++];
			else
			t[k]=a[j++];
		}
			while(i<=u1) t[k++]=a[i++];
			while(j<=u2) t[k++]=a[j++];
			l1=u2+1;
		}
		for(i=l1;i<n;i++){
			t[k++]=a[i];
		} 
		for(i=0;i<n;i++) {
			a[i]=t[i];
		}
		s*=2;
	}
}
int main(){
	int a[] = {10, 30, 55, 20, 65, 70, 100, 99};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
	

