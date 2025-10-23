#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        // vector<bool>isPrime(n+1,true);
        // isPrime[0]=isPrime[1]=false;
        // for(int i=2;i*i<=n;i++){
        //     if(isPrime[i]){
        //         for(int j=i*i;j<=n;j+=i){
        //             isPrime[j]=false;
        //         }
        //     }
        // }
        // int cnt=0;
        
        // return count(isPrime.begin(), isPrime.end()-1, true);

        //Sieve of Atkins
        if(n<=2)return 0;
        vector<bool>prime(n,false);
        prime[2]=prime[3]=true;

        for(int x=1;x*x<=n;x++){
            for(int y=1;y*y<=n;y++){
                int num=4*x*x+y*y;
                if(num<n && ( (num%12==1) ||(num%12==5)))prime[num]=!prime[num];
                num=3*x*x+y*y;
                if(num<n && num%12==7)prime[num]=!prime[num];
                num=3*x*x-y*y;
                if(x>y && num<n && num%12==11)prime[num]=!prime[num];
            }
        }
        for(int i=5;i*i<=n;i++){
            if(prime[i])for(int j=i*i;j<n;j+=i*i)prime[j]=false;
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i])cnt++;
        }
        return cnt;
    }
};