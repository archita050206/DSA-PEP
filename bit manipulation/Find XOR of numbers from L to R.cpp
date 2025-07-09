

class Solution {
  public:
  
    int XORsolver(int a){
        if((a%4)==1)return 1;
        else if((a%4)==2)return a+1;
        else if((a%4)==3)return 0;
        else if((a%4)==0)return a;
        
    }
    int findXOR(int l, int r) {
        return (XORsolver(l-1)^XORsolver(r));
    }
};