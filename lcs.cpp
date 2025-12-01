#include <iostream>
#include <string>
using namespace std;

int dp[101][101];

int main(){
    string A,B; cin>>A>>B;
    int n=A.size(), m=B.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
