#include<stdio.h>
#include<stdlib.h>
 struct node{
 int data;
 struct node *left;
 struct node *right;
 };
 struct node *predessor(struct node *root){
 root = root->left;
 while (root->right != NULL){
    root = root->right;
 }
 return root;
 };
struct node *leaf_deletion(struct node *root,int el){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root ->right == NULL){
        free(root);
        return NULL;
    }
    if(root->data > el){
        root->left = leaf_deletion(root->left,el);
    }
    else if(root->data < el){
        root->right = leaf_deletion(root->right,el);
    }
    else {
        struct node *pred = predessor(root);
        root->data = pred->data;
        root->left = leaf_deletion(root->left,pred->data);
    }
    return root;
};
 struct node *create(int num){
   struct node *newnode= malloc(sizeof(struct node));
   newnode->data = num;
   newnode->left = NULL;
   newnode -> right = NULL;
   return newnode;
 };

 struct node *traversal(struct node *root,int num){
    if(root == NULL){
        return create(num);
    }
    if(num == -1){
        return 0;
    }
    else if( num < root->data){
        root->left = traversal(root->left,num);
    }
    else if(num > root->data){
        root->right = traversal(root->right,num);
    }
    return root;
 };

 struct node *display(struct node *root){
    if(root == NULL){
        return;
    }
    root->left = display(root->left);
    printf("%d\t",root->data);
    root->right = display(root->right);
    return root;
 };

 void main(){
         int num,i,x;
         struct node *root = malloc(sizeof(struct node));
         root = NULL;
            root = traversal(root,5);
            traversal(root,3);
            traversal(root,6);
            traversal(root,1);
            traversal(root,4);

         display(root);
         int el;
    printf("\nenter element you want to delete");
    scanf("%d",&el);
    root = leaf_deletion(root,el);
    display(root);
 }
