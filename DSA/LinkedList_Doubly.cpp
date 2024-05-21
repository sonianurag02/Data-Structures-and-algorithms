#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* prev;
        ListNode* next;

    void linkedListTraversal(class ListNode* head){
        cout<<"Printing in given order"<<endl;
        while(head != NULL){
            cout<<"Element: "<<head->data<<endl;
            head = head->next;
        }
    }
    void linkedListTraversalReverseOrder(class ListNode** head){
        cout<<"Printing in reverse order"<<endl;
        ListNode* tail = *head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        while(tail != *head){
            cout<<"Element: "<<tail->data<<endl;
            tail = tail->prev;
        }
        cout<<"Element: "<<tail->data<<endl;
    }
};
int main(){
    ListNode ln;
    ListNode* head;
    head = new ListNode;
    ListNode* second;
    second = new ListNode;
    ListNode* third;
    third = new ListNode;
    ListNode* fourth;
    fourth = new ListNode;

    head->data = 10;
    head->prev = NULL;
    head->next = second; 

    second->data = 12;
    second->prev = head;
    second->next = third; 

    third->data = 14;
    third->prev = second;
    third->next = fourth; 

    fourth->data = 15;
    fourth->prev = third;
    fourth->next = NULL; 

    // Doubly Linked List in given order
    ln.linkedListTraversal(head);

    // Doubly Linked List in Reverse Order
    ln.linkedListTraversalReverseOrder(&head);

    return 0;
}