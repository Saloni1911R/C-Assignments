#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[100], st[100], ans[100], top=-1;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=n-1;i>=0;i--){
        while(top!=-1 && st[top] >= a[i]) top--;
        ans[i] = (top==-1)? -1 : st[top];
        st[++top] = a[i];
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}
