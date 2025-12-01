#include <iostream>
using namespace std;

void subseq(string &s, int idx, string cur){
    if(idx == (int)s.size()){
        cout << (cur.empty()? "\"\"" : cur) << "\n";
        return;
    }
    // exclude
    subseq(s, idx+1, cur);
    // include
    subseq(s, idx+1, cur + s[idx]);
}

int main(){
    string s; cin>>s;
    subseq(s, 0, "");
    return 0;
}
