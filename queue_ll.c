#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL;
node *rear=NULL;

int isempty(){
    if(front==NULL) return 1;
    else return 0;
}
void enqueue(int d){
    node * newnode=NULL;
    newnode=(node *)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=d;
    if(front==NULL&&rear==NULL){
        rear=newnode;
        front=newnode;
    }
    else {
        rear->next=newnode;
        rear=newnode;
    }
}
void peek(){
    printf("%d\n",front->data);
}
void dequeue(){
    node *temp=NULL;
    temp=front;
    if(front==NULL) printf("UNDERFLOW\n");
    else{
        printf("%d\n",front->data);
        front=temp->next;
        free(temp);
    }
}
void display() {
    struct node *temp;
    if(front==NULL){
        printf("queue is empty");
    }else {
        temp=front;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    int n,d;
    while(1){
        printf("Press 1 to enqueue\nPress 2 to Dequeue\nPress 3 to Peek\nPress 4 to exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                scanf("%d",&d);
                enqueue(d);
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
