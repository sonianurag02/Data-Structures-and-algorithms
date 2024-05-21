#include <iostream>
using namespace std;

class Queue{
    public:
        int size;
        int front;
        int rear;
        int* arr;

        void createQueue(class Queue* q, int sz){
            q->size = sz;
            q->front = q->rear = -1;
            q->arr = new int[q->size];
            cout<<"Queue has been created successfully."<<endl;
        }
        int isFull(class Queue* q){
            if(q->rear == q->size-1){
                return 1;
            }
            return 0;
        }
        int isEmpty(class Queue* q){
            if(q->rear == q->front){
                return 1;
            }
            return 0;
        }
        void enqueue(class Queue* q, int val){
            if(isFull(q)){
                cout<<"Queue Overflow."<<endl;
            }
            else{
                q->rear++;
                q->arr[q->rear] = val;
                cout<<val<<" is successfully inserted."<<endl;
            }
        }
        int dequeue(class Queue* q){
            int a = -1;
            if(isEmpty(q)){
                cout<<"Queue Underflow."<<endl;
            }
            else{
                q->front++;
                a = q->arr[q->front];
            }
            return a;
        }
};
int main(){
    Queue q;
    q.createQueue(&q, 4);

    // Enqueue few elements
    q.enqueue(&q, 10);
    q.enqueue(&q, 12);
    q.enqueue(&q, 14);
    q.enqueue(&q, 16);

    // Dequeuing few elements
    cout<<"Dequeuing element "<<q.dequeue(&q)<<endl;
    cout<<"Dequeuing element "<<q.dequeue(&q)<<endl;
    cout<<"Dequeuing element "<<q.dequeue(&q)<<endl;
    cout<<"Dequeuing element "<<q.dequeue(&q)<<endl;
    
    q.enqueue(&q, 18);

    if(q.isEmpty(&q)){
        cout<<"Queue is empty."<<endl;
    }
    if(q.isFull(&q)){
        cout<<"Queue is full."<<endl;
    }



    return 0;
}