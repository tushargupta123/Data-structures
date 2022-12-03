#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

int a[maxsize];
int front=-1, rear=-1;

int isempty(){
    if(front==-1){
    return 1;
    }
    else{
     return 0;
    }
}
int isfull(){
    if(rear==maxsize-1){
     return 1;
    }
    else{
    return 0;
    }
}
void peek(){
    printf("%d",a[front]);
}
void enqueue(int data){
    if(isempty()){
        front++;
        rear++;
        a[rear]=data;
    }
    else if(isfull()!=1){
        rear++;
        a[rear]=data;
    }
    else printf("OverFlow");
}
void dequeue(){
    if(isempty()){
        printf("Underflow\n");
    }
    else if(front>rear) {
        printf("Underflow\n");
    }
    else {
        printf("%d \n",a[front]);
        front++;
    }
}
void display(){
    if(isempty()){
        printf("Underflow\n");
    } else {
        for(int i=front;i<=rear;i++){
            printf("%d ",a[i]);
        }
    } printf("\n");
}
int main(){
    int n,data;
    while(1){
        printf("Press 1 for enqueue\nPress 2 for dequeue\nPress 3 to peek\nPress 4 to exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                scanf("%d",&data);
                enqueue(data);
                display();
                break;
            }
            case 2:{
                dequeue();
                display();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                exit(0);
            }
        }
    }
}
