#include<stdio.h>

int binarySearch(int arr[], int size , int element){
    int low, mid, high;
    low = 0;
    high = size -1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]== element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }else {
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,6,93,3933,3938,393,933,933,86754};
    int size = sizeof(arr)/sizeof(int);
    int element = 93;
    int searchIndex = binarySearch(arr, size, element);
    printf("the element %d was found at index at %d \n", element, searchIndex);
    return 0;
}