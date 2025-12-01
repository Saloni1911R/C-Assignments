#include <iostream>
using namespace std;

struct Queue{ int a[100], f=0, sz=0; void enq(int x){ a[(f+sz)%100]=x; sz++; } int deq(){ int x=a[f]; f=(f+1)%100; sz--; return x; } bool empty(){ return sz==0; } };

void reverseQueue(Queue &q){
    if(q.empty()) return;
    int x = q.deq();
    reverseQueue(q);
    q.enq(x);
}

int main(){
    Queue q; q.enq(1); q.enq(2); q.enq(3);
    reverseQueue(q);
    while(!q.empty()) cout<<q.deq()<<" "; // prints 3 2 1
}
