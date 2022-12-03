#include<stdio.h>

int partition(int a[],int lb, int ub){
    int pivot=a[lb];
    int start = lb;
    int end = ub;
    int temp;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            temp=a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    temp=a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void quickSort(int a[],int lb, int ub){
    if(lb<ub){
        int loc = partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }
}

int main(){
    int arr[10] ={1,23,4,45,78,84,12,2};
    quickSort(arr,0,7);
}