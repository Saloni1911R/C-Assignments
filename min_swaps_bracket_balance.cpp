#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin>>s;
    int open=0, swaps=0, imbalance=0;
    for(char c: s){
        if(c=='['){
            open++;
            if(imbalance>0){ swaps += imbalance; imbalance--; }
        } else {
            if(open>0) open--;
            else imbalance++;
        }
    }
    cout<<swaps;
    return 0;
}
