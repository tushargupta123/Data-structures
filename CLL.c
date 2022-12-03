#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
    struct node
    {
        int item;
        struct node *next;
    };
    struct node *last = NULL;
    void insert_first(int data);
    void insert_last(int data);
    void delete_first();
    void delete_last();
    void insert_AfterElement(int element,int data);
    void delete_element(int element);
    void viewListItems();

void insert_first(int data)
{ 
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->item=data;
    if(last==NULL)
    {
        last=n;
        last->next=last;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void viewListItems()
{
    struct node *temp=last->next;
    while(temp!=last)
    {
        printf("%d ", temp->item);
        temp=temp->next;
    }
    printf("%d",temp->item);
}
void insert_last(int data)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->item =data;
    if(last==NULL)
    {
        last=n;
        last->next=last;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
void delete_first()
{
    if(last==NULL)
    {
        printf("OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!");
    }
    else
    {
        if(last->next==last)
        {
            free(last);
            last=NULL;
        }
        else
        {
            struct node *temp=last->next;
            last->next=last->next->next;
            free(temp);
        }
    }
}
void delete_last()
{
    if(last==NULL)
    {
        printf("OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!");
    }
    else
    {
        if(last->next==last)
        {
            free(last);
            last=NULL;
        }
        else
        {
            struct node *t=last->next;
            while(t->next!=last)
            {
               t=t->next;
            }
            t->next=last->next;
            free(last);
            last=t;

        }
    }
}
void insert_AfterElement(int element,int data)
{
    if(last==NULL)
    {
        printf("OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!");
    }
    else
    {
        struct node *temp=last->next;
        while(temp!=last)
        {
            if(temp->item==element)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp==last)
        {
            if(temp->item==element)
            {
               insert_first(data);
            }
            else
            {
                printf("OPERATION FAILED:ELEMENT NOT FOUND!");
            }
        }
        else
        {
            struct node *n=(struct node *)malloc(sizeof(struct node));
            n->item=data;
            n->next=temp->next;
            temp->next=n;
        }
    }
}
void delete_element(int element)
{
    if(last==NULL)
    {
        printf("OPERATION FAILED:CIRCULAR LINKED LIST IS EMPTY!");
    }
    else
    {
        struct node *t1=last->next,*t2=NULL;
        while(t1!=last)
        {
            if(t1->item==element)
            {
                break;
            }
            t2=t1;
            t1=t1->next;
        }
        if(t1==last)
        {
            if(t1->item==element)
            {
                delete_last();
            }
            else
            {
                printf("OPERATION FAILED:ELEMENT NOT FOUND!");
            }
        }
        else
        {
            if(t2==NULL)
            {
                delete_first();
            }
            else
            {
                t2->next=t1->next;
                free(t1);
            }
        }
    }
}

void replace_last() {
    int data;
    printf("enter the value\n");
    scanf("%d",&data);
    delete_last();
    insert_last(data);
}

int main() {
    int data,n,a,b;
    printf("how many elements you want to insert?\n");
    scanf("%d",&a);
    b=0;
    while(b!=(a+1)){
    printf("\nenter the action you want to perform \n1.insert at first\n2.insert at end\n3.insert at any position\n4.delete first\n5.delete last\n6.delete at any position\n7.display\n8.replace last element.\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            printf("enter the data which you want to insert\n");
            scanf("%d",&data);
            insert_first(data);
            b++;
            break;
        case 2:
            printf("enter the data which you want to insert\n");
            scanf("%d",&data);
            insert_last(data);
            b++;
            break;
        case 3:
            printf("enter the data which you want to insert\n");
            scanf("%d",&data);
            insert_last(data);
            b++;
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            printf("enter the element which you want to delete\n");
            scanf("%d",data);
            delete_element(data);
            break;
        case 7:
            viewListItems();
            break;
        case 8:
            replace_last();
            break;
        default: exit(0);
    }
    }
    return 0;
}