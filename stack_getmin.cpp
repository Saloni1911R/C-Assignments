#include <iostream>
using namespace std;

class Stack {
    int arr[100], top, minElement;
public:
    Stack(){ top = -1; }

    void push(int x){
        if(top == -1){
            arr[++top] = x;
            minElement = x;
        }
        else if(x >= minElement){
            arr[++top] = x;
        }
        else {
            arr[++top] = 2*x - minElement;
            minElement = x;
        }
    }

    int pop(){
        int t = arr[top--];
        if(t >= minElement) return t;
        int oldMin = minElement;
        minElement = 2*minElement - t;
        return oldMin;
    }

    int getMin(){ return minElement; }
};

int main(){
    Stack s;
    s.push(5); s.push(3); s.push(7); s.push(2);
    cout << "Min = " << s.getMin();
}
