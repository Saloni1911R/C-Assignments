#include <iostream>
#include <string>
using namespace std;

/* student-level: use stack of indices implemented with array */
int main(){
    string s; cin>>s;
    int st[100], top=-1;
    st[++top]=-1; // base
    int maxLen=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='(') st[++top]=i;
        else{
            if(top!=-1) top--; // pop matching '(' index or base
            if(top==-1) st[++top]=i;
            else maxLen = max(maxLen, i - st[top]);
        }
    }
    cout<<maxLen;
}
