#include<stdio.h>
Stack()
{
    top=NULL;
}
bool isEmpty()
{
    return top==NULL;
}
void push(int data)
{
    node *n=new node;
    n->item=data;
    if(top==NULL)
    {
        top=n;
        n->next=NULL;
    }
    else
    {
        n->next=top;
        top=n;
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("OPERATION FAILED:STACK UNDERFLOW!\n");
    }
    else
    {
        node *temp=top;
        if(temp->next==NULL)
        {
            top=NULL;
            free(temp);
        }
        else
        {
            top=top->next;
            free(temp);
        }
    }
}
int peek()
{
    if(!isEmpty())
    {
        return top->item;
    }
}