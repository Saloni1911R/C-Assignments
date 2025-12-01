#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    int freq[26]={0};
    int q[200], f=0, r=0;

    for(char c: s){
        int idx=c-'a';
        freq[idx]++;
        q[r++] = idx;

        while(f!=r && freq[q[f]]>1) f++;

        if(f==r) cout<<"#";
        else cout<<char(q[f]+'a');
    }
}
