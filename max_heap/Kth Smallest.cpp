#include<queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // TC= O(nlogk)
        // SC= O(k)
        priority_queue<int>pq;
        for(int i: arr){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};