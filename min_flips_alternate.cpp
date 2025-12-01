#include <iostream>
using namespace std;

int main(){
    string s; cin>>s;
    int n=s.size();
    int flips0=0, flips1=0; // flips to make start with '0' or '1'
    for(int i=0;i<n;i++){
        char should0 = (i%2==0)? '0':'1';
        char should1 = (i%2==0)? '1':'0';
        if(s[i] != should0) flips0++;
        if(s[i] != should1) flips1++;
    }
    cout<<min(flips0, flips1);
    return 0;
}

