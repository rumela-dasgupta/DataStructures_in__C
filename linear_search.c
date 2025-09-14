//Linear Search
#include<stdio.h>
int Linear_search(int a[],int n,int e){
    for(int i=0;i<n;i++){
        if(a[i]==e){
            return i;
        }
    
    }
    return -1;
}
int main(){
    printf("how many elements in array?: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in array one by one\n");
    for(int i=0;i<n;i++){
        int f;
        printf("Enter element %d: ",i+1);
        scanf("%d",&f);
        a[i]=f;
    }
    int e;
    printf("Enter element to search: ");
    scanf("%d",&e);
    int result=Linear_search(a,n,e);
    if(result!=-1){
        printf("Element found at index %d",result);
    }else{
        printf("Element not found!");
    }
    return 0;
}