#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[10][10];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    int maxValue = -100000;

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i < n-1 && j < n-1)
                a[i][j] = max(a[i][j], max(a[i][j+1], max(a[i+1][j], a[i+1][j+1])));
        }
    }

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1;j++)
            maxValue = max(maxValue, a[i+1][j+1] - a[i][j]);

    cout << maxValue;
}
