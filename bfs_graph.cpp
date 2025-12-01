#include <iostream>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    int adj[50][50]={0};
    for(int i=0,u,v;i<m;i++){ cin>>u>>v; adj[u][v]=1; adj[v][u]=1; }
    int start; cin>>start;
    int q[100], f=0,r=0, vis[50]={0};
    q[r++]=start; vis[start]=1;
    while(f<r){
        int u=q[f++]; cout<<u<<" ";
        for(int v=0; v<n; v++)
            if(adj[u][v] && !vis[v]){ vis[v]=1; q[r++]=v; }
    }
    return 0;
}
