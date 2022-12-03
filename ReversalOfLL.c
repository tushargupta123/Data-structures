#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node reversed();
struct node *head=NULL;
int main(){
    reversed();
}
struct node reversed() {
    struct node *t1=NULL,*t2=NULL;
    while(head!=NULL){
        t2=head->next;
        head->next=t1;
        t1=head;
        head=t2;
    }
    return(t1);
}