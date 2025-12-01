#include <iostream>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    int adj[50][50]={0}, cloneA[50][50]={0};
    for(int i=0,u,v;i<m;i++){ cin>>u>>v; adj[u][v]=1; } // directed
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cloneA[i][j]=adj[i][j];
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<cloneA[i][j]<<" "; cout<<"\n"; }
    return 0;
}

