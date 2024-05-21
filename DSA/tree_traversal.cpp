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
    // root - left - right
    /*        4
             /\
            /  \
           1    6
          /\
         /  \
        5    2 */
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

int main(){

    // Constructing the root node using functions
    struct node *p = createNode(1); // 4
    struct node *p1 = createNode(2); // 1
    struct node *p2 = createNode(3); // 6
    struct node *p3 = createNode(4); // 5
    struct node *p4 = createNode(5); // 2

    
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout<<"Pre-order traversal: "<<endl;
    preOrder(p);
    cout<<endl;
    cout<<"Post-order traversal: "<<endl;
    postOrder(p);
    cout<<endl;
    cout<<"In-order traversal: "<<endl;
    inOrder(p);

    return 0;
}