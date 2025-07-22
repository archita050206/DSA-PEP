#include<queue>
#include<cmath>
using namespace std;
class Solution {
public:

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq(gifts.begin(), gifts.end());
        for(int i=0;i<k;i++){
            long long x=pq.top();
            pq.pop();
            long long sq=sqrt(x);
            pq.push(sq);

        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};