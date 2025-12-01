#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    int n=s.size();
    int i=n-2;
    while(i>=0 && s[i]>=s[i+1]) i--;
    if(i<0){ cout<<"No greater number\n"; return 0; }
    int j=n-1;
    while(s[j] <= s[i]) j--;
    swap(s[i], s[j]);
    // reverse s[i+1..end]
    int l=i+1, r=n-1;
    while(l<r) swap(s[l++], s[r--]);
    cout<<s<<"\n";
    return 0;
}
