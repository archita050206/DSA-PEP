class Solution {
public:
    int hammingWeight(int n) {

        int cnt=0;
        while(n!=0){
            if((n&1)==1)cnt++;
            n=n>>1;
        }
        return cnt;

        // Brian Kernighan's Algorithm
        // while(n>0){
        //     n=n&(n-1);
        //     cnt++;
        // }
        // return cnt;

        //  while(n!=0){
        //     int d=n%2;
        //     if(d==1)cnt++;
        //     n=n/2;
        // }
        // return cnt;

       
    }
};