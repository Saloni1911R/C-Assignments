#include <iostream>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    int a[10][10];
    int freq[1000] = {0};

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            cin >> a[i][j];
            if(i == 0) freq[a[i][j]] = 1;
        }

    for(int i=1;i<r;i++){
        int rowCount[1000] = {0};
        for(int j=0;j<c;j++)
            rowCount[a[i][j]] = 1;

        for(int x=0;x<1000;x++)
            if(freq[x] == i)
                if(rowCount[x] == 1)
                    freq[x]++;
    }

    for(int x=0;x<1000;x++)
        if(freq[x] == r)
            cout << x << " ";
}
