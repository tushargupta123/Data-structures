#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    char name[10];
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(char *name){
    struct node *newPatient ;
    newPatient = (struct node *)malloc(sizeof(struct node));
    strcpy(newPatient->name,name);
    newPatient->next = NULL;
    if(front == NULL && rear == NULL){
        front = newPatient;
        rear = newPatient;
    }
    else{
        rear->next = newPatient;
        rear=newPatient;
    }
}

int main(){
    char name[10];
    int t=10;
    while(t--){
    gets(name);
    insert(name);
    }
}