long long M=1e9+7;
class Solution {
public:
    long long modPow(long long a, long long b){
        long long res=1;
        while(b>0){
            if(b&1)res=(res*a)%M;
            a=(a*a)%M;
            b=b>>1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return (modPow(5,n/2)*modPow(4,n/2))%M;
        }
        else return (modPow(5,(n+1)/2) * modPow(4,n/2))%M;
        return 1;
    }
};