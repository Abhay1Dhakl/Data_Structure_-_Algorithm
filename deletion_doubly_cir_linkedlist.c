#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};

struct node *traversal(struct node *first){
first->data = 5;
struct node *sec = malloc(sizeof(struct node));
struct node *third= malloc(sizeof(struct node));
struct node *fourth= malloc(sizeof(struct node));
struct node *last= malloc(sizeof(struct node));
first->next = sec;
first->prev = last;
sec->data = 10;
third->data=15;
sec->next=third;
sec->prev = first;
third->next=fourth;
fourth->data = 20;
fourth ->prev = sec;
fourth->next = last;
last->data = 25;
last->prev = fourth;
last->next = first;
return first;
};

struct node *del_at_first(struct node *first){
struct node *temp = first;
struct node *ptr = first;
do{
    ptr = ptr->next;
}while(ptr->next != first);
printf("\nthe number to be deleted is %d",temp->data);
ptr->next = temp->next;
struct node *ptr1 = first->next;
ptr1->prev= ptr;
first = ptr1;
free(temp);
return first;
};

struct node *del_at_last(struct node *first){
struct node *ptr1 = first;
struct node *ptr2 = first->next;
do{
    ptr2 = ptr2->next;
    ptr1 = ptr1->next;
}while(ptr2->next != first);
printf("\nthe number to be deleted is %d",ptr2->data);
ptr1->next= first;
first->prev= ptr1;
free(ptr2);
return first;
};

struct node *del_at_btn(struct node *first,int index){
   struct node *ptr1 = first;
   struct node *ptr2 = first;

    int i = 0;
    while( i!=index -1){
        ptr1=ptr1->next;
        i++;
    }
    int j = 0;
        while( j!=index -2){
        ptr2=ptr2->next;
        j++;
    }
    struct node *ptr3 = ptr1->next;
    ptr2->next = ptr3;
    ptr3->prev = ptr2;
  printf("\nthe number to be deleted is %d",ptr1->data);
   free(ptr1);
   return first;
};

struct node *display(struct node *first){
struct node *ptr =  first;
do{
    printf("\n");
    printf("%d\t",ptr->data);
    ptr = ptr->next;
}while(ptr!=first);
return first;
};

void main(){
struct node *first = malloc(sizeof(struct node));
first = traversal(first);
first = display(first);
first = del_at_first(first);
first = display(first);
int index;
printf("\nenter the position from where data is to be deleted");
scanf("%d",&index);
first = del_at_btn(first,index);
first = display(first);
first = del_at_last(first);
first = display(first);
}

