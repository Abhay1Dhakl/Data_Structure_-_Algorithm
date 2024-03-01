#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};

struct node *traversal(struct node *first){
struct node *sec = malloc(sizeof(struct node));
struct node *last= malloc(sizeof(struct node));
first->data = 5;
sec->data = 10;
last->data = 15;
first ->next = sec;
sec->next = last;
last ->next = first;
first->prev = last;
sec->prev = first;
last ->prev = sec;
return first;
};

struct node *display(struct node *first){
struct node *p = first;
printf("\n");
do{
    printf("%d\t",p->data);
    p = p->next;
}while(p!=first);

return first;
};

struct node *insertatbegining(struct node *first){
struct node *beg = malloc(sizeof(struct node));
beg ->data = 20;
beg ->next = first;
struct node *ptr = first;
do{
    ptr = ptr->next;
}while(ptr->next!=first);

ptr->next = beg;
beg->prev = ptr;
first = beg;
return first;
};

struct node *insertatend(struct node *first){
struct node *beg = malloc(sizeof(struct node));
beg ->data = 25;
beg ->next = first;
struct node *ptr = first;
do{
    ptr = ptr->next;
}while(ptr->next!=first);

ptr->next = beg;
beg->prev = ptr;
return first;
};

struct node *inserionatbtn(struct node *first, int index){
struct node *btn = malloc(sizeof(struct node));
btn->data = 30;
struct node *ptr = first;
int i=0;
while(i != index - 1){
    ptr = ptr->next;
    i++;
}
btn->prev = ptr;
btn ->next = ptr->next;
ptr->next = btn;
int j=0;
struct node *pt = first;
while(j!=index){
    pt = pt->next;
    j++;
}

pt->prev = btn;
return first;
};

void main(){
struct node *first = malloc(sizeof(struct node));
first = traversal(first);
first = display(first);
first = insertatbegining(first);
first = display(first);
first = insertatend(first);
first = display(first);
int index;
printf("\nenter your position where data is to be inserted");
scanf("%d",&index);
first = inserionatbtn(first,index);
first = display(first);
}
