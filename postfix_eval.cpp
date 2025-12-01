#include <iostream>
using namespace std;

int main(){
    string s = "231*+9-";
    int st[100], top = -1;

    for(char c : s){
        if(isdigit(c)){
            st[++top] = c - '0';
        }
        else {
            int b = st[top--];
            int a = st[top--];

            switch(c){
                case '+': st[++top] = a + b; break;
                case '-': st[++top] = a - b; break;
                case '*': st[++top] = a * b; break;
                case '/': st[++top] = a / b; break;
            }
        }
    }

    cout << "Result = " << st[top];
}
