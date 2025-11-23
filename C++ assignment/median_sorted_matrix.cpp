#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int a[10][10];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    int minv = a[0][0], maxv = a[0][c-1];

    for(int i=1;i<r;i++) {
        if(a[i][0] < minv) minv = a[i][0];
        if(a[i][c-1] > maxv) maxv = a[i][c-1];
    }

    int desired = (r * c + 1) / 2;

    while(minv < maxv) {
        int mid = (minv + maxv) / 2;
        int count = 0;

        for(int i=0;i<r;i++) {
            int j = 0;
            while(j < c && a[i][j] <= mid) j++;
            count += j;
        }

        if(count < desired)
            minv = mid + 1;
        else
            maxv = mid;
    }

    cout << minv;
}
