#include <iostream>
using namespace std;
int adj[50][50], vis[50], n;
void dfs(int u){
    vis[u]=1; cout<<u<<" ";
    for(int v=0; v<n; v++) if(adj[u][v] && !vis[v]) dfs(v);
}
int main(){
    int m; cin>>n>>m;
    for(int i=0,u,v;i<m;i++){ cin>>u>>v; adj[u][v]=1; adj[v][u]=1; }
    int start; cin>>start;
    dfs(start);
    return 0;
}
