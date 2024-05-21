#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

        void linkedListTraversal(class ListNode* head){
            while(head != NULL){
                cout<<"Element: "<<head->data<<endl;
                head = head->next;
            }
        }

        int isEmpty(ListNode* top){
            if(top == NULL){
                return 1;
            }
            return 0;
        }
        int isFull(ListNode* top){
            ListNode* n = new ListNode;
            if(n == NULL){
                return 1;
            }
            return 0;
        }
        ListNode* push(ListNode* top, int x){
            if(isFull(top)){
                cout<<"Stack Overflow."<<endl;
            }
            else{
                ListNode* n = new ListNode;
                n->data = x;
                n->next = top;
                top = n;
                return top;
            }
        }
        int pop(ListNode** top){
            if(isEmpty(*top)){
                cout<<"Stack Underflow."<<endl;
            }
            else{
                ListNode* n = *top;
                *top = (*top)->next;
                int x = n->data;
                free(n);
                return x;
            }
        }
        int peek(ListNode* top, int pos){
            ListNode* ptr = top;
            for(int i = 0; (i < pos-1 && ptr != NULL); i++){
                ptr = ptr->next;
            }
            if(ptr != NULL){
                return ptr->data;
            }
            else{
                return -1;
            }
        }
        int stackTop(ListNode* top){
            return top->data;
        }
        // int stackBottom(ListNode* top){
        //     ListNode* ptr = top->next;
        //     int temp = 0;
        //     while(ptr != NULL){
        //         ptr = ptr->next;
        //         temp = ptr->data;
        //     }
        //     return temp;
        // }
};
int main(){
    ListNode ln;
    ListNode* top = NULL;

    top = ln.push(top, 10);
    top = ln.push(top, 12);
    top = ln.push(top, 14);
    top = ln.push(top, 16);

    cout<<"Before traversal"<<endl;
    ln.linkedListTraversal(top);

    // int element = ln.pop(&top);
    // cout<<"Popped element is "<<element<<endl;

    for(int i = 1; i <= 4; i++){
        cout<<"Value at position "<<i<<" is "<<ln.peek(top, i)<<endl;
    }
    cout<<"Topmost element of stack is "<<ln.stackTop(top)<<endl;
    // cout<<"Bottom most element of stack is "<<ln.stackBottom(top)<<endl;
    
    cout<<"After traversal"<<endl;
    ln.linkedListTraversal(top);

    return 0;
}