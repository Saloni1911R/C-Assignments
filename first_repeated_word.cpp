#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; getline(cin, s);
    string words[100]; int wc=0;
    string cur="";
    for(char c: s){
        if(c==' '){ if(cur!=""){ words[wc++]=cur; cur=""; } }
        else cur += c;
    }
    if(cur!="") words[wc++]=cur;

    for(int i=0;i<wc;i++){
        for(int j=i+1;j<wc;j++){
            if(words[i]==words[j]){ cout<<words[i]; return 0; }
        }
    }
    cout<<"No Repetition";
    return 0;
}
