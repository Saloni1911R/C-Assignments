#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> target;

    sort(arr, arr+n);

    for(int i=0;i<n-2;i++) {
        int l = i+1, r = n-1;
        while(l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == target) {
                cout << "Triplet: " << arr[i] << ", " << arr[l] << ", " << arr[r];
                return 0;
            }
            else if(sum < target) l++;
            else r--;
        }
    }

    cout << "No triplet found";
}
 