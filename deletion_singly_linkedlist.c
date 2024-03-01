#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
};

struct node *traversal(struct node *first){
first->data = 5;
struct node *sec = malloc(sizeof(struct node));
struct node *third= malloc(sizeof(struct node));
struct node *fourth= malloc(sizeof(struct node));
struct node *last= malloc(sizeof(struct node));
first->next = sec;
sec->data = 10;
third->data=15;
sec->next=third;
third->next=fourth;
fourth->data = 20;
fourth->next = last;
last->data = 25;
last->next = NULL;
return first;
};

struct node *del_at_first(struct node *first){
struct node *temp = first;
printf("\nthe data to be deleted is %d",temp->data);
first = first->next;
free(temp);
return first;
};

struct node *del_at_last(struct node *first){
    struct node *ptr = first;
    struct node *pt = first->next;
    while(pt->next!=NULL){
        pt =pt->next;
        ptr=ptr->next;
    }
    printf("\nthe deleted item is %d",pt->data);
    ptr->next = NULL;
    free(pt);
    return first;
};

struct node *del_at_btn(struct node *first,int index){
    struct node *ptr = first;
    int i = 0;
    while(i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    printf("the data to be deleted is %d",ptr->data);
    first->next =ptr->next;
    free(ptr);
    return first;
};

struct node *display(struct node *first){
struct node *ptr =  first;
while(ptr!=NULL){
        printf("\n");
    printf("%d\t",ptr->data);
    ptr = ptr->next;
}
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


