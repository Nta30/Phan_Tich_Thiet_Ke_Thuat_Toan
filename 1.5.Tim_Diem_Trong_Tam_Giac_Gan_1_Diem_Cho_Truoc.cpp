//Tìm di?m trong Tam giác g?n v?i 1 di?m cho tru?c nh?t
#include<bits/stdc++.h>
using namespace std;

typedef pair<double,double> Diem;
#define x first
#define y second

 //Hàm tính di?n tích tam giác bi?t t?a d? 3 di?m
 double S(Diem A, Diem B, Diem C){
    return (1.0/2.0) * fabs((B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y));
 }
 //Hàm tính bình phuong kho?ng cách
 double bpkc(Diem A, Diem B){
    return pow(A.x-B.x,2)+pow(A.y-B.y,2);
 }
 //Hàm tìm di?m thu?c AB có kho?ng cách g?n nh?t v?i M
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
    cin>>n;
    Diem A,B,C,M;
    for(int i=0;i<n;i++){
        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>M.x>>M.y;
        if(S(A,B,M) + S(B,C,M) + S(A,C,M) == S(A,B,C)){
            cout<<setprecision(3)<<fixed<<M.x<<" "<<M.y<<endl;
        }else{
            Diem D,E,F;
            D = dgn(A,B,M); // Ði?m thu?c AB có kho?ng cách g?n nh?t d?n M
            E = dgn(A,C,M); // Ði?m thu?c AC có kho?ng cách g?n nh?t d?n M
            F = dgn(B,C,M); // Ði?m thu?c BC có kho?ng cách g?n nh?t d?n M
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
