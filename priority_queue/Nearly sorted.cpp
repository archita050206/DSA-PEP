#include<queue>
using namespace std;
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int idx=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                int val=pq.top();
                pq.pop();
                arr[idx]=val;
                idx++;
            }
        }
        while(!pq.empty()){
            arr[idx]=pq.top();
            pq.pop();
            idx++;
        }
        
        
        
    }
};