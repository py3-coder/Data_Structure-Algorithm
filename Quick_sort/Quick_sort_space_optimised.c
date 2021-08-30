@Saurabh kumar
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
    while(lb<ub){
        int pi =Partition(arr,lb,ub);
         if (pi - lb < ub - pi)
        {
            quicksort(arr, lb, pi - 1);
            lb = pi + 1;
        }
        else
        {
            quicksort(arr, pi + 1, ub);
            ub = pi - 1;
        }
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
    int arr[] ={4, 3, 8, 7, 1, 5}; 
    int n = 6; 
    quicksort(arr,0,n-1); 
    printf("Sorted array: \n"); 
    printarr(arr, n); 
}

