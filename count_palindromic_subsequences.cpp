#include <iostream>
using namespace std;

// dp[i][j] = number of palindromic subseq in s[i..j]
long long dp[101][101];

int main(){
    string s; cin>>s;
    int n = s.size();
    for(int i=0;i<n;i++) dp[i][i]=1;

    for(int len=2; len<=n; len++){
        for(int i=0;i+len-1<n;i++){
            int j = i+len-1;
            if(s[i]==s[j])
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            else
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
