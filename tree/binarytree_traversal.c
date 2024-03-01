#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *first;
struct node *second;
};

struct node *treetraversal(){
    struct node *newnode = malloc(sizeof(struct node));
    int x;
    printf("enter the data you want to insert in newnode(enter -1 to return null)");
    scanf("%d",&x);
    if(x == -1){
        return 0;
    }
    newnode->data = x;
    printf("\nenter data for left part");
    newnode->first =treetraversal(newnode->first);
    printf("\nenter data for right part");
    newnode->second=treetraversal(newnode->second);
    return newnode;
};
//preorder traversal
struct node *display(struct node *root){
   if(root == NULL){
    return ;
   }
   printf("\n%d",root->data);
   display(root->first);
   display(root->second);
   return root;
};
//postorder traversal
struct node *display1(struct node *root){
if(root == NULL){
    return ;
}
display1(root->first);
display1(root->second);
printf("\n%d",root->data);
return root;
};

struct node display2(struct node *root){

if(root == NULL){
    return;
}
display2(root->first);
printf("\n%d",root->data);
display2(root->second);

};
void main(){
struct node *root = malloc(sizeof(struct node));
root = 0;
root = treetraversal();
display(root);
printf("\npostorder");
display1(root);
printf("\ninorder");
display2(root);
/*
     4
    / \
   1   6
  / \
 5   2
*/
}
