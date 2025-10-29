// User function Template for C++
class Solution {
  public:
    bool isPrime(int n){
        if(n<=1)return false;
        if(n<=3)return true;
        if(n%2==0 || n%3==0)return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0)return false;
        }
        return true;
    }
    int nthTerm(int n) {
        // code here
        int cnt=0; int i=2;
        while(cnt!=n){
            if(isPrime(i))cnt++;
            i++;
        }
        
        return (i-1)*n+n;
    }
};