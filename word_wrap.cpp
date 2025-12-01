#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, maxWidth; 
    cin>>n; // number of words
    int w[100];
    for(int i=0;i<n;i++) cin>>w[i];
    cin>>maxWidth;

    int cost[100][100];
    for(int i=0;i<n;i++){
        int len = -1;
        for(int j=i;j<n;j++){
            len += 1 + w[j];
            if(len > maxWidth) cost[i][j] = INT_MAX;
            else {
                if(j==n-1) cost[i][j] = 0;
                else {
                    int extra = maxWidth - len;
                    cost[i][j] = extra*extra*extra; // cubic badness (commonly used)
                }
            }
        }
    }

    int dp[101];
    int path[101];
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        dp[i] = INT_MAX;
        for(int j=i;j<n;j++){
            if(cost[i][j]==INT_MAX) break;
            if(dp[j+1]!=INT_MAX && cost[i][j] + dp[j+1] < dp[i]){
                dp[i] = cost[i][j] + dp[j+1];
                path[i] = j+1;
            }
        }
    }

    cout<<"Minimum cost: "<<dp[0]<<"\n";
    cout<<"Breaks after words at indices: ";
    int i=0;
    while(i < n){
        cout<<path[i]-1<<" ";
        i = path[i];
    }
    return 0;
}
