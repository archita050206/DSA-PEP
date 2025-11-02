// User function template for C++

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
    int isTwistedPrime(int N) {
        // code here
        int rev=0;
        int num=N;
        while(N!=0){
            int d=N%10;
            N=N/10;
            rev=rev*10+d;
        }
        return (isPrime(num) && isPrime(rev));
    }
};