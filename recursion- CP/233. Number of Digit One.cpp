class Solution {
public:
    int solver(int n, long long pos){
        if(pos>n)return 0;
        int high=n/(pos*10);
        int curr=(n/pos)%10;
        int low=n%pos;
        int add=0;
        if(curr==0)add+=high*pos;
        else if(curr==1)add+=high*pos+low+1;
        else add+=(high+1)*pos;
        return add+solver(n,pos*10);
    }
    int countDigitOne(int n) {
        return solver(n,1LL);
    }
};