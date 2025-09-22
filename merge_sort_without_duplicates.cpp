#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void inputArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter element %d\t:", i + 1);
        scanf("%d", &arr[i]);
    }
}

void DisplayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int nA,nB;
    int arrA[SIZE];
    int arrB[SIZE];
    int arrC[SIZE*2];  
    printf("Enter number of elements in array A: ");
    scanf("%d", &nA);
    if (nA > SIZE)
        printf("INDEX OUT OF BOUNDS");
    else {
        inputArray(arrA, nA);
        printf("sorted array A: \n");
        selection_sort(arrA, nA);
        DisplayArray(arrA, nA);
    }

    printf("Enter number of elements in array B: ");
    scanf("%d", &nB);
    if (nB > SIZE)
        printf("INDEX OUT OF BOUNDS");
    else {
        inputArray(arrB, nB);  
        printf("sorted array B: \n");
        selection_sort(arrB, nB);
        DisplayArray(arrB, nB);
    }

    int i=0, j=0,k=0;
    while (i<nA&&j<nB) {
        if (arrA[i] <arrB[j]) {
            arrC[k++] = arrA[i++];
        } 
		else if(arrA[i]>arrB[j]) {
            arrC[k++] = arrB[j++];
        }
        else{
        	arrC[k++]=arrA[i++];
        	j++;
		}
    }

    while(i<nA) {
        arrC[k++] = arrA[i++];
    }

    while(j <nB) {
        arrC[k++]=arrB[j++];
    }

    printf("New array after merge sort:\n");
    DisplayArray(arrC, k);

    return 0;
}

