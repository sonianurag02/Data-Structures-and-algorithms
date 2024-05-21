#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *array;

    void createStack(Stack *s, int sz)
    {
        s->size = sz;
        s->top = -1;
        s->array = new int[s->size];
        cout<<"Stack has been created successfully."<<endl;
    }
    int isEmpty(Stack *s)
    {
        if (s->top == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull(Stack *s)
    {
        if (s->top == s->size - 1)
        {
            return 1;
        }
        return 0;
    }
    void push(Stack* s, int value){
        if(isFull(s)){
            cout<<"Stack Overflow. Cannot push "<<value<<" to the stack."<<endl;
        }
        else{
            s->top++;
            s->array[s->top] = value;
        }
    }
    int pop(Stack* s){
        if(isEmpty(s)){
            cout<<"Stack Underflow. Cannot pop element from stack."<<endl;
            return -1;
        }
        else{
            int value = s->array[s->top];
            s->top--;
            return value;
        }
    }
    int peek(Stack* s, int i){
        int arrInd = s->top - i + 1;
        if(arrInd < 0){
            cout<<"Not a valid position for a stack."<<endl;
            return -1;
        }
        else{
            return s->array[arrInd];
        }
    }
    int stackTop(Stack* s){
        return s->array[s->top];
    }
    int stackBottom(Stack* s){
        return s->array[0];
    }
};
int main()
{
    Stack s1;
    s1.createStack(&s1, 50);

    // Pushing elements manually
    // s1.array[0] = 4;
    // s1.top++;

    // Check if stack is empty
    // if(s1.isEmpty(&s1)){
    //     cout<<"Stack is Empty"<<endl;
    // }
    // else{
    //     cout<<"Stack is not empty"<<endl;
    // }

    // int x = s1.pop(&s1);
    // cout<<"Popped value is: "<<x<<endl;

    s1.push(&s1, 10);
    s1.push(&s1, 20);
    s1.push(&s1, 30);

    // int y = s1.pop(&s1);
    // cout<<"Popped value is: "<<y<<endl;

    // int index;
    // cout<<"Enter index to check value on it: "<<endl;
    // cin>>index;
    for(int i = 1; i <= s1.top+1; i++){
        int z = s1.peek(&s1, i);
        cout<<"The value at index "<<i<<" is "<<z<<endl;
    }
    
    cout<<"The top most element of stack is "<<s1.stackTop(&s1)<<endl;
    cout<<"The bottm most element of stack is "<<s1.stackBottom(&s1)<<endl;

    return 0;
}