#include<unordered_set>
using namespace std;
class Solution {
  public:
    int sumOfSquares(int n){
        int s=0;
        while(n!=0){
            int d=n%10;
            s+=d*d;
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n, unordered_set<int>&visited){
        if(n==1)return true;
        if(visited.count(n))return false;//loop exists
        visited.insert(n);
        int next=sumOfSquares(n);
        return isHappy(next,visited);
    }
    int nextHappy(int N) {
        // code here
       
        int x=N+1;
        while(true){
             unordered_set<int>visited;
            if(isHappy(x,visited))return x;
            x++;
        }
        return -1;
        
    }
};