#include <stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
};

void preorder(struct node *root) {
    if(root!=NULL) {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if(root!=NULL) {
        preorder(root->left);
        preorder(root->right);
        printf("%d",root->data);
    }
}

void inorder(struct node *root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else{
        return 1;
    }
}

struct node *search(struct node *root, int key){
    if(root==NULL){
        return NULL; 
    }
    if(key==root->data){
        return root;
    }else if(key < root->data){
        return search(root->left, key);
    }else if(key > root->data){
        return search(root->right, key);
    }
}

struct node *searchIter(struct node *root, int key){
    while(root!=NULL){
    if(key == root->data){
        return root;
    }else if(key < root->data){
        root = root->left;
    }else if(key > root->data){
        root = root->right;
    }
    }
    return NULL;
}

void insert(struct node *root, int key){
    struct node *prev =NULL;
    while(root!=NULL){
        prev = root;
        if(key == root-> data){
            printf("Cannot insert %d , as it is already in Tree\n", key);
            return;
        }else if(key < root->data){
            root = root->left;
        } else if (key > root->data){
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if(key < prev->data){
        prev->left = new;
    } else {
        prev->right = new;
    }
}

struct node * inorderpredecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node * deleteNode(struct node *root,int value){
    struct node *ipre=NULL;
    if(root==NULL) return NULL;
    if(root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }
    else{
        ipre=inorderpredecessor(root);
        root->data=ipre->data;
       root->left=deleteNode(root->left,ipre->data);
    }
}

int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 7);
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    if(isBST(p)){
        printf("tree is a Binary search tree");
    }else {
        printf("tree is not a Binary search tree");
    }
    printf("\n");
    
    struct node *n = search(p, 7);
    if(n!=NULL){
        printf("Found");
    }else {
        printf("Not Found");
    }
    printf("\n");
    struct node *n1 = searchIter(p, 6);
    if(n1!=NULL){
        printf("Found");
    }else {
        printf("Not Found");
    }

    deleteNode(p,6);
    printf("\n");
    inorder(p);
    
    return 0;
}