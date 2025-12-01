#include <iostream>
using namespace std;

string fun(string s){
    string r="";
    for(int i=0;i<s.size();){
        int j=i, cnt=0;
        while(j<s.size() && s[j]==s[i]){ cnt++; j++; }
        r += char(cnt+'0');
        r += s[i];
        i=j;
    }
    return r;
}

int main(){
    int n; cin>>n;
    string s="1";
    for(int i=1;i<n;i++) s = fun(s);
    cout<<s;
}
