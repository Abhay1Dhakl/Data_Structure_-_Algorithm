#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node* insertion(struct node* first,int a){
struct node *ins = (struct node*)malloc(sizeof(struct node));
 ins->data = 12;
ins->next = first;
first = ins;
return first;
}
struct node *inbetn(struct node * first,int a,int index){
struct node *betn = (struct node *)malloc(sizeof(struct node));
struct node *b = first;
int i = 0;
while(i != index - 1){
    b = b->next;
    i++;
}
betn->data = a;
betn->next = b->next;
b->next = betn;
return first;
}

void main(){
struct node *first= (struct node*)malloc(sizeof(struct node));
first->data = 55;
first->next = NULL;
struct node *second= (struct node*)malloc(sizeof(struct node));
second->data = 85;
second->next = NULL;
first->next = second;
struct node *third= (struct node*)malloc(sizeof(struct node));
third->data = 95;
third->next = NULL;
second->next = third;

/*int d = 33;
first=insertion(first,d);
third=first ;
while(third != NULL){
    printf("%d\t",third->data);
    third = third->next;
}*/
int index;
printf("enter your position to insert");
scanf("%d",&index);
int a = 15;
first=inbetn(first, a, index);
third=first ;
while(third != NULL){
    printf("%d\t",third->data);
    third = third->next;
}
}


