#include <iostream>
using namespace std;

int main(){
    int n,m; cin>>n>>m; // nodes, edges
    int adj[50][50]={0};
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[u][v]=1; adj[v][u]=1; // undirected
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<adj[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

