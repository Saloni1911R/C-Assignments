#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int a[10][10], temp[100];
    int k = 0;

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp[k++] = a[i][j];

    for(int i=0;i<k-1;i++)
        for(int j=i+1;j<k;j++)
            if(temp[j] < temp[i]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    for(int i=0;i<k;i++)
        cout << temp[i] << " ";
}
