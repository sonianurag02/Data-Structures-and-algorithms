#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

        void linkedListTraversal(class ListNode* head){
            ListNode* ptr = head;
            // cout<<"Element: "<<ptr->data<<endl;
            // ptr = ptr->next;
            // while(ptr != head){
            //     cout<<"Element: "<<ptr->data<<endl;
            //     ptr = ptr->next;
            // }
            do{
                cout<<"Element: "<<ptr->data<<endl;
                ptr = ptr->next;
            }while(ptr != head);
        }

        ListNode* insertAtFirst(ListNode* head, int data){
            ListNode* ptr = new ListNode;
            ptr->data = data;

            ListNode* p = head->next;
            while(p->next != head){
                p = p->next;
            }
            // At this point p points to the last node of the circular linked list. 
            p->next = ptr;
            ptr->next = head;
            head = ptr;
            return head;
        }
};

int main(){
    ListNode *head, l1;
    head = new ListNode;
    ListNode *first;
    first = new ListNode;
    ListNode *second;
    second = new ListNode;
    ListNode *third;
    third = new ListNode;

    head->data = 6;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 10;
    second->next = third;
    
    third->data = 12;
    third->next = head;

    cout<<"Linked List before insertion:"<<endl;
    l1.linkedListTraversal(head);

    head = l1.insertAtFirst(head, 4);

    cout<<"Linked List after insertion:"<<endl;
    l1.linkedListTraversal(head);

    return 0;
}