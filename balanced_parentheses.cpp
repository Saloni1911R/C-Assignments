#include <iostream>
using namespace std;

char stackArr[100];
int top = -1;

void push(char x){ stackArr[++top] = x; }
char pop(){ return stackArr[top--]; }
bool empty(){ return top == -1; }

bool isMatching(char a, char b){
    return (a=='(' && b==')') ||
           (a=='{' && b=='}') ||
           (a=='[' && b==']');
}

bool isBalanced(string s){
    for(char c : s){
        if(c=='(' || c=='{' || c=='[') push(c);
        else {
            if(empty()) return false;
            if(!isMatching(pop(), c)) return false;
        }
    }
    return empty();
}

int main(){
    string s = "{(())}";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced");
}
