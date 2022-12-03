#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

    struct node
    {
        int item;
        struct node *next;
    };
   struct node *start =NULL;
    
    void insert_first(int data)
    {
           struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->item=data;
            temp->next=start;
            start=temp;
    }
    void insert_after(int element,int data)
    {
        struct node *temp1=start;
        for(; temp1!=NULL;)
        {
            if(temp1->item==element)
            {
                break;
            }
            temp1=temp1->next;
        }
        if(temp1==NULL)
        {
            printf("OPERATION FAILED: ELEMENT NOT FOUND!");
            return;
        }
       struct node *temp2=(struct node *)malloc(sizeof(struct node));
        temp2->item=data;
        temp2->next=temp1->next;
        temp1->next=temp2;
    }
    void insert_last(int data)
    {
        if(start==NULL)
        {
            start=(struct node *)malloc(sizeof(struct node));
            start->item=data;
            start->next=NULL;
        }
        else
        {
            struct node *temp=start;
            for(; temp->next!=NULL;)
            {
                temp=temp->next;
            }
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp->next->item=data;
            temp->next->next=NULL;
        }
    }
    void view_list_items()
    {
        if(start==NULL)
        {
            printf("OPERATION FAILED: LINKED LIST IS EMPTY");
            return;
        }
        for(struct node *temp=start; temp!=NULL;)
        {
            printf("%d ",temp->item);
            temp=temp->next;
        }
        printf("\n");
    }
    void delete_first()
    {
        if(start==NULL)
        {
            printf("OPERATION FAILED: LINKED LIST IS EMPTY!");
        }
        else
        {
            struct node *temp=start->next;
            free(start);
            start=temp;
        }
    }
    void delete_last()
    {
        if(start==NULL)
        {
            printf("OPERATION FAILED: LINKED LIST IS EMPTY!");
        }
        else
        {
            if(start->next==NULL)
            {
                free(start);
                start=NULL;
            }
            else
            {
                struct node *temp=start;
                for(; temp->next->next!=NULL;)
                {
                   temp=temp->next;
                }
                free(temp->next);
                temp->next=NULL;
            }
        }
    }
    void delete_element(int element)
    {
        if(start==NULL)
        {
            printf("OPERATION FAILED: LINKED LIST IS EMPTY!");
        }
        else
        {
           struct node *temp1=start,*temp2=NULL;
            for(;temp1!=NULL;)
            {
                if(temp1->item==element)
                {
                    break;
                }
                temp2=temp1;
                temp1=temp1->next;
            }
            if(temp1==NULL)
            {
                printf("OPERATION FAILED: ELEMENT NOT FOUND!");
                return;
            }
            else
            {
                if(temp2==NULL)
                start=temp1->next;
                else
                temp2->next=temp1->next;
                free(temp1);
            }
        }
    }
int menu();
int main()
{
    int data,element;
    while(1)
    {
       system("cls");
       view_list_items();
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
        insert_after(element,data);
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
        printf("Enter the element to delete:");
        scanf("%d",&element);
        delete_element(element);
        break;
       case 6:
        delete_last();
        break;
       case 7:
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
    printf("1.Insert at first");
    printf("2.Insert after the element");
    printf("3.Insert at last");
    printf("4.Delete first");
    printf("5.Delete element");
    printf("6.Delete last");
    printf("7.Exit");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}
