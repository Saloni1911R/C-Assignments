#include <iostream>
using namespace std;
struct Node{ int x,y,d; };
Node q[10000]; int f=0,r=0;
void enq(Node t){ q[r++]=t; } Node deq(){ return q[f++]; }

int main(){
    int N; cin>>N;
    int sx,sy,dx,dy; cin>>sx>>sy>>dx>>dy;
    int vis[50][50]={0};
    int mx[8]={2,2,-2,-2,1,1,-1,-1}, my[8]={1,-1,1,-1,2,-2,2,-2};
    enq({sx,sy,0}); vis[sx][sy]=1;
    while(f<r){
        Node cur=deq();
        if(cur.x==dx && cur.y==dy){ cout<<cur.d; return 0; }
        for(int i=0;i<8;i++){
            int nx=cur.x+mx[i], ny=cur.y+my[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && !vis[nx][ny]){
                vis[nx][ny]=1; enq({nx,ny,cur.d+1});
            }
        }
    }
    cout<<-1;
    return 0;
}
