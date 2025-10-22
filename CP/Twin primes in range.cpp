#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0||n%3==0)return false;
    for(int i=5;i*i<=n;i+=6){
        if((n%i==0)||(n%(i+2)==0))return false;
    }
    return true;

}

bool twinPrime(int n1, int n2){
    return isPrime(n1)&&isPrime(n2)&abs(n1-n2)==2;
}

int main(){
    for(int i=1;i<=1000;i++){
        if(twinPrime(i,i+2))cout<<'('<<i<<','<<i+2<<')';
    }
}