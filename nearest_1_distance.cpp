#include <iostream>
using namespace std;

struct Node{ int x,y,d; };
Node q[10000]; int f=0,r=0;

void enq(Node n){ q[r++]=n; }
Node deq(){ return q[f++]; }
int main(){
    int n,m; cin>>n>>m;
    int a[100][100], dist[100][100];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==1){ dist[i][j]=0; enq({i,j,0}); }
            else dist[i][j]=-1;
        }

    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    while(f!=r){
        Node cur = deq();
        for(int k=0;k<4;k++){
            int nx=cur.x+dx[k], ny=cur.y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny]==-1){
                dist[nx][ny]=cur.d+1;
                enq({nx,ny,cur.d+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<dist[i][j]<<" ";
        cout<<"\n";
    }
}
