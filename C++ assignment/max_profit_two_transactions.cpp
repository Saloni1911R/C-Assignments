#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int price[n];
    for(int i=0;i<n;i++) cin >> price[i];

    int left[n], right[n];

    int minPrice = price[0];
    for(int i=1;i<n;i++) {
        left[i] = max(left[i-1], price[i] - minPrice);
        minPrice = min(minPrice, price[i]);
    }

    int maxPrice = price[n-1];
    for(int i=n-2;i>=0;i--) {
        right[i] = max(right[i+1], maxPrice - price[i]);
        maxPrice = max(maxPrice, price[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans, left[i] + right[i]);

    cout << ans;
}
