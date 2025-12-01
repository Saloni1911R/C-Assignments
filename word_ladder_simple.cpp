#include <iostream>
#include <string>
using namespace std;

int diff1(const string &a, const string &b){
    int c=0;
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) c++;
    return c;
}

int main(){
    string start, target; int n;
    cin>>start>>target>>n;
    string dict[100];
    for(int i=0;i<n;i++) cin>>dict[i];

    int used[100]={0}, q[200], d[200], f=0,r=0;
    q[r++]=0; 
    if(start==target){ cout<<0; return 0; }

    // enqueue all words one step from start
    for(int i=0;i<n;i++){
        if(diff1(start, dict[i])==1){ q[r++]=i; d[r-1]=1; used[i]=1; if(dict[i]==target){ cout<<1; return 0; } }
    }

    // BFS
    int head=0;
    while(head<r){
        int idx = q[head++]; int dist = d[head-1];
        for(int i=0;i<n;i++){
            if(!used[i] && diff1(dict[idx], dict[i])==1){
                used[i]=1; q[r++]=i; d[r-1]=dist+1;
                if(dict[i]==target){ cout<<dist+1; return 0; }
            }
        }
    }
    cout<<"No Path";
    return 0;
}
