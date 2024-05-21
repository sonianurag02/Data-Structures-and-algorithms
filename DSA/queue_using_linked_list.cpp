#include<iostream>
using namespace std;

class Node* front = NULL;
class Node* rear = NULL;

class Node{
    public:
        int data;
        Node *next;

        void linkedListTraversal(class Node* head){
            cout<<"Printing the elements of the linked list: "<<endl;
            while(head != NULL){
                cout<<"Element: "<<head->data<<endl;
                head = head->next;
            }
        }

        void enqueue(int val){
            Node* n = new Node;
            if(n == NULL){
                cout<<"Queue is full"<<endl;
            }
            else{
                n->data = val;
                n->next = NULL;
                if(front == NULL){
                    front = rear = n;
                }
                else{
                    rear->next = n;
                    rear = n;
                }
            }
        }

        int dequeue(){
            int val = -1;
            Node *ptr = front;
            if(front == NULL){
                cout<<"Queue is Empty."<<endl;
            }
            else{
                front = front->next;
                val = ptr->data;
                free(ptr);
            }
            return val;
        }
};

int main(){
    Node n1;

    n1.linkedListTraversal(front);

    cout<<"Dequeueing elemeent "<<n1.dequeue()<<endl;

    n1.enqueue(34);
    n1.enqueue(4);
    n1.enqueue(7);

    cout<<"Dequeueing elemeent "<<n1.dequeue()<<endl;

    n1.linkedListTraversal(front);

    return 0;
}