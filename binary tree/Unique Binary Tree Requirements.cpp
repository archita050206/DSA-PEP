// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        if(a==1){
            if(b==2)return true;
            else return false;
        }
        else if(a==2){
            if(b==1 || b==3)return true;
            else return false;
        }
        else if(a==3){
            if(b==2)return true;
            else return false;
        }
        else return false;
    }
};