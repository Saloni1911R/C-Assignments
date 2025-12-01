#include <iostream>
using namespace std;
int R,C, grid[50][50];

void fillDFS(int x,int y,int oldc,int newc){
    if(x<0||x>=R||y<0||y>=C) return;
    if(grid[x][y]!=oldc) return;
    grid[x][y]=newc;
    fillDFS(x+1,y,oldc,newc); fillDFS(x-1,y,oldc,newc);
    fillDFS(x,y+1,oldc,newc); fillDFS(x,y-1,oldc,newc);
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) cin>>grid[i][j];
    int sx,sy,newc; cin>>sx>>sy>>newc;
    int oldc = grid[sx][sy];
    if(oldc!=newc) fillDFS(sx,sy,oldc,newc);
    for(int i=0;i<R;i++){ for(int j=0;j<C;j++) cout<<grid[i][j]<<" "; cout<<"\n"; }
    return 0;
}
