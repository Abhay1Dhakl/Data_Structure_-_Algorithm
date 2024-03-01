#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *traversal(struct node *first){
    first->data = 19;
    struct node *sec = (struct node*)malloc (sizeof(struct node));
    sec->data = 20;
    first->next = sec;
    struct node *last = (struct node*)malloc (sizeof(struct node));
    last->data=21;
    sec->next = last;
    last->next = first;
    return first;
};

struct node *insertatbegining(struct node *first){
 struct node *add = (struct node*)malloc (sizeof(struct node));
 add ->data = 22;
 add->next = first;
 struct node *p = first;
 do{
    p = p->next;
 }while(p->next!=first);
 first = add;
 p->next = first;
 return first;
};

struct node *insertatend(struct node *first){
 struct node *add = (struct node*)malloc (sizeof(struct node));
 add ->data = 33;
 add->next = first;
 struct node *p = first;
 do{
    p = p->next;
 }while(p->next!=first);

 p->next = add;
 return first;

};

struct node *insertatbetn(struct node *first,int index){
    struct node *btn = (struct node*)malloc (sizeof(struct node));
    btn->data= 55;
    struct node *pr = first;
    int i = 0;
    while (i != index - 1){
        pr = pr->next;
        i++;
    }
    btn ->next = pr->next;
    pr->next = btn;
    return first;
};


struct node *display(struct node *first){
struct node *ptr = first;
    printf("\n");
    do{

        printf("%d\t",ptr->data);
        ptr = ptr ->next;
    }while(ptr != first);
};

void main(){
struct node *first = (struct node*)malloc (sizeof(struct node));
first = traversal(first);
first = display(first);
first = insertatbegining(first);
first = display(first);
first =insertatend(first);
first = display(first);
int index;
printf("\nenter your index");
scanf("%d",&index);
first =insertatbetn(first,index);
first = display(first);
}
