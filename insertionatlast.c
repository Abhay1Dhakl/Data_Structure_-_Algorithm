#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* traversal(struct node* first){
first->data = 15;
struct node *sec = (struct node *) malloc(sizeof(struct node));
sec->data = 55;
first->next = sec;
struct node *last= (struct node *) malloc(sizeof(struct node));
last->data = 35;
sec->next=last;
last->next=NULL;
return first;
}

struct node *lastins(struct node *first,int a){
struct node *p = first;
while(p->next != NULL){
    p = p->next;
}
struct node *addi = (struct node *) malloc(sizeof(struct node));
addi->data = a;
addi->next = NULL;
p->next = addi;
return first;
}

void main(){
struct node *first = (struct node *) malloc(sizeof(struct node));
first = traversal(first);
struct node *ptr = first;
while(ptr!=NULL){
    printf("%d\t",ptr->data);
    ptr = ptr->next;
}
int a = 25;
first = lastins(first,a);
struct node *pt = first;
while(pt!=NULL){
    printf("\n%d\t",pt->data);
    pt = pt->next;
}
}
