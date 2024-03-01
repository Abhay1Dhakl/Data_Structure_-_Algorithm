#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
int height;
struct node *left;
struct node *right;
};

int max(int a , int b){
return (a > b)? a : b;
}

int height(struct node *root){
if(root == NULL){
    return 0;
}
return root->height;
}

struct node *create(int el){
struct node *new_node = malloc(sizeof(struct node));
new_node->data = el;
new_node->height = 1;
new_node->left = NULL;
new_node->right = NULL;
return new_node;
};

int balance_facotr(struct node *root){
if(root == NULL){
    return 0;
}
return height(root->left) - height(root->right);
};

struct node *right_rotation(struct node *root){
struct node *x = root->left;
struct node *x1 = x->right;
x->right = root;
root->left = x1;
root->height = 1 +max(height(root->left),height(root->right));
x->height =1 + max(height(x->left),height(x->right));
return x;
};

struct node *left_rotation(struct node *root){
struct node *x = root->right;
struct node *x1 = x->left;
x->left = root;
root->right= x1;
root->height = 1 + max(height(root->left),height(root->right));
x->height = 1 + max(height(root->left),height(root->right));
return x;
};

struct node *insertion(struct node *root,int el){
if(root == NULL){
    return create(el);
}

if(el < root->data){
    root->left = insertion(root->left,el);
}

else if(el >root->data){
    root->right = insertion(root->right,el);
}

else {
    return root;
}

root->height = 1 + max(height(root->left),height(root->right));
int bf = balance_facotr(root);
if(bf > 1 && el < root->left->data){
    return right_rotation(root);
}

else if(bf > 1 && el > root->left->data){
    root->right = left_rotation(root->right);
    return right_rotation(root);
}

else if (bf < -1 && el > root->right->data){
    return left_rotation(root);
}

else if (bf < -1 && el < root->right ->data){
    root->right = right_rotation(root->right);
    return left_rotation(root);
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
