#include<stdio.h>

void Swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int Partition(int arr[],int lb,int ub){
    int pivot =arr[lb];
    int start = lb;
    int end  = ub;
    while(start < end){
    while(arr[start]<=pivot){
        start ++;
    }
    while(arr[end]>pivot){
        end--;
    }
    if(start < end){
        Swap(&arr[start],&arr[end]);
    }
    }
    Swap(&arr[lb],&arr[end]);
    return end;

}
void quicksort(int arr[], int lb, int ub){
    if(lb<ub){
        int loc =Partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
void printarr(int arr[] , int size){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    printf("\n");
    }
}
int main() 
{ 
    int arr[] ={10, 7, 8, 9, 1, 5}; 
    int n = 6; 
    quicksort(arr,0,n-1); 
    printf("Sorted array: \n"); 
    printarr(arr, n); 
}