#include <iostream>
using namespace std;

char st[100];
int top = -1;

int main(){
    string s = "saloni";
    for(char c : s) st[++top] = c;
    while(top != -1) cout << st[top--];
}
