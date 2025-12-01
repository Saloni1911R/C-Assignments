#include <iostream>
using namespace std;

struct Stack { int a[100], top=-1; void push(int x){ a[++top]=x; } int pop(){ return a[top--]; } bool empty(){ return top==-1; } int peek(){ return a[top]; } };

void sortedInsert(Stack &s, int x){
    if(s.empty() || s.peek() <= x){ s.push(x); return; }
    int t = s.pop();
    sortedInsert(s, x);
    s.push(t);
}

void sortStack(Stack &s){
    if(s.empty()) return;
    int x = s.pop();
    sortStack(s);
    sortedInsert(s, x);
}

int main(){
    Stack s; s.push(30); s.push(10); s.push(20);
    sortStack(s);
    while(!s.empty()) cout<<s.pop()<<" "; // prints 30 20 10 (descending top-first)
}
