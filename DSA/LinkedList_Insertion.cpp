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
        // Insert at First Index
        ListNode* insertAtFirst(ListNode *head, int data){
            ListNode* ptr = new ListNode;
            ptr->next = head;
            ptr->data = data;
            return ptr;
        }
        // Insert at any Index
        ListNode* insertAtIndex(ListNode* head, int data, int index){
            ListNode* ptr = new ListNode;
            ListNode* p = head;
            int i = 0;
            while(i != index-1){
                p = p->next;
                i++;
            }
            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;
            return head;
        }
        // Insert at End
        ListNode* insertAtEnd(ListNode* head, int data){
            ListNode* ptr = new ListNode;
            ListNode* p = head;
            ptr->data = data;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = ptr;
            ptr->next = NULL;
            return head;
        }
        // Insert after any Node
        ListNode* insertAfterNode(ListNode* head, ListNode* prevNode, int data){
            ListNode* ptr = new ListNode;
            ptr->data = data;
            ptr->next = prevNode->next;
            prevNode->next = ptr;
            return head;
        }
};

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
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

    // cout<<"Insert at First Index:"<<endl;
    // head = l1.insertAtFirst(head, 4);

    // cout<<"Insert at any Index:"<<endl;
    // head = l1.insertAtIndex(head, 9, 2);

    // cout<<"Insert at End:"<<endl;
    // head = l1.insertAtEnd(head, 14);

    // cout<<"Insert After a node:"<<endl;
    head = l1.insertAfterNode(head, first, 9);

    cout<<"Linked List after insertion:"<<endl;
    l1.linkedListTraversal(head);

    return 0;
}