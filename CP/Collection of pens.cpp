// User function Template for C++
class Solution {
  public:
    bool isPrime(int num){
        if(num<=1)return false;
        if(num<=3)return true;
        if(num%2==0 || num%3==0)return false;
        for(int i=5;i*i<=num;i++){
            if(num%i==0 || num%(i+2)==0)return false;
        }
        return true;
    }
    int minThirdPiles(int A, int B) {
        // code here
        int sum=A+B;
        int c=1;
        while(!isPrime(sum+c))c++;
        return c;
    }
};