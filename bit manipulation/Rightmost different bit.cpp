class Solution {
  public:
    int posOfRightMostDiffBit(int m, int n) {
        
        int num=m^n;
        int k=0;
        while(num>0){
            if((num&1)==1)return k+1;
            num=num>>1;
            k++;
        }
        return -1;
    }
};