#include<queue>
using namespace std;
class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        if(arr.size()<=1)return 0;
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(),arr.end());
        int i=0,sum=0,ans=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            sum=x+y;
            ans+=sum;
            if(!pq.empty())
            pq.push(sum);
            
            
        }
        return ans;
    }
};