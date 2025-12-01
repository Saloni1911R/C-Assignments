#include <iostream>
using namespace std;

struct Stack { int a[100], top=-1; void push(int x){a[++top]=x;} int pop(){ return a[top--]; } bool empty(){ return top==-1; } int peek(){ return a[top]; } };

struct Queue {
    Stack s1, s2;
    void enqueue(int x){ s1.push(x); }
    void dequeue(){ if(s2.empty()){ while(!s1.empty()) s2.push(s1.pop()); } if(!s2.empty()) s2.pop(); }
    int front(){ if(s2.empty()){ while(!s1.empty()) s2.push(s1.pop()); } return s2.peek(); }
    bool empty(){ return s1.empty() && s2.empty(); }
};

int main(){
    Queue q; q.enqueue(1); q.enqueue(2); q.enqueue(3);
    cout<<q.front()<<"\n"; q.dequeue(); cout<<q.front()<<"\n"; // 1 then 2
}
