#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int end=pairs[0][1],cnt=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>end)
            {cnt++;
             end=pairs[i][1];
            }
        }
        return cnt;
    }
};