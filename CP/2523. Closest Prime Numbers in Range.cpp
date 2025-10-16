#include<vector>
#include<climits>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=sqrt(right);
        vector<bool>isPrime(right+1,true);
        isPrime[0]=isPrime[1]=false;
        for(long i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(long j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int >primes;
        for(int i=0;i<=n;i++){
            if(isPrime[i])primes.push_back(i);
        }

        for(int p: primes){
            for(int j=p*p;j<=right;j+=p){
                isPrime[j]=false;
            }
        }
        vector<int>prim;
        for(int i=left;i<=right;i++){
            if(isPrime[i])prim.push_back(i);
        }
        int diff=INT_MAX;
        vector<int>ans(2,-1);
        for(int i=prim.size()-1;i>0;i--){
            if(prim[i]-prim[i-1]<=diff){
                diff=(prim[i]-prim[i-1]);
                ans[0]=prim[i-1];
                ans[1]=prim[i];
            }
        }
        return ans;
        
    }
};