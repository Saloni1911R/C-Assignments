#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int a[10][10];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    int maxRow = -1, j = c - 1;

    for(int i=0;i<r;i++) {
        while(j >= 0 && a[i][j] == 1) {
            j--;
            maxRow = i;
        }
    }

    cout << maxRow;
}
