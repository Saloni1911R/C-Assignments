#include <iostream>
using namespace std;

struct CircularQueue{
    int a[100], front=0, size=0, cap=100;
    void enq(int x){ if(size==cap){ cout<<"Overflow\n"; return; } a[(front+size)%cap]=x; size++; }
    void deq(){ if(size==0){ cout<<"Underflow\n"; return; } front=(front+1)%cap; size--; }
    int fr(){ return size==0? -1 : a[front]; }
    bool empty(){ return size==0; }
};

int main(){
    CircularQueue q; q.enq(1); q.enq(2); q.deq(); q.enq(3);
    cout<<q.fr(); // 2
}
