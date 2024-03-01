#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
};

int max(int a,int b){
    return (a>b)?a:b ;
}

int height (struct node *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int balanced_factor(struct node *root){
return height(root->left)-height(root->right);
}

struct node *create(int el){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = el;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
};

struct node *left_rotation(struct node *root){
struct node *x = root->right;
struct node *x1 = x->left;
root->right = x1;
x->left = root;
root->height = 1+max(height(root->left),height(root->right));
x->height = 1+max(height(x->left),height(x->right));
return x;
};

struct node *right_rotation(struct node *root){
struct node *x = root->left;
struct node *x1 = x->right;
root->left = x1;
x->right = root;
root->height = 1+max(height(root->left),height(root->right));
x->height = 1+max(height(x->left),height(x->right));
return x;
};

struct node *insertion(struct node *root , int el){
if(root==NULL){
    return create(el);
}
if(el < root->data){
    root->left = insertion(root->left,el);
}
else if(el > root->data){
    root->right = insertion(root->right,el);
}
else {
    return root;
}
root->height = 1 + max(height(root->left),height(root->right));
int bf = balanced_factor(root);
if(bf > 1 && el > root->left->data){
    return right_rotation(root);
}
if(bf > 1 && el < root->left->data){
    root->left = left_rotation(root->left);
    return right_rotation(root);
}
if(bf < -1 && el > root->right->data){
    return left_rotation(root);
}
if(bf < -1 && el < root->right ->data){
    root->right = right_rotation(root->right);
    return right_rotation(root);
}
return root;
};

struct node *display(struct node *root){
if(root == NULL){
    return 0;
}
root->left = display (root->left);
printf("%d",root->data);
root->right = display(root->right);
return root;
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
}
