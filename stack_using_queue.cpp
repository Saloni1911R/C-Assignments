#include <iostream>
using namespace std;

/* Use simple array queue; push is enqueue, but we rotate to make top at front */
struct Queue{ int a[100], f=0, sz=0, cap=100; void enq(int x){ a[(f+sz)%cap]=x; sz++; } int deq(){ int x=a[f]; f=(f+1)%cap; sz--; return x;} bool empty(){return sz==0;} int size(){return sz;} };

struct Stack{
    Queue q;
    void push(int x){
        q.enq(x);
        int k=q.size()-1;
        while(k--) q.enq(q.deq());
    }
    void pop(){ if(!q.empty()) q.deq(); }
    int top(){ return q.empty()? -1 : q.a[q.f]; }
    bool empty(){ return q.empty(); }
};

int main(){
    Stack s; s.push(1); s.push(2); s.push(3);
    cout<<s.top()<<"\n"; s.pop(); cout<<s.top()<<"\n"; // 3 then 2
}
