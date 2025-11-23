#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of packets: ";
    cin >> n;
    int arr[n];

    cout << "Enter packets: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "Enter number of students: ";
    cin >> m;

    sort(arr, arr+n);

    int ans = arr[m-1] - arr[0];
    for(int i=1; i+m-1 < n; i++) {
        ans = min(ans, arr[i+m-1] - arr[i]);
    }

    cout << "Minimum difference = " << ans;
}
