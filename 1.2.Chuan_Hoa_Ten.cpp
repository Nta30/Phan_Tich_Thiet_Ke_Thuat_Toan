//Chuan hoa ten
#include<bits/stdc++.h>
 using namespace std;

 int main(){
	char s[10000];
	scanf("%[^\n]", s);
	char *p = s;
	D:
		if(*p == ' '){
			p++;
			goto D;
		}
		if(*p == '\0') goto K;
		else cout<<char(toupper(*p++));
		goto T;
	T:
		if(*p == ' '){
			p++;
			cout<<" ";
			goto D;
		}
		if(*p == '\0') goto K;
		else cout<<char(tolower(*p++));
		goto T;
	K:
		return 0;	
 }