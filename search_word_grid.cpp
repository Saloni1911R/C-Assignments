#include <iostream>
using namespace std;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

bool existsFrom(char mat[][50], int n, int m, int x, int y, string &pat){
    int L = pat.size();
    if(mat[x][y] != pat[0]) return false;
    for(int dir=0; dir<8; dir++){
        int k, nx=x+dx[dir], ny=y+dy[dir];
        for(k=1;k<L;k++){
            if(nx<0||nx>=n||ny<0||ny>=m) break;
            if(mat[nx][ny] != pat[k]) break;
            nx += dx[dir]; ny += dy[dir];
        }
        if(k==L) return true;
    }
    return false;
}

int main(){
    int n,m; cin>>n>>m;
    char mat[50][50];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mat[i][j];
    string pat; cin>>pat;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(existsFrom(mat,n,m,i,j,pat)){ cout<<"YES"; return 0; }
    cout<<"NO";
    return 0;
}
