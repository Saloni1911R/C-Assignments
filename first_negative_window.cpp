#include <iostream>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    int a[100], q[100], f=0,r=0;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<k;i++)
        if(a[i]<0) q[r++]=i;

    for(int i=k;i<=n;i++){
        if(f!=r) cout<<a[q[f]]<<" ";
        else cout<<0<<" ";

        if(q[f] == i-k) f++;
        if(i<n && a[i]<0) q[r++]=i;
    }
}
