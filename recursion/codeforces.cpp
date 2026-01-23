#include<iostream>
#include<string>
using namespace std;

void solver(int n, int &cnt){
   if(n==1){
    cnt++;
    return;
   }
   cnt++;
   if((n%2)==0){
    solver(n/2,cnt);
   }
   else{
    solver(3*n+1,cnt);
   }
}
int main(){
    
  int n,cnt=0;
  cin>>n;
  solver(n,cnt);
  cout<<cnt;
    return 0;
}