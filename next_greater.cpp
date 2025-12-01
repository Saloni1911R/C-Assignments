#include <iostream>
using namespace std;

int main(){
    int arr[6] = {4, 5, 2, 25, 7, 8};
    int st[100], top = -1;

    for(int i=0;i<6;i++){
        while(top!=-1 && arr[top] < arr[i]){
            cout << arr[top] << " -> " << arr[i] << endl;
            top--;
        }
        st[++top] = arr[i];
    }

    while(top!=-1){
        cout << st[top] << " -> -1" << endl;
        top--;
    }
}
