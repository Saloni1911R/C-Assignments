#include <iostream>
using namespace std;

string solve(string s){
    int n=s.size(), best=1, start=0;
    for(int i=0;i<n;i++){
        int l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > best){ best=r-l+1; start=l; }
            l--; r++;
        }
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1 > best){ best=r-l+1; start=l; }
            l--; r++;
        }
    }
    return s.substr(start, best);
}

int main(){
    string s; cin>>s;
    cout<<solve(s);
}
