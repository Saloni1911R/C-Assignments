#include <iostream>
using namespace std;
int n, adj[50][50], vis[50], rec[50];

int dfs(int u){
    vis[u]=1; rec[u]=1;
    for(int v=0; v<n; v++){
        if(adj[u][v]){
            if(!vis[v] && dfs(v)) return 1;
            else if(rec[v]) return 1;
        }
    }
    rec[u]=0; return 0;
}

int main(){
    int m; cin>>n>>m;
    for(int i=0,u,v;i<m;i++) cin>>u>>v, adj[u][v]=1;
    for(int i=0;i<n;i++) if(!vis[i] && dfs(i)){ cout<<"Cycle"; return 0;}
    cout<<"No Cycle";
    return 0;
}
