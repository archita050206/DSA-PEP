#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>>pq(nums.begin(),nums.end());
        // while(pq.size()>k){
        //     pq.pop();
        // }
        // return pq.top();
        // priority_queue<int>pq(nums.begin(),nums.end());
        // int n=pq.size();
        // while(pq.size()>(n-k+1)){
        //     pq.pop();
        // }
        // return pq.top();

        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i: nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        return pq.top();

    }
};