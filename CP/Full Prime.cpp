// User function template for C++

class Solution {
  public:
  bool isPrime(int n){
      if(n<=1)return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0)return false;
      }
      return true;
  }
    int fullPrime(int N) {
        // code here
        if(!isPrime(N))return 0;
        int temp=N;
        while(N!=0){
            int dig=N%10;
            if(dig!=2&&dig!=3&&dig!=5&& dig!=7)return 0;
            N=N/10;
        }
        return 1;
    }
};
