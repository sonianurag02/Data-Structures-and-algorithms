#include <iostream>
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
    char stackTop(Stack* s){
        return s->array[s->top];
    }
    char stackBottom(Stack* s){
        return s->array[0];
    }
    int match(char a, char b){
        if(a == '(' && b == ')') return 1;
        if(a == '{' && b == '}') return 1;
        if(a == '[' && b == ']') return 1;
        return 0;
    }
    int parenthesisMatch(char* exp){
        // Create and initialize a stack
        Stack sp;
        createStack(&sp, 100);
        char popped_ch;

        for(int i = 0; exp[i] != '\0'; i++){
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
                push(&sp, exp[i]);
            }
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
                if(isEmpty(&sp)){
                    return 0;
                }
                popped_ch = pop(&sp);
                if(!match(popped_ch, exp[i])){
                    return 0;
                }
            }
        }
        return isEmpty(&sp) ? 1 : 0;
    }
};
int main()
{
    Stack s1;
    char* exp = "{[(8*(9))]}";
    if(s1.parenthesisMatch(exp)){
        cout<<"Parenthesis is balanced."<<endl;
    }
    else{
        cout<<"Parenthesis is not balanced."<<endl;
    }

    return 0;
}