#include<stdio.h>
#include<stdlib.h>

int n,*arr,*countArr,*output;
void count_sort(int* arr,int n);
void display_arr(int* arr,int n);
void count_sort(int* arr,int n){
    int max=arr[0];
    for(int i = 0 ; i<n ; i++)
        if(max<arr[i])
            max = arr[i];
    countArr = (int*)calloc(max+1,sizeof(int));
    for(int i = 0 ; i<n ; i++)
        ++countArr[arr[i]]; 
    for(int i=1;i<max+1;i++)
        countArr[i] += countArr[i-1];
    for(int i = 0 ; i<n;i++){
        output[countArr[arr[i]]-1] = arr[i];
        countArr[arr[i]]--;
    }
}
void display_arr(int* arr,int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void main(){
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    arr = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    output = (int*)calloc(n,sizeof(int));
    count_sort(arr,n);
    display_arr(output,n);
}