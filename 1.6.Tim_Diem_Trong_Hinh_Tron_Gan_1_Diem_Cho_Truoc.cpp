//Tìm điểm trong hình tròn và gần một điểm cho trước nhất
//Link bài: https://laptrinhonline.club/problem/tichpxdiemgan

#include<bits/stdc++.h>
using namespace std;

typedef pair<double,double> Diem;
#define x first
#define y second
 
 //Hàm tính bình phương khoảng cách giữa 2 điểm
 double bpkc(Diem A, Diem B){
    return pow(A.x-B.x,2) + pow(A.y-B.y,2);
 }

 int main(){
   Diem O,A,B,M;
   double r;
   cin>>O.x>>O.y>>r;
   cin>>A.x>>A.y;
   B=O;
   if(bpkc(O,A) < r*r){
      cout<<setprecision(3)<<fixed<<"("<<A.x<<", "<<A.y<<")";
      return 0;
   }
   while(fabs(A.x-B.x)>1e-4 || fabs(A.y-B.y)>1e-4){
      M.x = (A.x + B.x)/2;
      M.y = (A.y + B.y)/2;
      (bpkc(O,M)>r*r)?(A=M):(B=M);
   }
   cout<<setprecision(3)<<fixed<<"("<<A.x<<", "<<A.y<<")";
   return 0;
 }
