#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *n; // Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Settign the left and right children to null
    n->right = NULL; // Settign the left and right children to null

    return n; // Finally retturning the created node
}

void preOrder(struct node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int isBST(struct node* root){
    if(root != NULL){
        static struct node* prev = NULL;
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node* search(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

struct node* iterativeBST(struct node* root, int key){
    while(root != NULL){
        if(root->data == key){
            return root;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

void insertInBST(struct node* root, int key){
    struct node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            cout<<"Cannot insert "<<key<<", already in BST."<<endl;
            return ;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* ptr = createNode(key);
    if(key < prev->data){
        prev->left = ptr;
    }
    else{
        prev->right = ptr;
    }
}

int main(){

    // Constructing the root node using functions
    struct node *p = createNode(5); // 4
    struct node *p1 = createNode(3); // 1
    struct node *p2 = createNode(6); // 6
    struct node *p3 = createNode(1); // 5
    struct node *p4 = createNode(4); // 2
    // Finally a tree looks like this
    /*        5
             /\
            /  \
           3    6
          /\
         /  \
        1    4 */

    
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // cout<<"Pre-order traversal: "<<endl;
    // preOrder(p);
    // cout<<endl;
    // cout<<"Post-order traversal: "<<endl;
    // postOrder(p);
    // cout<<endl;
    cout<<"In-order traversal: "<<endl;
    inOrder(p);
    cout<<endl;
    cout<<"To check the tree is Binary Search Tree or not: "<<(isBST(p))<<endl;

    // struct node* n = search(p, 3);
    struct node* n = iterativeBST(p, 6);
    if(n != NULL){
        cout<<"Element found: "<<n->data<<endl; 
    }
    else{
        cout<<"Element not found!!"<<endl;
    }

    insertInBST(p, 7);
    cout<<p->right->right->data<<endl;

    return 0;
}