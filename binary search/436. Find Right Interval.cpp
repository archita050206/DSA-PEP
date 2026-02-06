#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findVal(int target,vector<pair<int,int>>&index){
        int l=0,h=index.size()-1,ans=-1;
        while(l<=h){
            int mid= l+(h-l)/2;
            if(index[mid].first>=target){
                ans=index[mid].second;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>>index;
        vector<int>ans;
        for(int i=0;i<intervals.size();i++){
            index.push_back({intervals[i][0],i});
        }
        sort(index.begin(), index.end());
        for(int i=0;i<intervals.size();i++){
            int idx= findVal(intervals[i][1], index);
            ans.push_back(idx);
        }
        return ans;
    }
};