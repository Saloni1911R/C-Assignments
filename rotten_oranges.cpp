#include <iostream>
using namespace std;

struct Node{ int x,y,t; };
Node q[10000];
int front=0, rear=0;

void enq(Node n){ q[rear++]=n; }
Node deq(){ return q[front++]; }
bool empty(){ return front==rear; }

int main(){
    int n,m; cin>>n>>m;
    int g[50][50];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==2) enq({i,j,0});
        }

    int ans=0;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    while(!empty()){
        Node cur=deq();
        ans = max(ans, cur.t);

        for(int k=0;k<4;k++){
            int nx=cur.x+dx[k], ny=cur.y+dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==1){
                g[nx][ny]=2;
                enq({nx,ny,cur.t+1});
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]==1){
                cout<<-1; return 0;
            }

    cout<<ans;
}
