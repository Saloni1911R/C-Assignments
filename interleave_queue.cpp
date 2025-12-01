#include <iostream>
using namespace std;

struct Queue { 
    int a[200], f=0, sz=0; 
    void enq(int x){ a[(f+sz)%200]=x; sz++; }
    int deq(){ int x=a[f]; f=(f+1)%200; sz--; return x; }
};

int main(){
    Queue q, firstHalf;
    int n; cin>>n;
    for(int i=0;i<n;i++){ int x; cin>>x; q.enq(x); }

    int half=n/2;
    for(int i=0;i<half;i++) firstHalf.enq(q.deq());

    while(firstHalf.sz){
        q.enq(firstHalf.deq());
        q.enq(q.deq());
    }

    for(int i=0;i<n;i++) cout<<q.deq()<<" ";
}
