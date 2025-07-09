class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int k=0;
        int num=n;
        while((n&1)!=0){
            n=n>>1;
            k++;
        }
        
        return num |(1<<k);
        
        //return n|(n+1); --> shortcut
    }
};