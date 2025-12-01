#include <iostream>
using namespace std;

class Stack {
    int arr[100], top;
public:
    Stack(){ top = -1; }
    void push(int x){ arr[++top] = x; }
    int pop(){ return arr[top--]; }
    bool empty(){ return top == -1; }
    int size(){ return top + 1; }
};

int main(){
    Stack s, temp;
    s.push(10); s.push(20); s.push(30); s.push(40); s.push(50);

    int mid = s.size()/2;

    for(int i=0;i<mid;i++)
        temp.push(s.pop());

    cout << "Middle element = " << s.pop();
}
