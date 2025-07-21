#include<queue>
#include<vector>

using namespace std;
class Solution {
  public:

  // can also use kSmallestElement wherein TC= O(nlogk) instead of O(nlogn)
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        
        priority_queue<long long , vector<long long>,greater<long long>>pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        vector<long long>v;
        for(int i=1;i<=N;i++){
            if(i>K1 && i<K2)v.push_back(pq.top());
            pq.pop();
        }
        long long sum=0;
        for(long long  i: v){
            sum+=i;
        }
        return sum;
    }
};