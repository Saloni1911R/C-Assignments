#include <iostream>
using namespace std;

int main(){
    string s; int k; cin>>s>>k;
    int freq[26]={0};
    for(char c: s) freq[c-'a']++;

    // Repeat k times: remove 1 from the largest freq
    for(int x=0;x<k;x++){
        int idx=0;
        for(int i=1;i<26;i++)
            if(freq[i] > freq[idx]) idx=i;
        if(freq[idx]>0) freq[idx]--;
    }

    int ans=0;
    for(int i=0;i<26;i++) ans+=freq[i]*freq[i];
    cout<<ans;
}
