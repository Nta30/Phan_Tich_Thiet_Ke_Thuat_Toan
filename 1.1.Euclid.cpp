//Thuat toan Euclid tim UCLN cua 2 so
#include<bits/stdc++.h>
 using namespace std;
 
 //Ham tim UCLN
 int gcd(int a, int b){
 	if(a==b) return a;
 	if(a>b) return gcd(a-b,b);
 	else return gcd(b,b-a);
 }
 
 int main(){
	B1:
		int a,b;
	B2:
		cout<<"a = "; cin>>a;	
		cout<<"b = "; cin>>b;
	B3:
		if(a!=b){
			(a>b)?a-=b:b-=a;
			goto B3;
		}
	B4:
		cout<<"UCLN: "<<a;	 		
 }

