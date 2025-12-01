#include <iostream>
using namespace std;

int maxArea(int hist[], int n){
    int st[100], top=-1;
    int maxA=0, i=0;
    while(i<n){
        if(top==-1 || hist[st[top]] <= hist[i]) st[++top]=i++;
        else{
            int tp = st[top--];
            int width = (top==-1)? i : i - st[top] -1;
            maxA = max(maxA, hist[tp]*width);
        }
    }
    while(top!=-1){
        int tp = st[top--];
        int width = (top==-1)? i : i - st[top] -1;
        maxA = max(maxA, hist[tp]*width);
    }
    return maxA;
}

int main(){
    int n; cin>>n;
    int h[100];
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<maxArea(h,n);
}
