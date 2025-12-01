#include <iostream>
using namespace std;
int n, adj[50][50], vis[50];

int dfs(int u, int parent){
    vis[u]=1;
    for(int v=0; v<n; v++){
        if(adj[u][v]){
            if(!vis[v]){
                if(dfs(v,u)) return 1;
            } else if(v!=parent) return 1;
        }
    }
    return 0;
}

int main(){
    int m; cin>>n>>m;
    for(int i=0,u,v;i<m;i++) cin>>u>>v, adj[u][v]=adj[v][u]=1;
    for(int i=0;i<n;i++) if(!vis[i] && dfs(i,-1)){ cout<<"Cycle"; return 0;}
    cout<<"No Cycle";
    return 0;
}
