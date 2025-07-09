class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //Left shift
        // if((n &(1<<k))==(1<<k))return true;
        // return false;
        //return (n &(1<<k));

        //Right shift
        return ((n>>k)&1);
    }
};