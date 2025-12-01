#include <iostream>
using namespace std;
struct Node{ int x,y,d; };
Node q[10000]; int f=0,r=0;
void enq(Node t){ q[r++]=t; }
Node deq(){ return q[f++]; }

int main(){
    int R,C; cin>>R>>C;
    int a[50][50], vis[50][50]={0};
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) cin>>a[i][j];
    int sx,sy,dx,dy; cin>>sx>>sy>>dx>>dy;
    enq({sx,sy,0}); vis[sx][sy]=1;
    int dxs[4]={1,-1,0,0}, dys[4]={0,0,1,-1};
    while(f<r){
        Node cur=deq();
        if(cur.x==dx && cur.y==dy){ cout<<cur.d; return 0; }
        for(int k=0;k<4;k++){
            int nx=cur.x+dxs[k], ny=cur.y+dys[k];
            if(nx>=0 && nx<R && ny>=0 && ny<C && !vis[nx][ny] && a[nx][ny]==0){
                vis[nx][ny]=1; enq({nx,ny,cur.d+1});
            }
        }
    }
    cout<<"No Path";
    return 0;
}
