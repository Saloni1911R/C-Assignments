#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int petrol[100], dist[100];

    for(int i=0;i<n;i++) cin>>petrol[i]>>dist[i];

    int start=0, balance=0, deficit=0;
    for(int i=0;i<n;i++){
        balance += petrol[i] - dist[i];
        if(balance < 0){
            start = i+1;
            deficit += balance;
            balance = 0;
        }
    }
    if(balance + deficit >= 0) cout<<start;
    else cout<<-1;
}
