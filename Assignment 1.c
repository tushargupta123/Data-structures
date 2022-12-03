#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void bubble_sort(int *arr){
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            int temp;
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int main(){
    int arr[10];
    int max=0;
    int second_max=0;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){ 
        arr[i]=rand()%50;
        fflush(stdin);
    }
    printf("\n");
    bubble_sort(arr);
    second_max=arr[8];
    printf("Second Max value: %d \n",second_max);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}