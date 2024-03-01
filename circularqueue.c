#include<stdio.h>
#define MAX_SIZE 5
void enqueue(int a[]);
void dequeue(int a[]);
int front = -1,rear = -1;
void main(){
int x,a[MAX_SIZE],ans1;

do{
printf("choose 1 for push and 2 for pop");
scanf("%d",&x);
switch(x){
case 1:
    enqueue(a);
    break;

case 2:
    dequeue(a);
    break;
}
printf("\ndo you want continue? 'y'");
    scanf(" %c",&ans1);
}while(ans1=='y');
}
enqueue(int a[]){
int ans,n;
do{
    if((front==0 && rear==MAX_SIZE-1 )||(front == rear+1)){
        printf("Stack Overflow");
        return;
    }
    else{
            if(front==-1){
                front++;
            }
            printf("\nenter your number to be inserted");
    scanf("%d",&n);
        rear++;
    int temp = rear%MAX_SIZE;
    a[temp]=n;
    }
    printf("\ndo you want to cintinue?? select y for yes");
    scanf(" %c",&ans);
}while(ans=='y');
for(int i = 0 ;i<=rear;i++)
{
    printf("%d",a[i]);
}
}

dequeue(int a[]){
    int ans2;
    printf("hello");
do{
    if(front == -1){
        printf("\nstackunderflow");
        return;
    }
    else {
        printf("\nthe deleted item is %d",a[front]);
        if(front==rear){
        front = rear = -1;
    }
    else{
        front = front+1 % MAX_SIZE;
    }}

    printf("\ndo you want do delete more? select y if yes");
    scanf(" %c",&ans2);
}while(ans2=='y');
for(int i=front;i<=rear;i++){
    printf("%d",a[i]);
}
}
