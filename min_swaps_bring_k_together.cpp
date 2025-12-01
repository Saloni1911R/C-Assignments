#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> k;

    int countGood = 0;
    for(int i=0;i<n;i++)
        if(arr[i] <= k) countGood++;

    int bad = 0;
    for(int i=0;i<countGood;i++)
        if(arr[i] > k) bad++;

    int ans = bad;
    for(int i=1; i+countGood-1 < n; i++) {
        if(arr[i-1] > k) bad--;
        if(arr[i+countGood-1] > k) bad++;
        ans = min(ans, bad);
    }

    cout << ans;
}
