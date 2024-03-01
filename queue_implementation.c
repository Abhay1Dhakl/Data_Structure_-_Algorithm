#include<stdio.h>
#include<stdlib.h>
void enqueue(int a[]);
void dequeue(int a[]);
#define MAX_SIZE 5
int front=-1,rear=-1;
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
printf("do you want continue? 'y'");
    scanf(" %c",&ans1);
}while(ans1=='y');
}
enqueue(int a[]){
int n,ans;
do{
        if(rear<MAX_SIZE-1){
    printf("\nenter your element to be inserted");
    scanf("%d",&n);
    rear++;
    a[rear] = n;
    printf("do you want to add more if yes then press 'y'");
    scanf(" %c",&ans);
}
else{
    printf("\nstacloverflow");
    return;
}
}while(ans=='y');
 for(int j=0;j<=rear;j++){
        printf("%d",a[j]);
    }
    return;
}

dequeue(int a[5]){
   // printf("hello");
int ans2,n1;
front=0;
do{
    n1 = a[front];
     front++;
     printf("do you want to add more if yes then press 'y'");
    scanf(" %c",&ans2);

}while(ans2=='y');
for(int j=front;j<=rear;j++){
        printf("%d",a[j]);
    }
}
