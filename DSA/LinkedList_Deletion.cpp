#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

        void linkedListTraversal(class ListNode* head){
            while(head != NULL){
                cout<<"Element: "<<head->data<<endl;
                head = head->next;
            }
        }
        // Delete at First Index
        ListNode* deleteAtFirst(ListNode *head){
            ListNode* ptr = head;
            head = head->next;
            free(ptr);
            return head;
        }
        // Deletion the element at a given Index
        ListNode* deleteAtIndex(ListNode* head, int index){
            ListNode* p = head;
            int i = 0;
            while(i != index-1){
                p = p->next;
                i++;
            }
            ListNode* q = p->next;
            p->next = q->next;
            free(q);
            return head;
        }
        // Delete the last Element
        ListNode* deletionAtLast(ListNode* head){
            ListNode* p = head;
            ListNode* q = p->next;
            while(q->next != NULL){
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            free(q);
            return head;
        }
        // IDelete the element with a given value
        ListNode* deleteWithAGivenValue(ListNode* head, int value){
            ListNode* p = head;
            ListNode* q = p->next;
            while(q->data != value && q->next != NULL){
                p = p->next;
                q = q->next;
            }
            if(q->data == value){
                p->next = q->next;
                free(q);
            }
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
    third->next = NULL;

    cout<<"Linked List before insertion:"<<endl;
    l1.linkedListTraversal(head);

    // For deleting element at first Index.
    // head = l1.deleteAtFirst(head);

    // For deleting element at any Index.
    // head = l1.deleteAtIndex(head, 2);

    // Delete the last element
    // head = l1.deletionAtLast(head);

    // Delete the element with a given value
    head = l1.deleteWithAGivenValue(head, 8);

    cout<<"Linked List after insertion:"<<endl;
    l1.linkedListTraversal(head);

    return 0;
}