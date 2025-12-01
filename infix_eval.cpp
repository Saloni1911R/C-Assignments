#include <iostream>
#include <cctype>
using namespace std;

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int apply(int a, int b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    return a/b;
}

int main(){
    string s = "3+5*2";
    int vals[100], vTop = -1;
    char ops[100]; int oTop = -1;

    for(char c : s){
        if(isdigit(c)){
            vals[++vTop] = c - '0';
        }
        else {
            while(oTop!=-1 && prec(ops[oTop]) >= prec(c)){
                int b = vals[vTop--];
                int a = vals[vTop--];
                char op = ops[oTop--];
                vals[++vTop] = apply(a,b,op);
            }
            ops[++oTop] = c;
        }
    }

    while(oTop!=-1){
        int b = vals[vTop--];
        int a = vals[vTop--];
        char op = ops[oTop--];
        vals[++vTop] = apply(a,b,op);
    }

    cout << "Answer = " << vals[vTop];
}
