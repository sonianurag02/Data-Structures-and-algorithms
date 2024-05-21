#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct ArrayStack
{
    int top;
    int capacity;
    int* array;
};
struct ArrayStack* createStack(int cap){
    struct ArrayStack *stack;
    stack = new struct ArrayStack;
    stack->capacity = cap;
    stack->top = -1;
    stack->array = new int[stack->capacity];
    return (stack);
}
int isFull(struct ArrayStack *stack){
    if(stack->top == stack->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct ArrayStack *stack){
    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct ArrayStack *stack, int item){
    if(!isFull(stack)){
        stack->top++;
        stack->array[stack->top] = item;
    }
}
int pop(struct ArrayStack *stack){
    int item;
    if(!isEmpty(stack)){
        item = stack->array[stack->top];
        stack->top--;
        return (item);
    }
    return (-1);
}
int main(){
    struct ArrayStack *stack;
    stack = createStack(4);
    int choice, item;
    while (1)
    {
        cout<<"Enter your choice: "<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter a number "<<endl;
            cin>>item;
            push(stack,item);
            break;
        case 2: 
            item = pop(stack);
            if(item == -1){
                cout<<"Stack is Empty."<<endl;
            }
            else{
                cout<<"Popped value is "<<item<<endl;
            }
            break;

        case 3:
            exit(0);

        default:
            cout<<"Invalid choice! Enter your choice again."<<endl;
            break;
        }
    }
    
}
