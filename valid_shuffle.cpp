#include <iostream>
using namespace std;

int main(){
    string s1,s2,s3; 
    cin>>s1>>s2>>s3;
    if(s1.size()+s2.size() != s3.size()){
        cout<<"NO"; return 0;
    }
    int i=0,j=0,k=0;
    while(k < s3.size()){
        if(i<s1.size() && s3[k]==s1[i]) i++;
        else if(j<s2.size() && s3[k]==s2[j]) j++;
        else { cout<<"NO"; return 0; }
        k++;
    }
    cout<<"YES";
}
