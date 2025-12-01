#include <iostream>
using namespace std;

class TwoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x){
        if(top1 < top2 - 1)
            arr[++top1] = x;
        else
            cout << "Overflow\n";
    }

    void push2(int x){
        if(top1 < top2 - 1)
            arr[--top2] = x;
        else
            cout << "Overflow\n";
    }

    int pop1(){
        if(top1 >= 0) return arr[top1--];
        cout << "Underflow\n";
        return -1;
    }

    int pop2(){
        if(top2 < size) return arr[top2++];
        cout << "Underflow\n";
        return -1;
    }
};

int main(){
    TwoStacks ts(10);
    ts.push1(10);
    ts.push2(20);
    cout << ts.pop1() << " " << ts.pop2();
}
