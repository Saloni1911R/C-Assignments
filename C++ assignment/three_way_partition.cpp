#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> a >> b;

    int low = 0, high = n-1, mid = 0;

    while(mid <= high) {
        if(arr[mid] < a)
            swap(arr[low++], arr[mid++]);
        else if(arr[mid] > b)
            swap(arr[mid], arr[high--]);
        else
            mid++;
    }

    for(int i=0;i<n;i++) cout << arr[i] << " ";
}
