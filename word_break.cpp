#include <iostream>
using namespace std;

bool wordInDict(string &s, string dict[], int d){
    for(int i=0;i<d;i++) if(s==dict[i]) return true;
    return false;
}

int main(){
    string s; cin>>s;
    int d; cin>>d;
    string dict[100];
    for(int i=0;i<d;i++) cin>>dict[i];

    int n=s.size();
    bool dp[101] = {false};
    dp[0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]){
                string sub = s.substr(j, i-j);
                if(wordInDict(sub, dict, d)){ dp[i]=true; break; }
            }
        }
    }
    cout << (dp[n] ? "Yes" : "No");
    return 0;
}
