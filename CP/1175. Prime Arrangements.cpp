#include<vector>
using namespace std;
class Solution {   
    const int M = 1e9 + 7   ;
public:
long long fact(int n){
    vector<long long>v(n+1,1);
    
    for(int i=1;i<=n;i++){
        v[i]=(v[i-1]*i)%M;
    }
    return v[n];
}
    bool isPrime(int n){
        if(n<=1)return false;
        if(n<=3)return true;
        if(n%2==0 || n%3==0)return false;
        for(int i=5;i*i<=n;i++){
            if(n%i==0 || n%(i+2)==0)return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int np=0,p=0;
        for(int i=1;i<=n;i++){
            if(isPrime(i))p++;
            else np++;
        }
        return (fact(p)*(fact(np)))% M;
    }
};