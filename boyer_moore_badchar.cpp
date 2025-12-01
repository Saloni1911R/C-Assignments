#include <iostream>
#include <cstring>
using namespace std;

void badCharHeu(char *txt, char *pat){
    int m = strlen(pat), n = strlen(txt);
    int bad[256];
    for(int i=0;i<256;i++) bad[i] = -1;
    for(int i=0;i<m;i++) bad[(unsigned char)pat[i]] = i;

    int s=0;
    while(s <= (n-m)){
        int j = m-1;
        while(j>=0 && pat[j]==txt[s+j]) j--;
        if(j<0){
            cout<<"Pattern occurs at index "<<s<<"\n";
            s += (s+m < n) ? m - bad[(unsigned char)txt[s+m]] : 1;
        } else {
            int shift = j - bad[(unsigned char)txt[s+j]];
            s += (shift>0)? shift : 1;
        }
    }
}

int main(){
    char txt[500], pat[100];
    cin>>txt>>pat;
    badCharHeu(txt, pat);
    return 0;
}
