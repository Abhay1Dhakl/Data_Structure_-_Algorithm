#include<stdio.h>
#define MAX 5
int top=-1, stack[MAX];
void push();
void pop();
void display();
void main()
{
    int choice;
    while(1){
    printf("\nenter your choice");
    printf("\nenter 1 for push\nenter 2 for pop\nenter 3 for display\nenter 4 to exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        break;
        default: printf(" Sorry entered choice is invalid..........");
    }
}
}
void push()
{
int num;
if(top==MAX-1)
    {
        printf("\nStack is full..............");
        //return 0;
    }
    else
    {
        printf("\nenter element to push");
        scanf("%d",&num);
        top=top+1;
        stack[top]=num;
        //return 0;
    }
}
void pop()
{
    int num;
    printf("\nenter the number you want to delete..");
    if(top=-1)
    {
        printf("\nstack is full");
        //return 0;
    }
    else
    {
        num=stack[top];
        top=top-1;
        //return 0;
    }
}
void display()
{
    int i;
    for(i=MAX;i>;i++)
    {
        printf("%d",stack[i]);
    }
    return 0;
}


