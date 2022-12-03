// Write a program to form a single linked list by intersection of two linked list without repeating any element.

#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *link;
    int data;
};
struct node* insert(struct node *head,int value){
     struct node *temp;
    struct node *newP = (struct node *)malloc(sizeof(struct node));
    newP->data = value;
    newP->link = NULL;

    if(head == NULL){
        newP->link = head;
        head = newP;
    } else {
        temp = head;
        while(temp->link !=NULL){
        temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

struct node *create(struct node *head){
    int n, i;
    int data;

    printf("Enter the number of terms ");
    scanf("%d",&n);

    for (i=0;i<n;i++){
        printf("Enter the value for term %d: ",i+1);
        scanf("%d",&data);

        head = insert(head,data);
    }
    return head;
};

void print(struct ndoe *head){
    if (head == NULL){
        printf("Nothing to show in list");
    } else {
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d", temp->data);
            temp = temp->link;
            if (temp!=NULL)
            printf(" , ");
            else
            printf("\n");
        }
    }
}

void merger(struct node *head1 , struct node *head2){
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data == ptr2->data){
            head3 = insert(head3,ptr1->data);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->data > ptr2->data){
            head3 = insert(head3,ptr1->data);
            ptr1 = ptr1->link;
        }else if (ptr1->data < ptr2->data){
            head3 = insert(head3, ptr2->data);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3 = insert(head3,ptr1->data);
        ptr1 = ptr1->link;
    }
    while(ptr2!=NULL){
        head3 = insert(head3,ptr2->data);
        ptr2 = ptr2->link;
    }
    printf("Merged list is : ");
    print(head3);
}

int main() {
    struct node *head1 = NULL;
    struct ndoe *head2 = NULL;
    printf("Enter the first list\n");
    head1 = create(head1);
    printf("Enter the second list\n");
    head2 = create(head2);

    merger(head1,head2);
    return 0;
}