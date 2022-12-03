// Write a C program to find the frequency of each elements in a doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
    struct node
    {
        int item;
        struct node *prev;
        struct node *next;
    };
    struct node *start=NULL;
    void delete_second(int element);
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
        printf("OPERATION FAILED:ELEMENT NOT FOUND!");
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
void frequency()
{
    int count=1,x,flag=0;
    struct node *t1=start,*t2;
    for(;t1!=NULL;)
    {
        x=t1->item;
        t2=t1->next;
        for(count=1;t2!=NULL;) 
        {
            if(x==t2->item)
            {
                count++;
                flag=1;
            }
            if(flag==1)
            {
                delete_second(x);
                flag=0;
            }
            t2=t2->next;
        }
        printf("%d-%d\n",x,count);
        t1=t1->next;
    }
}
void delete_second(int element)
{
    int c=0;
    struct node *t1=start,*t2=NULL;
    while(t1)
    {
        if(t1->item==element)
        {
            c++;
            if(c==2)
            {
                break;
            }
        }
        t2=t1;
        t1=t1->next;
    }
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
int main()
{
    int data,element;
    while(1)
    {
        system("cls");
       viewListItems();
       switch(menu())
       {
       case 1:
        printf("Enter data to insert at first:");
        scanf("%d",&data);
        insert_first(data);
        break;
       case 2:
        printf("Enter data to insert after a element:");
        scanf("%d",&data);
        printf("Enter element to after it:");
        scanf("%d",&element);
        insert_afterElement(element,data);
        break;
       case 3:
        printf("Enter data to insert at last:");
        scanf("%d",&data);
        insert_last(data);
        break;
        case 4:
        delete_first();
        break;
       case 5:
        printf("Enter element to delete:");
        scanf("%d",&element);
        delete_element(element);
        break;
       case 6:
        delete_last();
        break;
       case 7:
        frequency();
        break;
       case 8:
        exit(0);
       default:
        printf("INVALID CHOICE!!");
       }
       getch();
    }
    return 0;
}
int menu()
{
    int choice;
    printf("1.Insert at first\n");
    printf("2.Insert after the element\n");
    printf("3.Insert at last\n");
    printf("4.Delete first\n");
    printf("5.Delete the element\n");
    printf("6.Delete last\n");
    printf("7.Frequency\n");
    printf("8.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}