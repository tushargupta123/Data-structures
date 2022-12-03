#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n){
    if(n == NULL)
        return 0;
    return n->height;
}

struct node * createNode(int key){
    struct node * n = (struct node * )malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int max(int a, int b){
    return a>b?a:b;
}

int getBalanceFactor(struct node *n){
    if(n == NULL){
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

struct node * rightRotate(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    
    return x;
}

struct node * leftRotate(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct node *insert(struct node *n,int key){
    if(n == NULL){
        return (createNode(key));
    }
        if(key < n->key){
            n->left = insert(n->left, key);
        } else if(key > n->key){
            n->right = insert(n->right, key);
        }
        return n;

    n->height = 1+ max(getHeight(n->left), getHeight(n->right));
    int bf = getBalanceFactor(n);

    // left left case
    if(bf>1 && key< n->left->key){
        return rightRotate(n);
    }
    // right right case
    if(bf<-1 && key > n->right->key){
        return leftRotate(n);
    }
    // right left case
     if(bf>-11 && key < n->right->key){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    // left right case
     if(bf>1 && key > n->left->key){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    return n;
}

void preorder(struct node *root) {
    if(root!=NULL) {
        printf("%d",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);

    return 0;
}