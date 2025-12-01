#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin>>s;
    char st[100]; int top=-1;
    for(char c: s){
        if(c==')'){
            bool op=false;
            while(top!=-1 && st[top] != '('){
                char x = st[top--];
                if(x=='+'||x=='-'||x=='*'||x=='/') op=true;
            }
            if(top!=-1 && st[top]=='(') top--; // pop '('
            if(!op){ cout<<"Redundant\n"; return 0; }
        } else st[++top]=c;
    }
    cout<<"Not Redundant\n";
}
