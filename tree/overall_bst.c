#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left;
struct node *right;
};
struct node *inOrderPredessor(struct node *root){
    root = root ->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
};
struct node *create(int x){
    struct node *roots = malloc(sizeof(struct node));
    roots->data =x;
    roots->left = NULL;
    roots->right = NULL;
    return roots;
};

struct node *insertion(struct node *root,int x){
    if(root == NULL){
        return create(x);
    }
    if(root == -1){
        return 0;
    }
    else if(root->data > x){
        root->left = insertion(root->left,x);
    }
    else if(root->data < x){
        root->right = insertion(root->right,x);
    }
    return root;
};

struct node *display(struct node *root){
    if(root == NULL){
        return 0;
    }
    root->left = display(root->left);
    printf("%d\t",root->data);
    root->right = display(root->right);
    return root;
};

struct node *delete_node(struct node *root,int el){
if(root == NULL){
    return 0;
}
if(root->left== NULL && root->right== NULL){
   free(root);
   return 0;
   }
if(root->data > el){
    root->left = delete_node(root->left,el);
}
else if(root->data < el){
    root->right = delete_node(root->right,el);
}

else{
    struct node *pred;
    pred = inOrderPredessor(root);
    root->data = pred ->data;
    root->left = delete_node(root->left,el);
}
printf("%d",root);
printf("\t%d",root->left);
};

struct node *isBST(struct node *root){
struct node *ptr = malloc(sizeof(struct node));
ptr=NULL;
if(root != NULL){
    if(!isBST(root->left)){
        return 0;
    }
    if(ptr != NULL && root->data <= ptr->data){
        return 0;
    }
    ptr = root->data;
    return isBST(root->right);
}
else {
    return 1;
}
};
void main(){
    int num,i,x,el;
struct node *root = malloc(sizeof(struct node));
printf("enter the number of elements your want insert");
scanf("%d",&num);
root = NULL;
for(i = 1 ;i<=num;i++){
    printf("\nenter the number you want to insert");
    scanf("%d",&x);
    root =insertion(root,x);
}
display(root);
printf("\n%d",isBST(root));
printf("\nenter the number you want to delete");
scanf("%d",&el);
delete_node(root,el);
display(root);
}
