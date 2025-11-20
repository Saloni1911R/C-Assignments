#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    int i=0, j=0;

    cout << "Union: ";
    while(i<n && j<m) {
        if(a[i] < b[j]) cout << a[i++] << " ";
        else if(b[j] < a[i]) cout << b[j++] << " ";
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }
    while(i<n) cout << a[i++] << " ";
    while(j<m) cout << b[j++] << " ";

    i=0; j=0;
    cout << "\nIntersection: ";
    while(i<n && j<m) {
        if(a[i] < b[j]) i++;
        else if(b[j] < a[i]) j++;
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }
}
