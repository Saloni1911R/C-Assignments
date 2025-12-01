#include <iostream>
using namespace std;

struct Queue {
    int *arr;
    int capacity;
    int frontIdx, size;
    Queue(int cap=1000){
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0;
        size = 0;
    }
    ~Queue(){ delete[] arr; }
    void enqueue(int x){
        if(size == capacity){ cout<<"Overflow\n"; return; }
        int idx = (frontIdx + size) % capacity;
        arr[idx] = x;
        size++;
    }
    void dequeue(){
        if(size==0){ cout<<"Underflow\n"; return; }
        frontIdx = (frontIdx + 1) % capacity;
        size--;
    }
    int front(){ if(size==0) return -1; return arr[frontIdx]; }
    bool empty(){ return size==0; }
};

int main(){
    Queue q(10);
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    cout<<q.front()<<"\n"; //1
    q.dequeue();
    cout<<q.front()<<"\n"; //2
    return 0;
}
