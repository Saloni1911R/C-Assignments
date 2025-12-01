#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    int i = 0, j = n-1, ops = 0;

    while(i < j) {
        if(arr[i] == arr[j]) {
            i++; j--;
        }
        else if(arr[i] < arr[j]) {
            arr[i+1] += arr[i];
            i++;
            ops++;
        }
        else {
            arr[j-1] += arr[j];
            j--;
            ops++;
        }
    }

    cout << ops;
}
