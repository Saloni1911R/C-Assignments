#include <iostream>
using namespace std;

/* Given input sequence 1..n pushed in order, check if target can be produced */
int main(){
    int n; cin>>n;
    int target[100];
    for(int i=0;i<n;i++) cin>>target[i];

    int st[100], top=-1;
    int cur=1, i=0;
    while(cur<=n){
        st[++top]=cur++;
        while(top!=-1 && st[top]==target[i]){ top--; i++; if(i==n) break; }
    }
    if(i==n) cout<<"Yes\n"; else cout<<"No\n";
}
