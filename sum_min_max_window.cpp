#include <iostream>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];

    int minQ[100], maxQ[100], f1=0,r1=0,f2=0,r2=0;
    long long sum=0;

    for(int i=0;i<n;i++){
        while(r1>f1 && a[minQ[r1-1]] >= a[i]) r1--;
        minQ[r1++] = i;

        while(r2>f2 && a[maxQ[r2-1]] <= a[i]) r2--;
        maxQ[r2++] = i;

        if(i >= k-1){
            if(minQ[f1] <= i-k) f1++;
            if(maxQ[f2] <= i-k) f2++;
            sum += a[minQ[f1]] + a[maxQ[f2]];
        }
    }
    cout<<sum;
}
