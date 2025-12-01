#include <iostream>
#include <algorithm>
using namespace std;

float median(int arr[], int n) {
    if(n % 2 == 0) return (arr[n/2] + arr[n/2 - 1]) / 2.0;
    return arr[n/2];
}

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    cin >> m;
    int b[m];
    for(int i=0;i<m;i++) cin >> b[i];

    int c[n+m];
    for(int i=0;i<n;i++) c[i] = a[i];
    for(int i=0;i<m;i++) c[n+i] = b[i];

    sort(c, c+n+m);

    cout << median(c, n+m);
}
