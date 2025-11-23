#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> x;

    int minLen = n+1, sum = 0, start = 0;

    for(int end = 0; end < n; end++) {
        sum += arr[end];
        while(sum > x) {
            minLen = min(minLen, end - start + 1);
            sum -= arr[start++];
        }
    }

    cout << minLen;
}
