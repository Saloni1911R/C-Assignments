#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.size();
    int total0=0, total1=0;
    for(char c: s){ if(c=='0') total0++; else total1++; }

    int left0=0, left1=0;
    int ways=0;
    // split after index i (left: [0..i], right: [i+1..n-1])
    for(int i=0;i<n-1;i++){
        if(s[i]=='0') left0++; else left1++;
        int right0 = total0 - left0;
        int right1 = total1 - left1;
        if(left0==left1 && right0==right1) ways++;
    }
    cout<<ways;
    return 0;
}
