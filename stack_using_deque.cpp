#include <iostream>
using namespace std;

/* Simple deque with array */
struct Deque{ int a[200], front=100, back=100; void push_back(int x){ a[back++]=x; } void push_front(int x){ a[--front]=x; } int pop_back(){ return a[--back]; } int pop_front(){ return a[front++]; } bool empty(){ return front==back; } int frontVal(){ return a[front]; } int backVal(){ return a[back-1]; } };

/* Stack using deque: use back operations */
int main(){
    Deque d;
    d.push_back(1); d.push_back(2); d.push_back(3);
    cout<<d.pop_back()<<" "<<d.pop_back(); // 3 2
}
