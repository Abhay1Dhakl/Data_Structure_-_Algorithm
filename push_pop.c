#include<stdio.h>
void push(int a[]);
void pop(int a[]);
int top = -1;
void main(){
int x,a[5];
printf("choose 1 for push and 2 for pop");
scanf("%d",&x);

switch(x){
case 1:

    push(a);

case 2:
    pop(a);
}
}
 push(int a[5]){
     int ans,i;
     //int top = -1;

     do{

    int n;
if(top<5){
    printf("\nenter a number to be inserted");
    scanf("%d",&n);
    top = top+1;
    a[top] = n;
    printf("do you want to add more if yes then press 'y'");
    scanf(" %c",&ans);}
    else{
        printf("stack full");
     }
     }while(ans!='n');

    for(i=0;i<=top;i++){
        printf("%d",a[i]);
    }
}
pop(int a[5]){
    int ans,n,i;
    if(top<0){
        printf("stack underflow");
    }
    else{
        do{
            top--;
            printf("\ndo you want to delete more press'y' is yes");
            scanf(" %c",&ans);
        }while(ans == 'y');
        for(i = 0;i<=top;i++){
             printf("%d",a[i]);
        }
    }
}
