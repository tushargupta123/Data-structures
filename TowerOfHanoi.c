#include<stdio.h>
void move(int n, char source, char spare, char dest);
int main(){
    int n;
    move(3,'A','B','C');
    return 0;
}
void move(int n, char source, char spare, char dest){
    if(n==1){
        printf("Move %c to %c\n", source,dest);
    } else{
        move(n-1,source,dest,spare);
        move(1,source,spare,dest);
        move(n-1,spare,source,dest);
    }
}