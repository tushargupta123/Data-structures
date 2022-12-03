#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
    struct node
    {
        int item;
        struct node *prev;
        struct node *next;
    };
    struct node *start;
    void insert_first(int data);
    void insert_last(int data);
    void insert_afterElement(int element,int data);
    void viewListItems();
    void delete_first();
    void delete_last();
    void delete_element(int element);

void insert_first(int data)
{
    struct node temp=(struct node)malloc(sizeof(struct node));
    temp->item=data;
    temp->prev=NULL;
    temp->next=start;
    if(start!=NULL)
    {
        start->prev=temp;
    }
        start=temp;
}
void viewListItems()
{
    struct node *temp=start;
    while(temp)
    {
        printf("%d ",temp->item);
        temp=temp->next;
    }
    printf("\n");
}
void insert_last(int data)
{
    struct node temp=(struct node)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        start->prev=NULL;
    }
    else
    {
        struct node *n=start;
        while(n->next)
        {
            n=n->next;
        }
        n->next=temp;
        temp->prev=n;
    }
}
void insert_afterElement(int element,int data)
{
    struct node *temp=start;
    while(temp)
    {
        if(temp->item==element)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("OPERATION FAILED:ELEMENT NOT FOUND!\n");
    }
    else
    {
        struct node n=(struct node)malloc(sizeof(struct node));
        n->item=data;
        n->next=temp->next;
        n->prev=temp;
        if(temp->next)
        {
            temp->next->prev=n;
        }
        temp->next=n;
    }
}
void delete_first()
{
    if(start==NULL)
    {
        printf("OPERATION FAILED:DOUBLY LINKED LIST IS EMPTY!\n");
    }
    else
    {
        struct node *temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
    }
}
void delete_last()
{
    if(start==NULL)
    {
        printf("OPERATION FAILED:DOUBLY LINKED LIST IS EMPTY!\n");
    }
    else
    {
        struct node *t1,*t2;
        t1=start;
        t2=NULL;
        while(t1->next)
        {
            t2=t1;
            t1=t1->next;
        }
        if(t2==NULL)
        {
            start=NULL;
            free(t1);
        }
        else
        {
            free(t1);
            t2->next=NULL;
        }
    }
}
void delete_element(int element)
{
    struct node *t1=start,*t2=NULL;
    while(t1)
    {
        if(t1->item==element)
        {
            break;
        }
        t2=t1;
        t1=t1->next;
    }
    if(t1==NULL)
    {
        printf("OPERATION FAILED:ELEMENT NOT FLOUND!\n");
    }
    else
    {
        if(t2==NULL)
        {
            start=t1->next;
        }
        else
        {
            t2->next=t1->next;
            if(t1->next!=NULL)
            t1->next->prev=t2;
        }
        free(t1);
    }
}

void frequency(){
    
}

int main()
{
    start=NULL;
    insert_first(20);
    insert_first(70);
    insert_first(10);
    delete_first();
    viewListItems();

}

