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
                // cout<<val<<" is successfully inserted."<<endl;
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
    q.createQueue(&q, 400);

    // BFS Implementation
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
         {0, 1, 1, 1, 0, 0, 0},
         {1, 0, 1, 0, 0, 0, 0},
         {1, 1, 0, 1, 1, 0, 0},
         {1, 0, 1, 0, 1, 0, 0},
         {0, 0, 1, 1, 0, 1, 1},
         {0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0, 0}
    };
    cout<<i<<" ";
    visited[i] = 1;
    q.enqueue(&q, i); // Enqueue i for exploration
    while(!q.isEmpty(&q)){
        int node = q.dequeue(&q);

        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = 1;
                q.enqueue(&q, j);
            }
        }
        
    }

    return 0;
}