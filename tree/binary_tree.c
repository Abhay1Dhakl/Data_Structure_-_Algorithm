#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *first;
struct node *second;
};

struct node *treetraversal(){
struct node *newnode= malloc(sizeof(struct node));
int x;
printf("enter your data to be inserted in newnode(select -1 if you do not want a newnode)");
scanf("%d",&x);
if(x == -1){
    return 0;
}
newnode->data=x;
printf("enter data in your lest tree");
newnode->first=treetraversal();
printf("enter data in your second part of tree");
newnode->second = treetraversal();
return newnode;
};

struct node *display(struct node *root){
    if(root == NULL){
        return ;
    }
    printf("%d",root->data);
display(root->first);
display(root->second);
};

void main(){
struct node *root = malloc(sizeof(struct node));
root = 0;
root = treetraversal();
root = display(root);
}
