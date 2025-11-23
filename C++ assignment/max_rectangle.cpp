#include <iostream>
using namespace std;

int getMaxArea(int hist[], int n){
    int maxA = 0;

    for(int i=0;i<n;i++){
        int height = hist[i];
        int left = i, right = i;

        while(left > 0 && hist[left-1] >= height) left--;
        while(right < n-1 && hist[right+1] >= height) right++;

        int width = right - left + 1;
        maxA = max(maxA, width * height);
    }
    return maxA;
}

int main(){
    int r, c;
    cin >> r >> c;
    int a[10][10];
    int hist[10] = {0};

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    int maxRect = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] == 0) hist[j] = 0;
            else hist[j]++;
        }
        int area = getMaxArea(hist, c);
        if(area > maxRect) maxRect = area;
    }

    cout << maxRect;
}
