#include <iostream>
using namespace std;

struct Stack {
    int *arr;
    int capacity;
    int topIdx;
    Stack(int cap=1000){
        capacity = cap;
        arr = new int[capacity];
        topIdx = -1;
    }
    ~Stack(){ delete[] arr; }
    void push(int x){
        if(topIdx+1 == capacity){ cout<<"Overflow\n"; return; }
        arr[++topIdx] = x;
    }
    void pop(){
        if(topIdx == -1){ cout<<"Underflow\n"; return; }
        topIdx--;
    }
    int top(){ if(topIdx==-1) return -1; return arr[topIdx]; }
    bool empty(){ return topIdx == -1; }
};

int main(){
    Stack s(10);
    s.push(5); s.push(10);
    cout<<s.top()<<"\n"; // 10
    s.pop();
    cout<<s.top()<<"\n"; //5
    return 0;
}
