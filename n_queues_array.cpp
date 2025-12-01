#include <iostream>
using namespace std;

struct NQueues {
    int n, cap;
    int *arr, *start, *top;
    NQueues(int n, int capPerQ){
        this->n=n; cap=capPerQ;
        arr = new int[n*cap];
        start = new int[n];
        top = new int[n];
        for(int i=0;i<n;i++){ start[i]=i*cap; top[i]=start[i]-1; }
    }
    void enqueue(int qno, int x){
        if(top[qno] < start[qno] + cap -1) arr[++top[qno]]=x;
        else cout<<"Overflow\n";
    }
    int dequeue(int qno){
        if(top[qno] < start[qno]){ cout<<"Underflow\n"; return -1; }
        int val = arr[start[qno]];
        for(int i=start[qno]; i<top[qno]; i++) arr[i]=arr[i+1];
        top[qno]--;
        return val;
    }
};

int main(){
    NQueues Q(3,4);
    Q.enqueue(0,10); Q.enqueue(0,20);
    cout<<Q.dequeue(0)<<"\n"; // 10
}
