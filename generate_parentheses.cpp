#include <iostream>
using namespace std;

void gen(int open, int close, string cur){
    if(open==0 && close==0){ cout<<cur<<"\n"; return; }
    if(open>0) gen(open-1, close, cur+'(');
    if(close>open) gen(open, close-1, cur+')');
}

int main(){
    int n; cin>>n; // pairs
    gen(n, n, "");
    return 0;
}
