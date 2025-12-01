#include <iostream>
using namespace std;

struct Queue {
    int a[100], f=0, sz=0;
    void enq(int x){ a[(f+sz)%100]=x; sz++; }
    int deq(){ int x=a[f]; f=(f+1)%100; sz--; return x; }
    bool empty(){ return sz==0; }
};

void reverseK(Queue &q, int k){
    if(k==0 || q.empty()) return;
    int x=q.deq();
    reverseK(q, k-1);
    q.enq(x);
}

int main(){
    Queue q; int n,k; cin>>n>>k;
    for(int i=0;i<n;i++){ int x; cin>>x; q.enq(x); }

    reverseK(q, k);

    // Move remaining (n - k) elements to back in same order
    for(int i=0;i<n-k;i++) q.enq(q.deq());

    while(!q.empty()) cout<<q.deq()<<" ";
}
