#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};

struct node *traversal(struct node *first){
first->data = 15;
first->prev = NULL;
struct node *sec = (struct node*)malloc (sizeof(struct node));
sec->data = 28;
sec->prev = first;
first->next = sec;
struct node *last= (struct node*)malloc (sizeof(struct node));
last->data = 25;
last->next = NULL;
last->prev = sec;
sec ->next = last;
return first;
};

struct node *display(struct node *first){
struct node *ptr = first;
printf("\n");
while(ptr!= NULL){
    printf("%d\t",ptr->data);
    ptr = ptr->next;
}
return first;
};

struct node* insertatbegining1(struct node* first){
struct node* b = malloc(sizeof (struct node));
b->prev = NULL;
b->data = 10;
b->next = first;
first->prev = b;
first = b;
return first;
}

struct node *insertatend(struct node *first){
struct node *end = (struct node*)malloc (sizeof(struct node));
struct node *ptr = first;
while(ptr->next != NULL){
    ptr = ptr->next;
}
end->data = 44;
ptr ->next = end;
end->prev = ptr;
end->next = NULL;
return first;
};

struct node *insetionatbtn(struct node *first,int index){
struct node *pt = malloc(sizeof(struct node));
struct node *t = first;
int i = 0 ;
while(i != index - 1)
{
    t = t->next;
    i++;
}
pt->data = 66;
pt->next = t ->next;
t->next = pt;
pt->prev = t;
struct node *q = first;
int j = 0;
while(j != index){
    q = q->next;
    j++;
}
q->prev = pt;
return first;
};

void main(){
struct node *first = (struct node*)malloc (sizeof(struct node));
first = traversal(first);
first = display(first);
first = insertatbegining1(first);
first = display(first);
first = insertatend(first);
first = display(first);
int index;
printf("\nenter your position where data is to be inserted");
scanf("%d",&index);
first = insetionatbtn(first,index);
first = display(first);
}
