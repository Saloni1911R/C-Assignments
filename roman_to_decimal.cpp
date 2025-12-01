#include <iostream>
using namespace std;

int val(char c){
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    if(c=='M') return 1000;
    return 0;
}

int romanToInt(string s){
    int n=s.size(), ans=0;
    for(int i=0;i<n;i++){
        int v = val(s[i]);
        if(i+1<n && val(s[i+1])>v) ans -= v;
        else ans += v;
    }
    return ans;
}

int main(){
    string s; cin>>s;
    cout<<romanToInt(s);
    return 0;
}

