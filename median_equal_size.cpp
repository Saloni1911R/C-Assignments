#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int i = 0, j = 0, count = 0, prev = -1, curr = -1;

    while(count <= n) {
        prev = curr;

        if(i < n && (j >= n || a[i] < b[j]))
            curr = a[i++];
        else
            curr = b[j++];

        count++;
    }

    cout << (prev + curr) / 2.0;
}
