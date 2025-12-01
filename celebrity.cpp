#include <iostream>
using namespace std;

int knows(int M[][4], int a, int b){
    return M[a][b];
}

int main(){
    int M[4][4] = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {0,1,1,0}
    };

    int a = 0, b = 3;

    while(a < b){
        if(knows(M, a, b)) a++;
        else b--;
    }

    int celeb = a;

    for(int i=0;i<4;i++){
        if(i!=celeb && (knows(M, celeb, i) || !knows(M, i, celeb))){
            cout << "No Celebrity";
            return 0;
        }
    }

    cout << "Celebrity is " << celeb;
}
