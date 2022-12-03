#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

char stack[20];
int top=-1;
void push(char c){
    if(top == 19)
    printf("stack overflow");
    else{
        stack[++top]=c;
    }
}

char pop(){
    if(top==-1)
    printf("stack underflow");
    else
    return(stack[top--]);
}
int main(){
    int flag=1;
    char exp[20],temp;
    gets(exp);
    for (int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        push(exp[i]);
    if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
    if(top==-1)
    flag=0;
    else{
        temp==pop();
        if(exp[i]==')' && (exp[i]=='{')||exp[i]=='[')
        flag=0;
        if(exp[i]=='}' && (exp[i]=='(')||exp[i]=='[')
        flag=0;
        if(exp[i]==']' && (exp[i]=='{')||exp[i]=='(')
        flag=0;
    }
    }
    if (top>=0)
    flag=0;
    if(flag==1)
    printf("valid expression");
    else
    printf("invalid expression");
}

