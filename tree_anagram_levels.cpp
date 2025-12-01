#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int A[100], B[100];
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];

    int level=1, idx=0;

    while(idx < n){
        int freqA[100]={0}, freqB[100]={0};
        for(int i=idx;i<idx+level && i<n;i++){
            if(A[i]!=-1) freqA[A[i]]++;
            if(B[i]!=-1) freqB[B[i]]++;
        }
        for(int i=0;i<100;i++)
            if(freqA[i] != freqB[i]){
                cout<<"NO"; return 0;
            }
        idx+=level;
        level*=2;
    }
    cout<<"YES";
}
