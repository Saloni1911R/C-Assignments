#include <iostream>
#include <algorithm>
using namespace std;

/* Simple array-based version. Input: n intervals as pairs.
   This uses sort (allowed for student-level). */
int main(){
    int n; cin>>n;
    pair<int,int> arr[100];
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr, arr+n);
    pair<int,int> st[100]; int top=-1;
    for(int i=0;i<n;i++){
        if(top==-1 || arr[i].first > st[top].second) st[++top]=arr[i];
        else if(arr[i].second > st[top].second) st[top].second = arr[i].second;
    }
    for(int i=0;i<=top;i++) cout<<st[i].first<<" "<<st[i].second<<"\n";
}
