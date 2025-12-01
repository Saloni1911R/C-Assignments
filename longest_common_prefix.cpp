#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    string arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==0){ cout<<""; return 0; }
    string prefix = arr[0];
    for(int i=1;i<n;i++){
        while(prefix.size() > 0 && arr[i].substr(0, prefix.size()) != prefix)
            prefix = prefix.substr(0, prefix.size()-1);
        if(prefix.empty()) break;
    }
    cout<<prefix;
    return 0;
}
