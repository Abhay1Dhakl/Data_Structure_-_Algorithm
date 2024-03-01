#include<stdio.h>
#include<conio.h>
int top = -1,max,choice,num,stack[100];
void push();
void pop();
void display();
void main()
{
    printf("enter the max size of array");
    scanf("%d",&max);
    do
    {
       printf("\nenter your choice");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
       push();
        break;

        case 2:
        pop();
        break;

        case 3:{
        display();
        break;}

        case 4:
            exit(0);
            break;
       default:
       printf("enter valid number from 1-3");
        break;
       }
    } while (choice != 4);
}

void push(){
    int x;
    if(top >= max -1){
        printf("stack overflow");
    }
    else{
        printf("enter value to be pushed");
        scanf("%d",&num);
        top++;
        stack[top] = num;
    }
}

void pop(){
    int y,nm;
    if(top == -1){
        printf("stack underflow");
    }
    else{
        printf("enter value to be popped");
        scanf("%d",&nm);
        stack[top] = nm;
        top --;
    }
}
void display(){
    int i;
for(i=0;i<=top;i++)
    printf("%d",stack[i]);
}
