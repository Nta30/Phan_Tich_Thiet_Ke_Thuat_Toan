//Tìm điểm trong Tam giác gần với 1 điểm cho trước nhất
//Link bài: https://laptrinhonline.club/problem/tichpxtamgiac

#include<bits/stdc++.h>
using namespace std;

typedef pair<double,double> Diem;
#define x first
#define y second

 //Hàm tính diện tích tam giác biết tọa đọ 3 điểm
 double S(Diem A, Diem B, Diem C){
    return (1.0/2.0) * fabs((B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y));
 }
 //Hàm tính bình phương khoảng cách
 double bpkc(Diem A, Diem B){
    return pow(A.x-B.x,2)+pow(A.y-B.y,2);
 }
 //Hàm tìm điểm thuộc AB có khoảng cách gần nhất với M
 Diem dgn(Diem A, Diem B, Diem M){
    Diem C;
    while(fabs(A.x-B.x)>1e-4 || fabs(A.y-B.y)>1e-4){
        C.x = (A.x + B.x)/2;
        C.y = (A.y + B.y)/2;
        (bpkc(A,M) > bpkc(B,M))?(A=C):(B=C);
    }
    return A;
 } 

 int main(){
    int n;
    Diem A,B,C,M;
    for(int i=0;i<n;i++){
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>M.x>>M.y;
        if(S(A,B,M) + S(B,C,M) + S(A,C,M) == S(A,B,C)){
            cout<<setprecision(3)<<fixed<<M.x<<" "<<M.y<<endl;
        }else{
            Diem D,E,F;
            D = dgn(A,B,M); // Điểm thuộc AB có khoảng cách gần nhất đến M
            E = dgn(A,C,M); // Điểm thuộc AC có khoảng cách gần nhất đến M
            F = dgn(B,C,M); // Điểm thuộc BC có khoảng cách gần nhất đến M
            double min_kc = sqrt(bpkc(D,M));
            Diem nearest_point = D;
            if(min_kc > sqrt(bpkc(E,M))){
                min_kc = sqrt(bpkc(E,M));
                nearest_point = E;
            }
            if(min_kc > sqrt(bpkc(F,M))){
                min_kc = sqrt(bpkc(F,M));
                nearest_point = F;
            }
            cout<<setprecision(3)<<fixed<<nearest_point.x<<" "<<nearest_point.y<<endl;
        }
    }
 }