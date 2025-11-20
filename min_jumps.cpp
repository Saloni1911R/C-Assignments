#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    if(n == 1) { cout << 0; return 0; }
    if(arr[0] == 0) { cout << -1; return 0; }

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for(int i=1;i<n;i++) {
        if(i == n-1) {
            cout << jumps;
            return 0;
        }

        maxReach = max(maxReach, i + arr[i]);
        steps--;

        if(steps == 0) {
            jumps++;
            if(i >= maxReach) {
                cout << -1;
                return 0;
            }
            steps = maxReach - i;
        }
    }
}
