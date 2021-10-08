#include<stdio.h>
#include<stdlib.h>

int n,*arr,*countArr,*output;
void count_sort(int*,int,int);
void display_arr(int*,int);
void radix_sort(int*,int);
void count_sort(int* arr,int bit,int n){
    countArr = (int*)calloc(10,sizeof(int));
    for(int i = 0 ; i<n ; i++)
        ++countArr[(arr[i]/bit)%10];          
    for(int i=1;i<10;i++)
        countArr[i] += countArr[i-1];
    for(int i = n-1 ; i>=0;i--){
        output[countArr[(arr[i]/bit)%10]-1] = arr[i];
        countArr[(arr[i]/bit)%10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];  
    display_arr(arr,n);  
}
void display_arr(int* arr,int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void radix_sort(int* arr,int n){
    int max=arr[0];
    for(int i = 0 ; i<n ; i++)
        if(max<arr[i])
            max = arr[i];
    for (int i = 1; max/i > 0 ; i*=10)
    {
        count_sort(arr,i,n);
    }
    
}
void main(){
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    arr = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    output = (int*)calloc(n,sizeof(int));
    radix_sort(arr,n);
    display_arr(output,n);
}