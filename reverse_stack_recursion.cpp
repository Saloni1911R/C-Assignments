#include <iostream>
using namespace std;

struct Stack { int a[100], top=-1; void push(int x){ a[++top]=x; } int pop(){ return a[top--]; } bool empty(){ return top==-1; } int peek(){ return a[top]; } };

void insertAtBottom(Stack &s, int x){
    if(s.empty()){ s.push(x); return; }
    int t = s.pop();
    insertAtBottom(s, x);
    s.push(t);
}

void reverseStack(Stack &s){
    if(s.empty()) return;
    int x = s.pop();
    reverseStack(s);
    insertAtBottom(s, x);
}

int main(){
    Stack s; s.push(1); s.push(2); s.push(3);
    reverseStack(s);
    while(!s.empty()) cout<<s.pop()<<" "; // prints 1 2 3
}
