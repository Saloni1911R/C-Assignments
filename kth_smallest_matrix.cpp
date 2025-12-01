#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[10][10], temp[100];
    int t = 0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            temp[t++] = a[i][j];
        }

    for(int i=0;i<t-1;i++)
        for(int j=i+1;j<t;j++)
            if(temp[j] < temp[i]) {
                int x = temp[i];
                temp[i] = temp[j];
                temp[j] = x;
            }

    cout << temp[k-1];
}
