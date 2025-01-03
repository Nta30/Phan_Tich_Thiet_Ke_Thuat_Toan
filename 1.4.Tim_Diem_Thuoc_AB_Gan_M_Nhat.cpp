//Cho đoạn thẳng AB và điểm M. Tìm điểm thuộc AB gần M nhất
#include<bits/stdc++.h>
 using namespace std;
 
typedef pair<double,double> Diem;
#define x first
#define y second    

 //Hàm tính bình phương khoảng cách
 double bpkc(Diem A, Diem B){
    return pow(A.x-B.x,2) + pow(A.y-B.y,2); 
 }
 
 int main(){
    Diem A,B,M,C;
    double e = 1e-4;
    cout<<"Nhap cac diem A, B, M: ";
    cin>>A.x>>A.y>>B.x>>B.y>>M.x>>M.y;
    while(fabs(A.x - B.x)>e || fabs(A.y - B.y)>e){
        C.x = (A.x + B.x)/2;
        C.y = (A.y + B.y)/2;
        (bpkc(A,M) > bpkc(B,M))?(A = C):(B = C);
    }
    cout<<A.x<<" "<<A.y;
 }