#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
};

void main(){
struct node *first = (struct node *)malloc(sizeof(struct node));
first ->data = 22;
struct node *sec = (struct node*)malloc(sizeof(struct node));
sec ->data= 33;
first->next = sec;
struct node *last = (struct node*)malloc(sizeof(struct node));
last->data = 44;
sec->next = last;
last->next = first;
struct node *ptr = first;

do{

    printf("%d",ptr->data);
    ptr = ptr->next;
}while(ptr != last->next);
}
