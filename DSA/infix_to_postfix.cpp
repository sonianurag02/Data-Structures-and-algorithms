#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *array;

    void createStack(Stack *s, int sz)
    {
        s->size = sz;
        s->top = -1;
        s->array = new char[s->size];
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
    void push(Stack* s, char value){
        if(isFull(s)){
            cout<<"Stack Overflow. Cannot push "<<value<<" to the stack."<<endl;
        }
        else{
            s->top++;
            s->array[s->top] = value;
        }
    }
    char pop(Stack* s){
        if(isEmpty(s)){
            cout<<"Stack Underflow. Cannot pop element from stack."<<endl;
            return -1;
        }
        else{
            char value = s->array[s->top];
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
    int precedence(char ch){
        if(ch == '*' || ch == '/'){
            return 3;
        }
        else if(ch == '+' || ch == '-'){
            return 2;
        }
        else{
            return 0;
        }
    }
    int isOperator(char ch){
        if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
            return 1;
        }
        else{
            return 0;
        }
    }
    char* infixtoPostfix(char* infix){
        Stack sp;
        createStack(&sp, 100);
        char* postfix = new char[strlen(infix)+1];
        int i = 0; // Track infix traversal
        int j = 0; // Track postfix addition
        while(infix[i] != '\0'){
            if(!isOperator(infix[i])){
                postfix[j] = infix[i];
                i++;
                j++;
            }
            else{
                if(precedence(infix[i]) > precedence(stackTop(&sp))){
                    push(&sp, infix[i]);
                    i++;
                }
                else{
                    postfix[j] = pop(&sp);
                    j++;
                }
            }
        }
        while(!isEmpty(&sp)){
            postfix[j] = pop(&sp);
            j++;
        }
        postfix[j] = '\0';
        return postfix;
    }
};
int main()
{
    Stack s1;
    char* exp = "x-y/z-k*d";

    cout<<"Infix to postfix: "<<s1.infixtoPostfix(exp)<<endl;

    return 0;
}