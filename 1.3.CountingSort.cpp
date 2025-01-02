//Counting sort: Sap xep xau ki tu
#include<bits/stdc++.h>
 using namespace std;
 int main(){
    string s;
    getline(cin,s);
    int count[123] = {0};
    for(char x : s){
        count[x]++;
    }
    for(int i=97;i<123;i++){
        while(count[i]--) cout<<char(i);
    }  
 }