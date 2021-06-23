#include<stdio.h>

void merge(int arr[],int lb ,int mid ,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int arr2[ub];
    while(i<=mid && j<=ub){
        if(arr[i]<= arr[j]){
            arr2[k] = arr[i];
            i++,k++;
        }
        else{
            arr2[k]=arr[j];
            j++,k++;
        }
        if(i>mid){
            while(j<=ub){
            arr2[k] =arr[j];
            j++,k++;
            }
        }
        else{
            while(i<=mid){
                arr2[k] =arr[i];
                k++,i++;
            }
        }
    }
    for(k=lb;k<ub;k++){
        arr2[k]=arr[k];
    }
}

void Mergesort(int arr[],int lb, int ub){
    if(lb<ub){
        int mid =(lb+ub/2);
        Mergesort(arr,lb,mid);
        Mergesort(arr,mid+1,ub);
        merge(arr,lb ,mid ,ub);
    }
}

void Printarr(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[] ={10,1,5,9,4,12,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Mergesort(arr,0,n-1);
    printf("Sorted list : \n ");
    Printarr(arr,n);
    return 0;
    
}