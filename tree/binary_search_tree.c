#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *left;
struct node *right;
};

struct node *create(int y){
struct node *newnode = malloc(sizeof(struct node));
    newnode->data = y;
    newnode->left=NULL;
    newnode->right=NULL;
return newnode;
};

struct node *insertion(struct node *root,int x){

if(root == NULL){
   return create(x);
}

if(x == -1){
    return ;
}

if(x < root->data){
        printf("\nleft part inserted");
    root->left = insertion(root->left,x);
}
else if(x>root->data){
    printf("\nright part inserted");
    root->right=insertion(root->right,x);
}
return root;
};

struct node *display(struct node *root){
if(root == NULL){
    return ;
}

display(root->left);
printf("\n%d",root->data);
display(root->right);
return root;
};

struct node *isBST(struct node *root){
struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
};
void main(){
struct node *root = malloc(sizeof(struct node));
int x,n;
root = NULL;
printf("entr how much data you want to insert");
scanf("%d",&n);
for(int i = 0 ; i< n ;i++){
printf("\nenter the value of your node");
printf("\nif value will be -1 then node will be null");
scanf("%d",&x);
root = insertion(root,x);
}
display(root);
printf("\n%d",isBST(root));
}
