#include <iostream>
using namespace std;

class NStacks {
    int n, size;
    int *arr, *top, *start;

public:
    NStacks(int n, int size){
        this->n = n;
        this->size = size;
        arr = new int[size];
        top = new int[n];
        start = new int[n];

        int seg = size / n;
        for(int i=0;i<n;i++){
            start[i] = i * seg;
            top[i] = start[i] - 1;
        }
    }

    void push(int stackNum, int x){
        if(top[stackNum] < start[stackNum] + size/n - 1)
            arr[++top[stackNum]] = x;
        else
            cout << "Overflow in stack " << stackNum << endl;
    }

    int pop(int stackNum){
        if(top[stackNum] >= start[stackNum])
            return arr[top[stackNum]--];
        cout << "Underflow in stack " << stackNum << endl;
        return -1;
    }
};
