#include <iostream>
using namespace std;

class de_queue{
    public:
        int size;
        int front;
        int rear;
        int *arr;

        void createQueue(class de_queue *q, int sz){
            q->size = sz;
            q->front = q->rear = 0;
            q->arr = new int[q->size];
            cout<<"Queue has been created successfully."<<endl;
        }
        int isFull(class de_queue* q){
            if(((q->rear+1) % q->size) == q->front){
                return 1;
            }
            return 0;
        }
        int isEmpty(class de_queue* q){
            if(q->rear == q->front){
                return 1;
            }
            return 0;
        }
        void enqueue_at_rear(class de_queue* q, int val){
            if(isFull(q)){
                cout<<"Queue Overflow."<<endl;
            }
            else{
                q->rear = (q->rear+1)%q->size;
                q->arr[q->rear] = val;
                cout<<val<<" is successfully inserted."<<endl;
            }
        }void enqueue_at_front(class de_queue* q, int val){
            if(isFull(q)){
                cout<<"Queue Overflow."<<endl;
            }
            else{
                q->front = (q->front-1)%q->size;
                q->arr[q->front] = val;
                cout<<val<<" is successfully inserted."<<endl;
            }
        }
        int dequeue_from_front(class de_queue* q){
            int a = -1;
            if(isEmpty(q)){
                cout<<"Queue Underflow."<<endl;
            }
            else{
                q->front = (q->front+1)%q->size;
                a = q->arr[q->front];
            }
            return a;
        }
        int dequeue_from_rear(class de_queue* q){
            int a = -1;
            if(isEmpty(q)){
                cout<<"Queue Underflow."<<endl;
            }
            else{
                q->rear = (q->rear-1)%q->size;
                a = q->arr[q->rear];
            }
            return a;
        }
};

int main(){
    de_queue q;
    q.createQueue(&q, 4);

    // Enqueue few elements
    q.enqueue_at_rear(&q, 10);
    q.enqueue_at_front(&q, 12);
    q.enqueue_at_rear(&q, 14);
    q.enqueue_at_front(&q, 16);
    q.enqueue_at_front(&q, 18);
    q.enqueue_at_front(&q, 20);

    // Dequeuing few elements
    cout<<"Dequeuing element "<<q.dequeue_from_front(&q)<<endl;
    cout<<"Dequeuing element "<<q.dequeue_from_rear(&q)<<endl;

    q.enqueue_at_rear(&q, 14);
    q.enqueue_at_front(&q, 16);

    if(q.isEmpty(&q)){
        cout<<"Queue is empty."<<endl;
    }
    if(q.isFull(&q)){
        cout<<"Queue is full."<<endl;
    }

    return 0;
}