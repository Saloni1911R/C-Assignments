#include <iostream>
#include <algorithm>
using namespace std;

int lis_length(int arr[], int n){
    int dp[100], len=0;
    for(int i=0;i<n;i++){
        int pos = 0;
        while(pos<len && dp[pos] < arr[i]) pos++;
        dp[pos]=arr[i];
        if(pos==len) len++;
    }
    return len;
}

int main(){
    int n; cin>>n;
    pair<int,int> p[100];
    for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    sort(p, p+n);
    int b[100];
    for(int i=0;i<n;i++) b[i]=p[i].second;
    int lis = lis_length(b,n);
    cout << (n - lis); // minimum removals to avoid crossings
    return 0;
}
