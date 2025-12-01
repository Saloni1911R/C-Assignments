#include <iostream>
using namespace std;

struct Stack {
    int a[100], top=-1;
    void push(int x){ a[++top]=x; }
    int pop(){ return a[top--]; }
    bool empty(){ return top==-1; }
    int peek(){ return a[top]; }
};

void insertAtBottom(Stack &s, int x){
    if(s.empty()){ s.push(x); return; }
    int t = s.pop();
    insertAtBottom(s, x);
    s.push(t);
}

int main(){
    Stack s; s.push(1); s.push(2); s.push(3); // top=3
    insertAtBottom(s, 0); // becomes 0,1,2,3 (top 3)
    while(!s.empty()){ cout<<s.pop()<<" "; } // outputs 3 2 1 0
}
