#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i< n; i++ ){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubbleSort(int* A, int n){
    int temp;
    for (int i = 0; i<n; i++){
        for (int j=0; j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

void binarySearch(int arr[],int size, int element){
    int low = 0;
    int high = size - 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }if(arr[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

void insertionSort(int arr[],int size){
    int key,j;
    for (int i=0;i<size;i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merge(int arr[],int mid, int low , int high){
    int i,j,k,B[190];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k]=arr[i];
            i++;
            k++;
        }else{
            B[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=arr[i];
        i++;
        k++;
    }while(j<=high){
        B[k]=arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,mid,low,high);
    }
}

void selectionSort(int arr[],int size){
    int indexOfMin,temp;
    for (int i=0;i<size;i++){
        indexOfMin = i;
        for (int j =i+1; j<size; j++){
            if(arr[j]<arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp=arr[i];
        arr[i]=arr[indexOfMin];
        arr[indexOfMin]=temp;
    }
}